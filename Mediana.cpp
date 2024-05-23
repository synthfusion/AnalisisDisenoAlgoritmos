#include <iostream>
#include <vector>
#include <algorithm>

typedef int TElem;
//Particion #1
void particion(std::vector<TElem>& v, int a, int b, int& p) {
  TElem pivote = v[a];
  int i = a + 1;
  int j = b;
  while (i <= j) {
    while (i <= j && v[i] <= pivote) i++;
    while (i <= j && v[j] > pivote) j--;
    if (i < j) std::swap(v[i], v[j]);
  }
  std::swap(v[a], v[j]);
  p = j;
  }

//Seleccion #1
TElem seleccion1(std::vector<TElem>& v, int a, int b, int k) {
  int p;
  if (a == b){
    return v[a];
  }
  else {
    particion(v, a, b, p);
    if (k == p) {
      return v[p];
    } else if (k < p) {
      return seleccion1(v, a, p - 1, k);
    } else {
      return seleccion1(v, p + 1, b, k);
    }
  }
}

//Particion #2
void particion2(std::vector<TElem>& v, int a, int b, TElem pivote, int& p, int& q) {
  int k = a;
  while (k <= b) {
    if (v[k] < pivote) {
      std::swap(v[a], v[k]);
      a++;
      k++;
      } else if (v[k] == pivote) {
      k++;
      } else {
      std::swap(v[b], v[k]);
      b--;
      }
    }
  p = a - 1;
  q = b + 1;
}

//Seleccion #2
TElem seleccion2(std::vector<TElem>& v, int a, int b, int k) {
  int p, q;
  int t = b - a + 1;

  if (t <= 12) {
    std::sort(v.begin() + a, v.begin() + b + 1);
    return v[a + k];
  }
  
  int s = t / 5;
  std::vector<TElem> medianas;

  for (int l = 1; l <= s; l++) {
    std::sort(v.begin() + 5 * (l - 1), v.begin() + 5 * l);
    int pm = a + 5 * (l - 1) + (5 / 2);
    medianas.push_back(v[pm]);
  }
  
  TElem mm = seleccion2(medianas, 0, medianas.size() - 1, medianas.size() / 2);
  particion2(v, a, b, mm, p, q);
  
  if (k >= p && k <= q) {
    return mm;
  } else if (k < p) {
    return seleccion2(v, a, p - 1, k);
  } else {
    return seleccion2(v, q + 1, b, k);
  }
}


int main() {
  std::vector<TElem> v = {11, 2, 3, 4, 5, 6};
  int k = 1;
  TElem resultado = seleccion2(v, 0, v.size() - 1, k - 1);
  std::cout << "El " << k << "-ésimo menor elemento es: " << resultado << std::endl;
  return 0;
}

