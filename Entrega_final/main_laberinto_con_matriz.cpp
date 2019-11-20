#include <fstream>
#include <iostream>
using namespace std;
#include "laberinto_con_matriz.hpp"

int main(){
      Laberinto laberinto;
      laberinto.leerArchivo();
      laberinto.MuestraLaberinto();
      laberinto.recorrido_total();
      cout << "         #         HAS LLEGADO A LA META         #\n";
      cout << "         #########################################\n";

return 0;

}
