#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Objeto {
    double peso;
    double beneficio;
};

// Función para resolver el problema de la mochila con programación dinámica
double mochilaProgramacionDinamica(vector<Objeto>& objetos, double capacidad) {
    int n = objetos.size();
    
    // Crear un vector para almacenar los beneficios máximos para cada capacidad
    vector<double> dp(capacidad + 1, 0.0);

    // Procesar cada objeto
    for (int i = 0; i < n; ++i) {
        // Recorrer de derecha a izquierda para no usar el mismo objeto más de una vez
        for (int j = capacidad; j >= 0; --j) {
            if (j >= objetos[i].peso) {
                dp[j] = max(dp[j], dp[j - objetos[i].peso] + objetos[i].beneficio);
            }
        }
    }

    // El valor máximo estará en dp[capacidad]
    return dp[capacidad];
}

int main() {
    // Datos del problema
    double capacidad = 7.5;
    vector<Objeto> objetos = {
        {1.5, 1.0},
        {3.0, 4.0},
        {4.0, 5.0},
        {5.0, 7.0}
    };

    // Resolver el problema utilizando programación dinámica
    double mejorBeneficio = mochilaProgramacionDinamica(objetos, capacidad);

    // Mostrar el resultado
    cout << "Mejor beneficio obtenido: " << mejorBeneficio << endl;

    return 0;
}
