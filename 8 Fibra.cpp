#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

// Estructura para representar una ciudad con coordenadas (x, y)
struct Ciudad {
    int x, y;
};

// Función para calcular la distancia euclídea entre dos ciudades
double calcularDistancia(const Ciudad& a, const Ciudad& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Función para encontrar el Árbol de Expansión Mínima usando el algoritmo de Prim
double primMST(const vector<Ciudad>& ciudades) {
    int n = ciudades.size();
    vector<double> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    key[0] = 0;
    double costoTotal = 0;

    for (int count = 0; count < n; ++count) {
        // Encuentra el vértice con el valor mínimo de key que no está en el MST
        double minKey = INT_MAX;
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Añadir el vértice encontrado al MST
        inMST[u] = true;
        costoTotal += minKey;

        // Actualizar los valores de key de los vértices adyacentes al vértice u
        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                double distancia = calcularDistancia(ciudades[u], ciudades[v]);
                if (distancia < key[v]) {
                    key[v] = distancia;
                }
            }
        }
    }

    return costoTotal;
}

int main() {
    vector<Ciudad> ciudades = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    double costoTotal = primMST(ciudades);
    cout << "El costo total de la red de interconexión es: " << costoTotal << endl;

    return 0;
}
