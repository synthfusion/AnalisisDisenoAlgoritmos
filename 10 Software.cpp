#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para encontrar el cambio usando el algoritmo greedy
vector<int> encontrarCambio(double cambio) {
    // Denominaciones de las monedas en euros
    vector<double> denominaciones = {1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
    vector<int> cantidadMonedas(denominaciones.size(), 0);

    for (size_t i = 0; i < denominaciones.size(); ++i) {
        // Determina el número de monedas de cada denominación
        while (cambio >= denominaciones[i]) {
            cambio = round((cambio - denominaciones[i]) * 100) / 100.0; // Redondea a dos decimales para evitar errores de precisión
            cantidadMonedas[i]++;
        }
    }

    return cantidadMonedas;
}

int main() {
    double cambio;
    cout << "Introduce el monto del cambio en euros: ";
    cin >> cambio;

    vector<int> resultado = encontrarCambio(cambio);

    cout << "El cambio mínimo en monedas es:\n";
    vector<double> denominaciones = {1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
    for (size_t i = 0; i < denominaciones.size(); ++i) {
        if (resultado[i] > 0) {
            cout << denominaciones[i] << " euros: " << resultado[i] << " monedas\n";
        }
    }

    return 0;
}
