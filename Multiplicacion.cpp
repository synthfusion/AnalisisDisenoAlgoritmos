#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sumarVectores(const vector<int>& numero1, const vector<int>& numero2) {
    int n1 = numero1.size(), n2 = numero2.size();
    int maxSize = max(n1, n2);
    vector<int> resultado(maxSize + 1, 0);
    int acarreo = 0;

    for (int i = 0; i < maxSize; i++) {
        int digito1 = (i < n1) ? numero1[n1 - 1 - i] : 0;
        int digito2 = (i < n2) ? numero2[n2 - 1 - i] : 0;
        int suma = digito1 + digito2 + acarreo;
        resultado[maxSize - i] = suma % 10;
        acarreo = suma / 10;
    }

    resultado[0] = acarreo;
    if (resultado[0] == 0) {
        resultado.erase(resultado.begin());
    }

    return resultado;
}

vector<int> restarVectores(const vector<int>& numero1, const vector<int>& numero2) {
    int n1 = numero1.size(), n2 = numero2.size();
    vector<int> resultado(n1, 0);
    int acarreo = 0;

    for (int i = 0; i < n1; i++) {
        int digito1 = numero1[n1 - 1 - i];
        int digito2 = (i < n2) ? numero2[n2 - 1 - i] : 0;
        int resta = digito1 - digito2 - acarreo;
        if (resta < 0) {
            resta += 10;
            acarreo = 1;
        } else {
            acarreo = 0;
        }
        resultado[n1 - 1 - i] = resta;
    }

    // Eliminar ceros a la izquierda
    while (resultado.size() > 1 && resultado[0] == 0) {
        resultado.erase(resultado.begin());
    }

    return resultado;
}

vector<int> desplazarIzquierda(const vector<int>& numero, int posiciones) {
    if (numero.empty() || (numero.size() == 1 && numero[0] == 0)) {
        return {0};
    }
    vector<int> resultado = numero;
    resultado.insert(resultado.end(), posiciones, 0);
    return resultado;
}

vector<vector<int>> dividirEntero(const vector<int>& numero) {
    int longitud = numero.size();
    int mitad = longitud / 2;
    vector<vector<int>> mitades(2);
    mitades[0] = vector<int>(numero.begin(), numero.begin() + mitad);
    mitades[1] = vector<int>(numero.begin() + mitad, numero.end());
    return mitades;
}

vector<int> multiplicarPequenos(const vector<int>& numero1, const vector<int>& numero2) {
    long long n1 = 0, n2 = 0;
    for (int d : numero1) n1 = n1 * 10 + d;
    for (int d : numero2) n2 = n2 * 10 + d;
    long long resultado = n1 * n2;
    vector<int> resultadoVector;
    if (resultado == 0) {
        return {0};
    }
    while (resultado > 0) {
        resultadoVector.insert(resultadoVector.begin(), resultado % 10);
        resultado /= 10;
    }
    return resultadoVector;
}

vector<int> multiplicarGrandes(const vector<int>& numero1, const vector<int>& numero2) {
    if (numero1.empty() || numero2.empty() || (numero1.size() == 1 && numero1[0] == 0) || (numero2.size() == 1 && numero2[0] == 0)) {
        return {0};
    }

    if (numero1.size() <= 2 && numero2.size() <= 2) {
        return multiplicarPequenos(numero1, numero2);
    }

    vector<vector<int>> mitades1 = dividirEntero(numero1);
    vector<vector<int>> mitades2 = dividirEntero(numero2);

    vector<int> low1 = mitades1[1];
    vector<int> high1 = mitades1[0];
    vector<int> low2 = mitades2[1];
    vector<int> high2 = mitades2[0];

    vector<int> z0 = multiplicarGrandes(low1, low2);
    vector<int> z2 = multiplicarGrandes(high1, high2);
    vector<int> sum1 = sumarVectores(low1, high1);
    vector<int> sum2 = sumarVectores(low2, high2);
    vector<int> z1 = multiplicarGrandes(sum1, sum2);
    z1 = restarVectores(z1, z0);
    z1 = restarVectores(z1, z2);

    vector<int> resultado1 = desplazarIzquierda(z2, 2 * low1.size());
    vector<int> resultado2 = desplazarIzquierda(z1, low1.size());

    vector<int> resultadoFinal = sumarVectores(resultado1, resultado2);
    resultadoFinal = sumarVectores(resultadoFinal, z0);

    return resultadoFinal;
}

int main() {
    vector<int> numero1 = {1, 2, 3, 4};
    vector<int> numero2 = {5, 6, 7, 8};
    vector<int> resultado = multiplicarGrandes(numero1, numero2);

    cout << "Resultado: ";
    for (int digito : resultado) {
        cout << digito;
    }
    cout << endl;

    return 0;
}
