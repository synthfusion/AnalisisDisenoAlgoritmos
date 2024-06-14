//Menor costo disponible

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int asignarTareasEstrategia1(const vector<vector<int>>& costos) {
    int n = costos.size();
    vector<bool> tareasAsignadas(n, false);
    vector<int> asignacion(n, -1);
    int costoTotal = 0;

    for (int i = 0; i < n; i++) {
        int minCosto = INT_MAX;
        int tareaSeleccionada = -1;

        for (int j = 0; j < n; j++) {
            if (!tareasAsignadas[j] && costos[i][j] < minCosto) {
                minCosto = costos[i][j];
                tareaSeleccionada = j;
            }
        }

        asignacion[i] = tareaSeleccionada;
        tareasAsignadas[tareaSeleccionada] = true;
        costoTotal += minCosto;
    }

    return costoTotal;
}

int main() {
    vector<vector<int>> costos = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int costoTotal = asignarTareasEstrategia1(costos);
    cout << "Costo total utilizando Estrategia 1: " << costoTotal << endl;

    return 0;
}


//Global del menor costo
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int asignarTareasEstrategia2(const vector<vector<int>>& costos) {
    int n = costos.size();
    vector<bool> trabajadoresAsignados(n, false);
    vector<bool> tareasAsignadas(n, false);
    int costoTotal = 0;

    for (int k = 0; k < n; k++) {
        int minCosto = INT_MAX;
        int trabajadorSeleccionado = -1;
        int tareaSeleccionada = -1;

        for (int i = 0; i < n; i++) {
            if (!trabajadoresAsignados[i]) {
                for (int j = 0; j < n; j++) {
                    if (!tareasAsignadas[j] && costos[i][j] < minCosto) {
                        minCosto = costos[i][j];
                        trabajadorSeleccionado = i;
                        tareaSeleccionada = j;
                    }
                }
            }
        }

        trabajadoresAsignados[trabajadorSeleccionado] = true;
        tareasAsignadas[tareaSeleccionada] = true;
        costoTotal += minCosto;
    }

    return costoTotal;
}

int main() {
    vector<vector<int>> costos = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int costoTotal = asignarTareasEstrategia2(costos);
    cout << "Costo total utilizando Estrategia 2: " << costoTotal << endl;

    return 0;
}
