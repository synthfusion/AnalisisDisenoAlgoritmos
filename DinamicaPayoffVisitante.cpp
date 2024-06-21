#include <iostream>
#include <vector>
using namespace std;

double calcularInfluenciaVentajaCampo(double PL, double PV, int n) {
    // Matriz dp para almacenar las probabilidades
    vector<vector<double>> dp(2 * n, vector<double>(2 * n, 0.0));

    // Caso base
    dp[0][0] = 1.0; // Probabilidad inicial (0 partidos jugados, 0 victorias)

    // Llenar la matriz dp usando la recurrencia
    for (int i = 1; i < 2 * n; ++i) {
        dp[i][0] = dp[i-1][0] * PL; // Jugar como local
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i-1][j-1] * PL + dp[i-1][j] * PV; // Jugar como visitante
        }
    }

    // Calcular la influencia de jugar como local vs visitante
    double influencia = 0.0;
    for (int j = n; j < 2 * n; ++j) {
        influencia += dp[2 * n - 2][j];
    }

    return influencia;
}

int main() {
    double PL = 0.6; // Probabilidad de ganar como local
    double PV = 0.4; // Probabilidad de ganar como visitante
    int n = 4; // Número de victorias necesarias para ganar el playoff

    double influencia = calcularInfluenciaVentajaCampo(PL, PV, n);
    cout << "Influencia de jugar como local en el resultado final: " << influencia << endl;

    return 0;
}
