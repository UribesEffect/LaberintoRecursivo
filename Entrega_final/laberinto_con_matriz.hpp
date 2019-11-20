#include <fstream>
#include <iostream>
using namespace std;

const int ARRIBA=0, DERECHA=1, IZQUIERDA=2, ABAJO=3;

class Laberinto{
private:
  int matriz[100][100]; // Matriz que guarda los datos del archivo. El maximo del laberinto son 100 filas por 100 columnas.

  int filas,columnas; // filas y columnas del laberinto
  int filapersona,columnapersona; // coordenadas del jugador
  int filasalida,columnasalida; // coordenadas de la salida o meta


  int direccion=ARRIBA; // El jugador inicia viendo hacia arriba
  int arriba, abajo, izquierda, derecha; // Con estos atributos guardamos la informacion de la matriz para girar a dicho lado
                                         // Es decir las direcciones que tiene la persona

public:
  void leerArchivo();
  void MuestraLaberinto();
  void RecorrerLaberinto();
  void recorrido_total();
};
