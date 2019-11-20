#include <fstream>
#include <iostream>
using namespace std;

int matriz[100][100]; // Matriz que guarda los datos del archivo. El maximo del laberinto son 100 filas por 100 columnas.

int filas,columnas; // filas y columnas del laberinto

int filapersona,columnapersona; // coordenadas del jugador

int filasalida,columnasalida; // coordenadas de la salida o meta

const int ARRIBA=0, DERECHA=1, IZQUIERDA=2, ABAJO=3;

int direccion=ARRIBA; // El jugador inicia viendo hacia arriba

int arriba, abajo, izquierda, derecha; // Con estos atributos guardamos la informacion de la matriz para girar a dicho lado
                                       // Es decir las direcciones que tiene la persona

void leerArchivo() {
    int maxCol;
    ifstream archivo;
    char caracter;
    int caracterAscii;
    bool boolcolumnas=true; // Sirve para que aumente el numero de columnas solo hasta que encuentre le primer salto de linea

               // suponiendo que el archivo tiene todas las lineas de igual numero de caracteres


        string a = "laberinto.txt"; //guardamos el nombre del laberinto para imprimirlo al final de que si lo ejecuto
        archivo.open(a); // abrimos el archivo que tiene el laberinto que queremos resolver

        if (!archivo.is_open()) { // Si el archivo no existe o esta mal el nombre se ejecuta
           cout <<"Error en lectura de archivo\n";
           exit(true); // se acaba el programa por error de no encontrar el archivo
        }

        while(!archivo.eof()) { // sirve para llegar al final de la lectura del archivo
                caracter = archivo.get();//asignamos a caracter cada uno de los chars del txt
                caracterAscii = caracter; // obtenemos el codigo Ascii de el caracter

                if (caracterAscii == 10) { // 10 se refiere al codigo Ascii del salto de lineas


                     filas++; //Añadimos una fila a nuestra matriz

                     if (boolcolumnas){// solo lo hacemos para asignar el maximo de columnas
                          maxCol = columnas;
                          boolcolumnas = false;
                     }

                     columnas = 0;


                } else {
                       matriz[filas][columnas] = caracterAscii - 48;
                       if ( matriz[filas][columnas] == 2){
                         filapersona = filas; columnapersona = columnas;
                       }
                       if ( matriz[filas][columnas] == 3){
                         filasalida = filas;columnasalida = columnas;
                       }
                       columnas++ ;// añadimos una columna mas a nuestra matriz
                }
        }

        columnas = maxCol; // aqui ya se asigna la cantidad de columnas de la matriz
        cout << "  ########################################################" << '\n';
        cout << "  # Archivo leido exitosamente y se llama: " << a <<" #\n";
        cout << "  ########################################################" << '\n';
        cout << "  ###      A continuacion el inicio del laberinto" << "      ###\n";
        cout << "  ########################################################" << '\n';
        cout << "  ###     Para avanzar cada posicion presione Enter    " << "###\n";
        cout << "  ###     y mantenga undido Enter para verlo rapido    " << "###\n";
        cout << "  ########################################################" << '\n';
        archivo.close(); // cerramos el archivo


}



void MuestraLaberinto() {
     // En esta funcion cambiamos el txt que tomamos en leer archivo  y lo convertimos en:
     // los 0 ahora son ' '
     // los 1 ahora son '|'
     // el 2 ahora es 'P' que se refiere a la persona
     // el 3 ahora es 'S' que se refiere a la salida

    for (int i = 0;i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
           if (matriz[i][j] == 1) cout << "|";
           else if (i == filapersona && j == columnapersona) cout << "P";
           else if (i == filasalida && j == columnasalida) cout << "S";
           else cout << " ";
        }
    cout << "\n";
    }
    cout << "############################################################" << '\n';//para separar un laberinto de otro

}

void RecorrerLaberinto() {
    int fila_antigua_persona,columna_antigua_persona; // con estos enteros guardaremos la pasada posicion de la persona para poner un espacio

      fila_antigua_persona = filapersona; //asignamos la fila de la persona antes de moverse
      columna_antigua_persona = columnapersona; // asignamos la columna de la persona antes de moverse

      arriba = matriz[filapersona-1][columnapersona];// asignamos lo que significa en la matriz moverse para arriba

      abajo = matriz[filapersona+1][columnapersona];// asignamos lo que significa en la matriz moverse para abajo

      derecha = matriz[filapersona][columnapersona+1];// asignamos lo que significa en la matriz moverse para la derecha

      izquierda = matriz[filapersona][columnapersona-1];// asignamos lo que significa en la matriz moverse para la izquierda

      //############################################
      //### si la meta esta al lado de la persona###
      //############################################
      if (derecha == 3)
          direccion = DERECHA;
      else if (izquierda == 3)
          direccion = IZQUIERDA;
      else if (arriba == 3)
          direccion = ARRIBA;
      else if (abajo == 3)
          direccion = ABAJO;
      //###############################################


      //#########################################
      //### Si la meta no esta al lado nuestro###
      //#########################################
      else if (direccion == ARRIBA){ // miramos hacia arriba
         if (derecha == 1 && arriba == 0) {}// miramos si tenemos pared a la derecha
         else if (derecha == 0) // si no tenemos pared a la derecha miramos hacia alla
            direccion = DERECHA;
         else if (izquierda == 0) // si hay pared a la derecha miramos para la izquierda y so no hay pared miramos para alla
            direccion = IZQUIERDA;
         else
            direccion = ABAJO;// la ultima opcion seria devolvernos es decir mirar hacia abajo

      }
      else if (direccion == 1){ // si direccion es igual a 1 quiere decir que volteamos a la derecha
         if (abajo == 1 && derecha == 0) {}// Antes de avanzar hacia la derecha checamos si hay pared abajo

         else if (abajo == 0)// si no hay pared abajo nos giramos a la derecha (volteamos sabiendo que estamos mirando para abajo)
            direccion = ABAJO;
         else if (arriba == 0)// si no hay pared arriba giramos a la izquierda (volteamos sabiendo que estamos mirando para abajo)
            direccion = ARRIBA;
         else
            direccion = IZQUIERDA;// por ultimo seria la izquierda

      }
      else if (direccion == 3){ // si direccion es igual a 3 quiere decir que volteamos para abajo

         if (abajo == 0 && izquierda == 1) {}// si no tenemos paredes a los lados avanzamos
         else if (izquierda == 0)
            direccion = IZQUIERDA;// si no tenemos pared a la izquierda nos giramos a esta direccion
         else if (derecha == 0)
            direccion = DERECHA;// si no tenemos pared a la derecha nos giramos a esta direccion
         else
            direccion = ARRIBA; // por ultimo nos queda para arriba

      }

      else if (direccion==2){ // si direccion es igual a 2 quiere decir que volteamos para la izquierda

         if (izquierda == 0 && arriba == 1) {}// si tenemos paredes arriba y a la izquierda no, avanzamos

         else if (arriba == 0)// si no hay pared arriba giramos a la derecha
            direccion = ARRIBA;
         else if (abajo == 0)// si no hay pared abajo nos direcionamos a dicha posicion
            direccion = ABAJO;
         else
            direccion = DERECHA;// por ultimo nos devolvemos

      }

      matriz[fila_antigua_persona][columna_antigua_persona] = 0; // ponemos un espacio donde estaba el jugador

      switch(direccion){ // con este switch movemos al jugador segun los casos(paredes) que tengamos
        case 0:

             matriz[filapersona-1][columnapersona]=2; // actualizamos matriz
             filapersona--; // Actualizamos coordenadas del jugador
             break;

        case 1:

             matriz[filapersona][columnapersona+1]=2; // actualizamos matriz
             columnapersona++; // Actualizamos coordenadas del jugador
             break;

        case 2:

             matriz[filapersona][columnapersona-1]=2; // actualizamos matriz
             columnapersona--; // Actualizamos coordenadas del jugador
             break;

        case 3:

             matriz[filapersona+1][columnapersona]=2; // actualizamos matriz
             filapersona++; // Actualizamos coordenadas del jugador
             break;
      }
}

void recorrido_total(){
  int pasos = 0; //entero que guarda los movimientos de la persona
  while (filapersona != filasalida || columnapersona != columnasalida) {// Cuando encontramos la meta, salimos del ciclo

    getchar();//con esta funcion al undir una tecla del teclado continuamos con el while
    RecorrerLaberinto();
    pasos++;
    MuestraLaberinto();

  }
  cout << '\n';
  cout << "         #########################################\n";
  cout << "         ##     Cantidad de pasos dados: " << pasos <<"    ##\n";
  cout << "         #########################################\n";
}


int main() {


    leerArchivo();
    MuestraLaberinto();
    recorrido_total();
    // cout<< "    _____Sexy?Sex\n";
    // cout<< "____?Sexy?Sexy\n";
    // cout<< "___y?Sexy?Sexy?\n";
    // cout<< "___?Sexy?Sexy?S\n";
    // cout<< "___?Sexy?Sexy?S\n";
    // cout<< "__?Sexy?Sexy?Se\n";
    // cout<< "_?Sexy?Sexy?Se\n";
    // cout<< "_?Sexy?Sexy?Se\n";
    // cout<< "_?Sexy?Sexy?Sexy?\n";
    // cout<< "?Sexy?Sexy?Sexy?Sexy\n";
    // cout<< "?Sexy?Sexy?Sexy?Sexy?Se\n";
    // cout<< "?Sexy?Sexy?Sexy?Sexy?Sex\n";
    // cout<< "_?Sexy?__?Sexy?Sexy?Sex\n";
    // cout<< "___?Sex____?Sexy?Sexy?\n";
    // cout<< "___?Sex_____?Sexy?Sexy\n";
    // cout<< "___?Sex_____?Sexy?Sexy\n";
    // cout<< "____?Sex____?Sexy?Sexy\n";
    // cout<< "_____?Se____?Sexy?Sex\n";
    // cout<< "______?Se__?Sexy?Sexy\n";
    // cout<< "_______?Sexy?Sexy?Sex\n";
    // cout<< "________?Sexy?Sexy?sex\n";
    // cout<< "_______?Sexy?Sexy?Sexy?Se\n";
    // cout<< "_______?Sexy?Sexy?Sexy?Sexy?\n";
    // cout<< "_______?Sexy?Sexy?Sexy?Sexy?Sexy\n";
    // cout<< "_______?Sexy?Sexy?Sexy?Sexy?Sexy?S\n";
    // cout<< "________?Sexy?Sexy____?Sexy?Sexy?se\n";
    // cout<< "_________?Sexy?Se_______?Sexy?Sexy?\n";
    // cout<< "_________?Sexy?Se_____?Sexy?Sexy?\n";
    // cout<< "_________?Sexy?S____?Sexy?Sexy\n";
    // cout<< "_________?Sexy?S_?Sexy?Sexy\n";
    // cout<< "________?Sexy?Sexy?Sexy\n";
    // cout<< "________?Sexy?Sexy?S\n";
    // cout<< "________?Sexy?Sexy\n";
    // cout<< "_______?Sexy?Se\n";
    // cout<< "_______?Sexy?\n";
    // cout<< "______?Sexy?\n";
    // cout<< "______?Sexy?\n";
    // cout<< "______?Sexy?\n";
    // cout<< "______?Sexy\n";
    // cout<< "______?Sexy\n";
    // cout<< "_______?Sex\n";
    // cout<< "_______?Sex\n";
    // cout<< "_______?Sex\n";
    // cout<< "______?Sexy\n";
    // cout<< "______?Sexy\n";
    // cout<< "_______Sexy\n";
    // cout<< "_______ Sexy?\n";
    // cout<< "________SexY\n";
    cout << "         #         HAS LLEGADO A LA META         #\n";
    cout << "         #########################################\n";

    return 0;

}
