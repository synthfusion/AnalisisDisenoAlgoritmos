#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // Valor infinito para representar infinito

// Estructura para representar los arcos
struct Edge {
    int u, v, cost;
    Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}
};

int main() {
    int n, m, k;
    cout << "Ingrese el número de vértices, arcos y etapas del grafo: ";
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(k);
    vector<vector<int>> dp(k, vector<int>(n, INF));

    // Lectura de los arcos
    cout << "Ingrese los arcos (u v costo):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, costo;
        cin >> u >> v >> costo;
        graph[u-1].emplace_back(u-1, v-1, costo); // Ajuste a base 0
    }

    // Vértice de origen y destino
    int s = 0; // Origen en la etapa 1
    int t = n - 1; // Destino en la etapa k

    // Caso base: no se usan arcos
    dp[0][s] = 0;

    // Calculamos los caminos mínimos para cada etapa i
    for (int i = 1; i < k; ++i) {
        for (int v = 0; v < n; ++v) {
            for (auto& edge : graph[i-1]) {
                int u = edge.u;
                int new_cost = dp[i-1][u] + edge.cost;
                dp[i][v] = min(dp[i][v], new_cost);
            }
        }
    }

    // El resultado final es el costo mínimo para llegar a t en la última etapa
    int min_cost = dp[k-1][t];
    cout << "Costo mínimo desde s hasta t: " << min_cost << endl;

    return 0;
}
