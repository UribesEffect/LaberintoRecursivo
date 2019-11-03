#include "laberinto.hpp"

// CONSTRUCTOR
Laberinto:: Laberinto(){
  entry = nullptr;
  exit = nullptr;
  array = new box[1000];
  // MATRIZ 20X50
  //int matriz[20][50];
}

Laberinto:: ~Laberinto(){
  delete[] array;
}
// RETORNA POSICION DE LA CAJA
int Laberinto:: Posicion(){
  return posicion;
}

// INICIALIZA LA ENTRADA
void Laberinto:: entrada(){
  box *newbox = new box;
  newbox-> datos = 1;
  newbox->posicion = 1;
  newbox->above = nullptr;
  newbox->left = nullptr;
  entry = newbox;
}

// INICIALIZA LA SALIDA
void Laberinto:: salida(){
  box *newbox = new box;
  newbox-> datos = 1;
  newbox->posicion = 1000;
  newbox->below = nullptr;
  newbox->right = nullptr;
  exit = newbox;
}

void Laberinto:: asignar_posiciones(){
  for (int i= 1; i <=1000; i++){
      array[i-1].posicion = i;
  }

}
