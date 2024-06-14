#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para maximizar el número de contenedores cargados
int maximizarContenedoresCargados(int k, vector<int>& pesos) {
    // Ordenar los contenedores por peso en orden ascendente
    sort(pesos.begin(), pesos.end());

    int numeroContenedores = 0;
    int pesoTotal = 0;

    // Ir agregando contenedores hasta que no se pueda agregar más sin exceder la capacidad
    for (int peso : pesos) {
        if (pesoTotal + peso <= k) {
            pesoTotal += peso;
            numeroContenedores++;
        } else {
            break;
        }
    }

    return numeroContenedores;
}

int main() {
    int k = 50; // Capacidad del buque en toneladas
    vector<int> pesos = {10, 20, 30, 40, 50}; // Pesos de los contenedores en toneladas

    int resultado = maximizarContenedoresCargados(k, pesos);

    cout << "El número máximo de contenedores cargados es: " << resultado << endl;

    return 0;
}
