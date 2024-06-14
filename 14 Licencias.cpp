#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una licencia con su tasa de incremento
struct Licencia {
    int id;
    double incremento;

    // Constructor
    Licencia(int id, double incremento) : id(id), incremento(incremento) {}
};

// Función de comparación para ordenar las licencias en orden decreciente de tasa de incremento
bool compararIncremento(const Licencia& a, const Licencia& b) {
    return a.incremento > b.incremento;
}

// Función para calcular el coste total de adquirir las licencias de manera óptima
double costeTotal(vector<Licencia>& licencias) {
    // Ordenar las licencias en orden decreciente de tasa de incremento
    sort(licencias.begin(), licencias.end(), compararIncremento);

    double costeTotal = 0.0;
    int meses = 0;

    for (const Licencia& licencia : licencias) {
        costeTotal += 100.0 * pow(1 + licencia.incremento, meses);
        meses++;
    }

    return costeTotal;
}

int main() {
    // Ejemplo de tasas de incremento para las licencias
    vector<Licencia> licencias = {
        Licencia(1, 0.05),
        Licencia(2, 0.03),
        Licencia(3, 0.07),
        Licencia(4, 0.02),
        Licencia(5, 0.04)
    };

    double totalCoste = costeTotal(licencias);
    cout << "Coste total mínimo de adquisición de licencias: " << totalCoste << " €" << endl;

    return 0;
}
