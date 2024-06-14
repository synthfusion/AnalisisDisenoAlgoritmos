//Maximizar el número de programas almacenados en el disco
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para maximizar el número de programas almacenados en el disco
int maximizarProgramasAlmacenados(int D, vector<int>& tamaños) {
    // Ordenar los programas por tamaño en orden ascendente
    sort(tamaños.begin(), tamaños.end());

    int numeroProgramas = 0;
    int espacioTotal = 0;

    // Ir agregando programas hasta que no se pueda agregar más sin exceder la capacidad
    for (int tamaño : tamaños) {
        if (espacioTotal + tamaño <= D) {
            espacioTotal += tamaño;
            numeroProgramas++;
        } else {
            break;
        }
    }

    return numeroProgramas;
}

int main() {
    int D = 100; // Capacidad del disco en megabytes
    vector<int> tamaños = {20, 10, 30, 50, 40}; // Tamaños de los programas en megabytes

    int resultado = maximizarProgramasAlmacenados(D, tamaños);

    cout << "El número máximo de programas almacenados es: " << resultado << endl;

    return 0;
}

//Maximizar el uso de la capacidad del disco
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para maximizar el uso de la capacidad del disco
int maximizarUsoCapacidadDisco(int D, vector<int>& tamaños) {
    // Ordenar los programas por tamaño en orden descendente
    sort(tamaños.begin(), tamaños.end(), greater<int>());

    int espacioTotal = 0;

    // Ir agregando programas hasta que no se pueda agregar más sin exceder la capacidad
    for (int tamaño : tamaños) {
        if (espacioTotal + tamaño <= D) {
            espacioTotal += tamaño;
        } else {
            break;
        }
    }

    return espacioTotal;
}

int main() {
    int D = 100; // Capacidad del disco en megabytes
    vector<int> tamaños = {20, 10, 30, 50, 40}; // Tamaños de los programas en megabytes

    int resultado = maximizarUsoCapacidadDisco(D, tamaños);

    cout << "El uso máximo de la capacidad del disco es: " << resultado << " MB" << endl;

    return 0;
}
