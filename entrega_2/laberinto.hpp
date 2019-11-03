#ifndef__LABERINTO__HPP
#define__LABERINTO__HPP
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Laberinto{
private :
  struct box{
//PARED(0) O CAMINO LIBRE(1)
    int datos;
//POSICIONES EN ENTEROS (1,1000)
    int posicion;
// APUNTADORES EN TODAS LAS DIRECCIONES
    box *left;
    box *right;
    box *above;
    box *below;
  };
  box *array;

// APUNTADORES A LA ENTRADA Y SALIDA DEL LABERINTO
  box *entry;
  box *exit;

public:
  Laberinto();
  ~Laberinto();
// POSICION DE LA CAJA
  int Posicion();
// ENTRADA Y SALIDA
  void entrada();
  void salida();
//ASIGNAMOS POSICIONES ENTERAS A TODO EL LABERINTO
//PRIMERA_POS= 1, ULTIMA_POS=1000 PARA UNA MATRIZ 20*50
  void asignar_posiciones();

};
#endif
