#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para almacenar información de cada cliente
struct Cliente {
    int id;
    int tiempoServicio;
};

// Comparador para ordenar los clientes por tiempo de servicio ascendente
bool comparador(const Cliente& a, const Cliente& b) {
    return a.tiempoServicio < b.tiempoServicio;
}

// Función para maximizar las ganancias del camarero
double maximizarGanancias(vector<Cliente>& clientes) {
    // Ordenar los clientes por tiempo de servicio ascendente
    sort(clientes.begin(), clientes.end(), comparador);

    double gananciaTotal = 0;
    int tiempoAcumulado = 0;

    // Calcular las ganancias basadas en el tiempo de espera de cada cliente
    for (const Cliente& cliente : clientes) {
        tiempoAcumulado += cliente.tiempoServicio;
        gananciaTotal += 1.0 / tiempoAcumulado;
    }

    return gananciaTotal;
}

int main() {
    vector<Cliente> clientes = {
        {1, 5},
        {2, 2},
        {3, 3},
        {4, 1}
    };

    double resultado = maximizarGanancias(clientes);

    cout << "La ganancia máxima es: " << resultado << endl;

    return 0;
}
