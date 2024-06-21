#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n; // Total de unidades de recurso
    int r; // Número de proyectos
    cout << "Ingrese el número de unidades de recurso (n): ";
    cin >> n;
    cout << "Ingrese el número de proyectos (r): ";
    cin >> r;

    // Vector para almacenar los beneficios de cada proyecto
    vector<vector<int>> beneficios(r + 1, vector<int>(n + 1, 0));

    // Lectura de los beneficios por asignación de recursos
    for (int i = 1; i <= r; ++i) {
        int ni; // Máximo recursos que se pueden asignar al proyecto i
        cout << "Ingrese el máximo de unidades para el proyecto " << i << ": ";
        cin >> ni;

        for (int j = 1; j <= ni; ++j) {
            cout << "Ingrese el beneficio para asignar " << j << " unidades al proyecto " << i << ": ";
            cin >> beneficios[i][j];
        }
    }

    // Programación dinámica para calcular el beneficio máximo
    vector<vector<int>> dp(r + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= r; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = 0;
            for (int k = 0; k <= min(j, (int)beneficios[i].size() - 1); ++k) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-k] + beneficios[i][k]);
            }
        }
    }

    // El resultado final estará en dp[r][n]
    int maxBeneficio = dp[r][n];
    cout << "El beneficio máximo obtenido es: " << maxBeneficio << endl;

    return 0;
}
