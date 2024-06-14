#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tarea {
    int id;
    int beneficio;
    int plazo;
};

// Comparador para ordenar tareas por beneficio decreciente
bool comparador(const Tarea& a, const Tarea& b) {
    return a.beneficio > b.beneficio;
}

int maximizarBeneficio(vector<Tarea>& tareas, int n) {
    // Ordenar las tareas por beneficio decreciente
    sort(tareas.begin(), tareas.end(), comparador);

    // Array para marcar los slots de tiempo disponibles
    vector<bool> slots(n, false);
    int beneficioTotal = 0;

    // Iterar sobre las tareas ordenadas
    for (int i = 0; i < n; i++) {
        // Encontrar un slot disponible desde el plazo de la tarea hacia atrás
        for (int j = min(n, tareas[i].plazo) - 1; j >= 0; j--) {
            if (!slots[j]) {
                slots[j] = true; // Marcar este slot como ocupado
                beneficioTotal += tareas[i].beneficio;
                break;
            }
        }
    }

    return beneficioTotal;
}

int main() {
    int n = 4; // Número de tareas
    vector<Tarea> tareas = {
        {1, 50, 2},
        {2, 10, 1},
        {3, 15, 2},
        {4, 30, 1}
    };

    int resultado = maximizarBeneficio(tareas, n);

    cout << "El beneficio máximo es: " << resultado << endl;

    return 0;
}
