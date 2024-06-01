#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fichero {
    int longitud;
};


bool comparador(const Fichero& a, const Fichero& b) {
    return a.longitud < b.longitud;
}

double calcularTMR(const vector<Fichero>& ficheros) {
    int n = ficheros.size();
    int tiempo_acumulado = 0;
    int suma_tiempos = 0;

    for (int i = 0; i < n; ++i) {
        tiempo_acumulado += ficheros[i].longitud; 
        suma_tiempos += tiempo_acumulado; 
    }

    return static_cast<double>(suma_tiempos) / n; 
}

void almacenarFicherosEnCinta(vector<Fichero>& ficheros) {
    sort(ficheros.begin(), ficheros.end(), comparador);

    double tmr = calcularTMR(ficheros);
    cout << "Tiempo Medio de Recuperación (TMR): " << tmr << endl;
}

int main() {
    vector<Fichero> ficheros = {{4}, {2}, {5}, {1}, {3}};
    almacenarFicherosEnCinta(ficheros);

    return 0;
}

