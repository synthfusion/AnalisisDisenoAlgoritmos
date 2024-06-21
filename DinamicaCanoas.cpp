#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9; // Utilizamos un valor grande para representar infinito

void alquilerCanoas(int n, vector<vector<int>>& costos) {
    // Inicialización de la matriz dp con los costos directos
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

    // Copiamos los costos directos a la matriz dp
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = costos[i][j];
        }
    }

    // Aplicamos el algoritmo de Floyd-Warshall modificado
    for (int k = 1; k <= n; ++k) { // aldea intermedia
        for (int i = 1; i <= n; ++i) { // aldea de partida
            for (int j = 1; j <= n; ++j) { // aldea de llegada
                if (dp[i][k] != INF && dp[k][j] != INF && dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    // Imprimimos la matriz dp resultante que contiene los costos mínimos
    cout << "Matriz de costos mínimos:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] == INF) {
                cout << "∞ ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    vector<vector<int>> costos = {
        {0, 17, 8, 16, 20},
        {INF, 0, 12, 6, 15},
        {INF, INF, 0, 12, 16},
        {INF, INF, INF, 0, 15},
        {INF, INF, INF, INF, 0}
    };

    alquilerCanoas(n, costos);

    return 0;
}
