#include <iostream>
#include <vector>
using namespace std;

int n; // Número de elementos
int capacidad; // Capacidad de la mochila
vector<int> pesos; // Pesos de los elementos
vector<int> beneficios; // Beneficios de los elementos

// Variables globales para la solución óptima
int mejorBeneficio;
vector<int> mejorSolucion;

// Función recursiva de backtracking con árbol combinatorio
void backtracking(int indice, int pesoActual, int beneficioActual, vector<int>& solucionActual) {
    if (pesoActual > capacidad) {
        return; // Si el peso excede la capacidad, retrocedemos
    }
    if (indice == n) {
        // Hemos alcanzado una combinación, verificamos si es la mejor solución
        if (beneficioActual > mejorBeneficio) {
            mejorBeneficio = beneficioActual;
            mejorSolucion = solucionActual;
        }
        return;
    }

    // Generar todas las combinaciones posibles a partir del índice actual

    // Explorar la opción de no incluir el elemento en la mochila
    solucionActual[indice] = 0;
    backtracking(indice + 1, pesoActual, beneficioActual, solucionActual);

    // Explorar la opción de incluir el elemento en la mochila
    solucionActual[indice] = 1;
    backtracking(indice + 1, pesoActual + pesos[indice], beneficioActual + beneficios[indice], solucionActual);
}

int main() {
    // Datos del problema
    n = 4;
    capacidad = 7;
    pesos = {1, 3, 4, 5};
    beneficios = {1, 4, 5, 7};

    mejorBeneficio = 0;
    mejorSolucion.resize(n, 0);
    vector<int> solucionActual(n, 0);

    // Llamada inicial a la función de backtracking
    backtracking(0, 0, 0, solucionActual);

    // Mostrar el resultado
    cout << "Mejor beneficio: " << mejorBeneficio << endl;
    cout << "Mejor solución (elementos incluidos): ";
    for (int i = 0; i < n; ++i) {
        if (mejorSolucion[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
