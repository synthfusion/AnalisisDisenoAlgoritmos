#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dividirEntero(const vector<int>& numero) {
  int longitud = numero.size();
  int mitad = longitud / 2;
  
  if (longitud % 2 != 0) {
    vector<int> cero(1, 0);
    numero.insert(numero.end(), cero.begin(), cero.end());
    mitad++;
  }

  vector<vector<int>> mitades(2);
  mitades[0] = vector<int>(numero.begin(), numero.begin() + mitad);
  mitades[1] = vector<int>(numero.begin() + mitad, numero.end());

  return mitades;
}


vector<int> sumarVectores(const vector<int>& numero1, const vector<int>& numero2) {
  int acarreo = 0;
  vector<int> resultado;
  
  for (int i = numero1.size() - 1; i >= 0; i--) {
    int digito1 = numero1[i];
    int digito2 = numero2[i];

    int sumaParcial = digito1 + digito2 + acarreo;
    acarreo = sumaParcial / 10;
    int digitoResultado = sumaParcial % 10;

    resultado.insert(resultado.begin(), digitoResultado);
  }

  if (acarreo > 0) {
    resultado.insert(resultado.begin(), acarreo);
  }

  return resultado;
}

vector<int> multiplicarGrandes(const vector<int>& numero1, const vector<int>& numero2) {
  if (numero1.empty() || numero2.empty() || numero1[0] == 0 || numero2[0] == 0) {
    return vector<int>(1, 0);
  }

  if (numero1.size() <= 2 && numero2.size() <= 2) {
    long long resultado = 0;
    for (int i = 0; i < numero1.size(); i++) {
      for (int j = 0; j < numero2.size(); j++) {
        resultado += numero1[i] * numero2[j];
      }
    }
    return vector<int>(to_string(resultado));
  }

  vector<vector<int>> mitades1 = dividirEntero(numero1);
  vector<vector<int>> mitades2 = dividirEntero(numero2);

  vector<int> A_alta_B_alta = multiplicarGrandes(mitades1[0], mitades2[0]);
  vector<int> A_baja_B_baja = multiplicarGrandes(mitades1[1], mitades2[1]);
  vector<int> A_alta_B_baja = multiplicarGrandes(mitades1[0], mitades2[1]);
  vector<int> A_baja_B_alta = multiplicarGrandes(mitades1[1], mitades2[0]);

  vector<int> resultado1 = sumarVectores(A_alta_B_alta, vector<int>(mitades1[0].size() + mitades2[0].size() - 2, 0));
  vector<int> resultado2 = A_baja_B_baja;
  vector<int> resultado3 = sumar
