#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
using namespace std;
#include "laberintos.hpp"

int main(){
  leerArchivo();
  MuestraLaberinto();
  while (fp!=fs || cp!=cs) {// Cuando encontramos la meta, salimos del ciclo
    RecorrerLaberinto();
    MuestraLaberinto();
  }
  system("cls");
  printf ("El jugador llego a la meta\n");
  system("pause");
  return 0;
}
