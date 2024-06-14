#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para calcular la distancia euclídea entre dos puntos
double calcularDistancia(const vector<double>& a, const vector<double>& b) {
    double suma = 0;
    for (size_t i = 0; i < a.size(); i++) {
        suma += pow(a[i] - b[i], 2);
    }
    return sqrt(suma);
}

// Función para encontrar los centros de clúster utilizando el algoritmo Farthest-First Traversal
vector<int> encontrarCentros(const vector<vector<double>>& clientes, int K) {
    int n = clientes.size();
    vector<int> centros;
    centros.push_back(0); // Selecciona el primer centro arbitrariamente (por ejemplo, el primer cliente)

    for (int k = 1; k < K; k++) {
        int farthestCliente = -1;
        double maxDistancia = -1;

        for (int i = 0; i < n; i++) {
            double minDistancia = numeric_limits<double>::max();
            for (int centro : centros) {
                double distancia = calcularDistancia(clientes[i], clientes[centro]);
                minDistancia = min(minDistancia, distancia);
            }
            if (minDistancia > maxDistancia) {
                maxDistancia = minDistancia;
                farthestCliente = i;
            }
        }
        centros.push_back(farthestCliente);
    }

    return centros;
}

// Función para asignar cada cliente al centro de clúster más cercano
vector<int> asignarClientes(const vector<vector<double>>& clientes, const vector<int>& centros) {
    int n = clientes.size();
    int K = centros.size();
    vector<int> asignaciones(n);

    for (int i = 0; i < n; i++) {
        double minDistancia = numeric_limits<double>::max();
        int centroAsignado = -1;
        for (int j = 0; j < K; j++) {
            double distancia = calcularDistancia(clientes[i], clientes[centros[j]]);
            if (distancia < minDistancia) {
                minDistancia = distancia;
                centroAsignado = j;
            }
        }
        asignaciones[i] = centroAsignado;
    }

    return asignaciones;
}

int main() {
    srand(time(0));

    // Ejemplo de conjunto de clientes con vectores de características
    vector<vector<double>> clientes = {
        {1.0, 2.0},
        {2.0, 3.0},
        {3.0, 4.0},
        {5.0, 7.0},
        {3.5, 5.0},
        {4.5, 5.0},
        {3.5, 4.5}
    };

    int K = 2; // Número de grupos deseados

    vector<int> centros = encontrarCentros(clientes, K);
    vector<int> asignaciones = asignarClientes(clientes, centros);

    cout << "Centros de clúster: ";
    for (int centro : centros) {
        cout << centro << " ";
    }
    cout << endl;

    cout << "Asignaciones de clientes: ";
    for (int asignacion : asignaciones) {
        cout << asignacion << " ";
    }
    cout << endl;

    return 0;
}
