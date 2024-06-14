#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

struct Grafo {
    int V;
    vector<vector<int>> adj;

    Grafo(int V) : V(V), adj(V) {}

    void agregarArista(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int grado(int u) {
        return adj[u].size();
    }

    void removerAristas(int u) {
        for (int v : adj[u]) {
            adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
        }
        adj[u].clear();
    }
};

vector<int> recubrimiento(Grafo& G) {
    vector<int> U;
    set<pair<int, int>> nodosGrado;

    for (int i = 0; i < G.V; ++i) {
        nodosGrado.insert({G.grado(i), i});
    }

    while (!nodosGrado.empty()) {
        auto it = prev(nodosGrado.end()); // Nodo con mayor grado
        int u = it->second;

        U.push_back(u);
        nodosGrado.erase(it);
        G.removerAristas(u);

        for (auto it = nodosGrado.begin(); it != nodosGrado.end(); ) {
            int v = it->second;
            int nuevoGrado = G.grado(v);
            if (nuevoGrado == 0) {
                it = nodosGrado.erase(it);
            } else {
                it = nodosGrado.erase(it);
                nodosGrado.insert({nuevoGrado, v});
            }
        }
    }

    return U;
}

int main() {
    int V = 5;
    Grafo G(V);
    G.agregarArista(0, 1);
    G.agregarArista(0, 2);
    G.agregarArista(1, 2);
    G.agregarArista(1, 3);
    G.agregarArista(3, 4);

    vector<int> resultado = recubrimiento(G);

    cout << "El recubrimiento obtenido es: ";
    for (int nodo : resultado) {
        cout << nodo << " ";
    }
    cout << endl;

    return 0;
}
