#include <iostream>
#include <vector>
using namespace std;

vector<int> encontrarLIS(const vector<int>& V) {
    int n = V.size();
    if (n == 0) return {};

    vector<int> dp(n, 1); // dp[i] representa la longitud de la LIS que termina en V[i]
    vector<int> anterior(n, -1); // Para reconstruir la LIS

    // Calcular dp y la longitud de la LIS
    int longitudMaxima = 1;
    int finLIS = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (V[j] < V[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                anterior[i] = j;
            }
        }
        if (dp[i] > longitudMaxima) {
            longitudMaxima = dp[i];
            finLIS = i;
        }
    }

    // Reconstruir la LIS
    vector<int> lis;
    int idx = finLIS;
    while (idx != -1) {
        lis.push_back(V[idx]);
        idx = anterior[idx];
    }
    reverse(lis.begin(), lis.end()); // Revertir para obtener la secuencia creciente

    return lis;
}

int main() {
    vector<int> V = {11, 17, 5, 8, 6, 4, 7, 12, 3};

    vector<int> lis = encontrarLIS(V);

    cout << "Secuencia creciente de máxima longitud encontrada:" << endl;
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
