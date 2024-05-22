#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matriz;

Matriz sumarMatrices(const Matriz& A, const Matriz& B) {
    int n = A.size();
    Matriz C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matriz restarMatrices(const Matriz& A, const Matriz& B) {
    int n = A.size();
    Matriz C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

Matriz multiplicarMatrices(const Matriz& A, const Matriz& B) {
    int n = A.size();
    Matriz C(n, vector<int>(n, 0));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int newSize = n / 2;
        Matriz A11(newSize, vector<int>(newSize));
        Matriz A12(newSize, vector<int>(newSize));
        Matriz A21(newSize, vector<int>(newSize));
        Matriz A22(newSize, vector<int>(newSize));

        Matriz B11(newSize, vector<int>(newSize));
        Matriz B12(newSize, vector<int>(newSize));
        Matriz B21(newSize, vector<int>(newSize));
        Matriz B22(newSize, vector<int>(newSize));

        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        Matriz M1 = multiplicarMatrices(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
        Matriz M2 = multiplicarMatrices(sumarMatrices(A21, A22), B11);
        Matriz M3 = multiplicarMatrices(A11, restarMatrices(B12, B22));
        Matriz M4 = multiplicarMatrices(A22, restarMatrices(B21, B11));
        Matriz M5 = multiplicarMatrices(sumarMatrices(A11, A12), B22);
        Matriz M6 = multiplicarMatrices(restarMatrices(A21, A11), sumarMatrices(B11, B12));
        Matriz M7 = multiplicarMatrices(restarMatrices(A12, A22), sumarMatrices(B21, B22));

        Matriz C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7);
        Matriz C12 = sumarMatrices(M3, M5);
        Matriz C21 = sumarMatrices(M2, M4);
        Matriz C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6);

        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < newSize; ++j) {
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
        }
    }
    return C;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz (n): ";
    cin >> n;

    Matriz A(n, vector<int>(n));
    Matriz B(n, vector<int>(n));

    cout << "Ingrese la matriz A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Ingrese la matriz B:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    Matriz C = multiplicarMatrices(A, B);

    cout << "Resultado de A * B:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
