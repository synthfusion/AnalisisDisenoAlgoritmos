#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Actividad {
    int inicio;
    int fin;
};

bool compararActividades(Actividad a1, Actividad a2) {
    return (a1.fin < a2.fin);
}

void seleccionarActividades(vector<Actividad> &actividades) {
    sort(actividades.begin(), actividades.end(), compararActividades);

    vector<Actividad> actividadesSeleccionadas;

    actividadesSeleccionadas.push_back(actividades[0]);
    int ultimoIndiceSeleccionado = 0;

    for (int i = 1; i < actividades.size(); i++) {
        if (actividades[i].inicio >= actividades[ultimoIndiceSeleccionado].fin) {
            actividadesSeleccionadas.push_back(actividades[i]);
            ultimoIndiceSeleccionado = i;
        }
    }

    cout << "Las actividades seleccionadas son:" << endl;
    for (const auto& Actividad : actividadesSeleccionadas) {
        cout << "Comienza: " << Actividad.inicio << ", Termina: " << Actividad.fin << endl;
    }
}

int main() {
    vector<Actividad> actividades = {
        {1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    seleccionarActividades(actividades);

    return 0;
}
