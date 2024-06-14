#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Función para encontrar el índice del dato que no se usará por el mayor tiempo en el futuro
int encontrarFuturoMasLejano(const vector<int>& solicitudes, const unordered_set<int>& cache, int currentIndex) {
    unordered_map<int, int> nextUse;

    for (int i = currentIndex + 1; i < solicitudes.size(); ++i) {
        if (cache.find(solicitudes[i]) != cache.end() && nextUse.find(solicitudes[i]) == nextUse.end()) {
            nextUse[solicitudes[i]] = i;
        }
    }

    int farthestIndex = currentIndex;
    int farthestDistance = -1;
    int datoARemover = -1;

    for (int dato : cache) {
        if (nextUse.find(dato) == nextUse.end()) {
            return dato; // Este dato no se usará en el futuro, así que se selecciona para remover
        } else if (nextUse[dato] > farthestDistance) {
            farthestDistance = nextUse[dato];
            datoARemover = dato;
        }
    }

    return datoARemover;
}

// Función para simular la caché con el algoritmo óptimo de reemplazo
int optimalCache(const vector<int>& solicitudes, int k) {
    unordered_set<int> cache;
    int fallos = 0;

    for (int i = 0; i < solicitudes.size(); ++i) {
        int solicitud = solicitudes[i];
        if (cache.find(solicitud) == cache.end()) { // Miss
            if (cache.size() == k) {
                int datoARemover = encontrarFuturoMasLejano(solicitudes, cache, i);
                cache.erase(datoARemover);
            }
            cache.insert(solicitud);
            fallos++;
        }
        // Si hay un hit, no hacemos nada
    }

    return fallos;
}

int main() {
    vector<int> solicitudes = {4, 2, 3, 4, 2, 3, 1, 2, 4, 1, 2};
    int k = 3;

    int numFallos = optimalCache(solicitudes, k);
    cout << "Número de fallos de caché: " << numFallos << endl;

    return 0;
}
