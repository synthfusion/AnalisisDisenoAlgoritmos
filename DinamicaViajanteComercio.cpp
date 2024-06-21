#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

// Función para calcular la distancia entre dos puntos (nodos)
int distancia(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second); // Distancia Manhattan
}

// Función que resuelve el TSP usando programación dinámica
int tsp(vector<pair<int, int>>& puntos) {
    int n = puntos.size();
    if (n == 0) return 0;
    
    // Inicialización de la matriz dp
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    
    // Caso base: Cuando solo se visita el nodo inicial
    dp[1][0] = 0; // Iniciamos en el nodo 0 (el primer nodo)
    
    // Llenar la matriz dp usando la programación dinámica
    for (int mask = 1; mask < (1 << n); ++mask) { // Recorremos todos los subconjuntos de nodos
        for (int i = 0; i < n; ++i) { // Recorremos todos los nodos
            if (mask & (1 << i)) { // Si el nodo i está en el subconjunto representado por mask
                for (int j = 0; j < n; ++j) { // Consideramos todos los nodos j en el subconjunto mask
                    if (i != j && (mask & (1 << j))) { // Solo consideramos si j != i y j está en mask
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + distancia(puntos[j], puntos[i]));
                    }
                }
            }
        }
    }
    
    // Encontrar la solución óptima del TSP
    int min_cost = INF;
    for (int i = 1; i < n; ++i) {
        min_cost = min(min_cost, dp[(1 << n) - 1][i] + distancia(puntos[i], puntos[0]));
    }
    
    return min_cost;
}

int main() {
    // Ejemplo de uso
    vector<pair<int, int>> puntos = {{0, 0}, {1, 2}, {3, 3}, {2, 1}};
    
    int min_cost = tsp(puntos);
    
    cout << "Costo mínimo del TSP: " << min_cost << endl;
    
    return 0;
}
