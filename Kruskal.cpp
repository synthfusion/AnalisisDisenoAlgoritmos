#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Arista {
    int u, v, weight;
    bool operator<(const Arista& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

vector<Arista> kruskal(int V, vector<Arista>& aristas) {
    vector<Arista> result;
    sort(aristas.begin(), aristas.end());
    UnionFind uf(V);

    for (const auto& edge : aristas) {
        if (uf.unionSets(edge.u, edge.v)) {
            result.push_back(edge);
            if (result.size() == V - 1) {
                break;
            }
        }
    }

    if (result.size() != V - 1) {
        cout << "No hay solucion" << endl;
        return {};
    }

    return result;
}

int main() {
    int V = 4;
    vector<Arista> aristas = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Arista> mst = kruskal(V, aristas);

    if (!mst.empty()) {
        cout << "Aristas en el arbol de expansion minima:" << endl;
        for (const auto& edge : mst) {
            cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
        }
    }

    return 0;
}

