#include <iostream>
#include <vector>
using namespace std;

double calcularProbabilidadGanarPlayoff(double P, int n) {
    // Matriz dp para almacenar las probabilidades
    vector<vector<double>> dp(2 * n, vector<double>(2 * n, 0.0));

    // Caso base
    dp[0][0] = 1.0; // Probabilidad inicial (0 partidos jugados, 0 victorias)

    // Llenar la matriz dp usando la recurrencia
    for (int i = 1; i < 2 * n; ++i) {
        dp[i][0] = dp[i-1][0] * (1 - P); // No ganar el partido i
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i-1][j-1] * P + dp[i-1][j] * (1 - P); // Ganar el partido i
        }
    }

    // Sumar las probabilidades de tener al menos n victorias
    double probabilidadGanar = 0.0;
    for (int j = n; j < 2 * n; ++j) {
        probabilidadGanar += dp[2 * n - 2][j];
    }

    return probabilidadGanar;
}

int main() {
    double P = 0.5; // Probabilidad fija de ganar un partido
    int n = 4; // Número de victorias necesarias para ganar el playoff

    double probabilidad = calcularProbabilidadGanarPlayoff(P, n);
    cout << "Probabilidad de que Informáticos CB gane el playoff: " << probabilidad << endl;

    return 0;
}
