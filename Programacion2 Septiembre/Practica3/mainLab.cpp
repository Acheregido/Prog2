/*
 * Fichero main de la Práctica 3 de Prog2 en la que se resuelve el problema
 * del laberinto utilizando Backtracking
*/
#include "laberinto.hpp"


int main(int argc, char* argv[]) {
  if (argc == 2) {
    string nombreFichero = "datos/";
    nombreFichero += argv[1];
    
    Laberinto lab1;
    cargarLaberinto(nombreFichero, lab1);
    bool encontrado = false;
    buscarCamino(lab1, encontrado);
    mostrarLaberinto(lab1);
  }
  else if (argc == 4) {
    double densidad;
    int fila, columna;
    densidad = atof(argv[1]);
    fila = atoi(argv[2]);
    columna = atoi(argv[3]);

    if  (0.0 <= densidad && densidad <= 1.0 && 3.0 <= fila && fila <= MAX_DIM && 3.0 <= columna && columna <= MAX_DIM) {
        Laberinto lab2;
        lab2.ancho = columna;
        lab2.alto = fila;
        generarLaberinto(lab2, densidad, fila, columna);
        bool encontrado = false;
        lab2.mapa[1][1] = LIBRE;
        lab2.mapa[lab2.alto - 2][lab2.ancho - 2] = LIBRE;
        buscarCamino(lab2, encontrado);
        mostrarLaberinto(lab2);
    }
    else {
      cerr << "Algo no ha funcionado correctamente" << endl;
      cerr << "La densidad debe estar entre 0 y 1" << endl;
      cerr << "El número de filas debe estar entre 3 y MAX_DIM" << endl;
      cerr << "El número de columnas debe estar entre 3 y MAX_DIM" << endl;
    }
    
  }
  else {
    cerr << "Algo no ha funcionado correctamente" << endl;
    cerr << "Solo puedes pasar 2 o 4 argumentos" << endl;
    cerr << "En el caso de pasar 2 son ./mainLab y nombreFichero en ese orden" << endl;
    cerr << "En el caso de pasar 4 son ./mainLab, alto, ancho y densidad en ese orden" << endl;
  }
}