#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MAXN = 105;
const int POSITIVE = 1;
const int NEGATIVE = -1;

unordered_map<char, int> charToIndex = {
    {'a', 0},
    {'b', 1},
    {'c', 2}
};

vector<vector<int>> multiplyMatrix = {
    {0, 1, 2},
    {1, 2, 0},
    {2, 0, 1}
};

int main() {
    string x = "abacab";
    int n = x.size();

    // dp[i][j] will store the result of multiplication of substring x[i..j]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // neg[i][j] will store the sign of dp[i][j]: 1 for positive, -1 for negative
    vector<vector<int>> neg(n + 1, vector<int>(n + 1, 1));

    // Initialize dp[i][i] and neg[i][i]
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = charToIndex[x[i - 1]];
        neg[i][i] = 1; // Always positive initially
    }

    // Fill dp and neg matrices
    for (int len = 2; len <= n; ++len) { // length of substring
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = multiplyMatrix[dp[i][i]][dp[i + 1][j]];
            neg[i][j] = neg[i][i] * neg[i + 1][j];
        }
    }

    // Result is dp[1][n] with its sign
    int result = dp[1][n] * neg[1][n];
    
    // Determine the final character based on result
    char finalChar;
    if (result == POSITIVE) {
        finalChar = 'a';
    } else if (result == NEGATIVE) {
        finalChar = 'b';
    } else {
        finalChar = 'c';
    }

    cout << "Resultado de la multiplicación de la cadena " << x << ": " << finalChar << endl;

    return 0;
}
