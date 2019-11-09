#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void imprimirlaberinto(string filename){
  char letra;
  fstream ficheroEntrada;
  ficheroEntrada.open(filename, ios::in);
  if (ficheroEntrada.is_open()) {
    while (! ficheroEntrada.eof() ) {
      ficheroEntrada >> letra;
      if (letra == '1') {
        cout << "|" ;
      }else if (letra == '0') {
        cout << " " ;
      }else if(letra == '2'){
        cout << endl;
      }else{
        cout << letra;
      }

    }
    cout << endl;
    ficheroEntrada.close();
    }
    else cout << "Fichero inexistente" << endl;
}

int main () {

 imprimirlaberinto("laberinto1.txt");


   return 0;
}
