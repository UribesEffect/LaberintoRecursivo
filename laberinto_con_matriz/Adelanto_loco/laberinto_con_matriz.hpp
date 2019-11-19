#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
using namespace std;

const int ARRIBA=0, DERECHA=1, IZQUIERDA=2, ABAJO=3;

class Laberinto{
private:
  int m[100][100]; // Matriz que guarda los datos del archivo. El maximo del laberinto son 100 filas por 100 columnas.
                   //Se puede modificar
  int f,c; // filas y columnas del laberinto
  int fp,cp; // coordenadas del jugador
  int fs,cs; // coordenadas de la salida o meta
  int direccion=ARRIBA; // El jugador inicia viendo hacia arriba
  int arriba, abajo, izquierda, derecha; // Aqui guardamos la informacion de la matriz de las
                                        // cuatro direcciones junto al jugador

public:
  void leerArchivo();
  void MuestraLaberinto();
  void RecorrerLaberinto();
}
