#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> DevolverCambio(int P, const vector<int>&C){
  int act=0;
  int n=C.size();
  vector<int>X(n,0);

  int j=n-1;
  while(act!=P){
    while(j>=0&&C[j]>(P-act)){
      j--;
    }
    if(j<0){
      cout<<"No existe solucion"<<endl;
      return vector<int>();
    }
    X[j]=(P-act)/C[j];
    act=act+C[j]*X[j];
  }
  return X;
}

int main(){
  vector<int>monedas={1,2,5,10,20,50,100,200};
  //sort(monedas.begin(),monedas.end()); //monedas ordenadas de menor a mayor (pero se vuelve nlogn)
  int cantidad=87;
  vector<int>resultado=DevolverCambio(cantidad,monedas);
  if(!resultado.empty()){ //si es que existe una solucion
    cout<<"Monedas usadas: ";
    for(int i=0; i<resultado.size(); ++i){
      cout<<resultado[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
