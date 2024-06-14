#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Clase {
    int inicio;
    int fin;
};

bool compararInicio(const Clase& a, const Clase& b) {
    return a.inicio < b.inicio;
}

int minimizarAulas(vector<Clase>& clases) {
    // Ordenar las clases por hora de inicio
    sort(clases.begin(), clases.end(), compararInicio);
    
    // Priority queue para mantener las horas de fin de las aulas
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const Clase& clase : clases) {
        // Si la clase puede ser asignada a un aula que queda libre antes de su inicio
        if (!pq.empty() && pq.top() <= clase.inicio) {
            pq.pop();
        }
        // Asignar la clase a un aula (ya sea existente o nueva)
        pq.push(clase.fin);
    }

    // El tamaño de la priority queue será el número mínimo de aulas necesarias
    return pq.size();
}

int main() {
    vector<Clase> clases = {
        {9, 10}, {9, 11}, {11, 12}, {10, 11}, {12, 13}, {11, 14}
    };

    int numAulas = minimizarAulas(clases);
    cout << "Número mínimo de aulas necesarias: " << numAulas << endl;

    return 0;
}
