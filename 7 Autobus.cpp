#include <iostream>
#include <vector>

using namespace std;

// Función para determinar las paradas necesarias para repostar
vector<int> repostar(int n, vector<int>& gasolineras) {
    vector<int> paradas;
    int alcance_actual = n;
    int ultima_posicion = 0;

    for (int i = 0; i < gasolineras.size(); ++i) {
        if (gasolineras[i] > alcance_actual) {
            paradas.push_back(gasolineras[i - 1]);
            alcance_actual = gasolineras[i - 1] + n;
        }
    }

    if (gasolineras.back() <= alcance_actual) {
        paradas.push_back(gasolineras.back());
    }

    return paradas;
}

int main() {
    int n = 400; // Distancia máxima con un tanque lleno
    vector<int> gasolineras = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}; // Distancias de las gasolineras

    vector<int> paradas = repostar(n, gasolineras);

    cout << "El autobús debe repostar en las siguientes gasolineras: ";
    for (int parada : paradas) {
        cout << parada << " ";
    }
    cout << endl;

    return 0;
}
