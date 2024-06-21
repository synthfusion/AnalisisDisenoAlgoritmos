#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definición del alfabeto y función f(x, y)
unordered_map<char, int> index = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}};

bool f(char x, char y) {
    // Implementación de la relación de orden Φ
    return index[x] < index[y];
}

// Función para determinar si u precede a v en Φ
bool precedeEnOrden(char u, char v) {
    // Tamaño del alfabeto Σ
    int size = index.size();

    // Matriz para almacenar si un elemento precede a otro
    vector<vector<bool>> precedes(size, vector<bool>(size, false));

    // Llenar la matriz usando la función f(x, y)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            precedes[i][j] = f(i + 'a', j + 'a');
        }
    }

    // Devolver el valor de precedes[u][v]
    return precedes[index[u]][index[v]];
}

int main() {
    // Ejemplos de uso
    char u = 'a', v = 'c';
    cout << "¿" << u << " precede a " << v << " en Φ? ";
    if (precedeEnOrden(u, v)) {
        cout << "Sí" << endl;
    } else {
        cout << "No" << endl;
    }

    u = 'd', v = 'b';
    cout << "¿" << u << " precede a " << v << " en Φ? ";
    if (precedeEnOrden(u, v)) {
        cout << "Sí" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
