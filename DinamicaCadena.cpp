#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAXN = 105;
int dp[MAXN][MAXN];
int peso[MAXN];
int suma_peso[MAXN];

int main() {
    int n;
    cout << "Ingrese el número de eslabones: ";
    cin >> n;
    
    cout << "Ingrese los pesos de los eslabones: ";
    for (int i = 1; i <= n; ++i) {
        cin >> peso[i];
        suma_peso[i] = suma_peso[i-1] + peso[i];
    }

    // Inicializar la matriz dp
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0; // No hay coste cuando solo hay un eslabón
    }

    // Llenar la matriz dp utilizando la estrategia de programación dinámica
    for (int len = 2; len <= n; ++len) { // Longitud de la subcadena
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + suma_peso[j] - suma_peso[i-1]);
            }
        }
    }

    // El resultado final estará en dp[1][n]
    cout << "El coste mínimo total para formar la cadena es: " << dp[1][n] << endl;

    return 0;
}
