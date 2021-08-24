//***************************************************************************
// File:   laberinto.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   March 26, 2021
// Coms:   Implementación del tipo "Laberinto" para la práctica 3 de la asignatura
//***************************************************************************

#include "laberinto.hpp"
#include <unistd.h>
#include <Windows.h>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>
#include <time.h>

//*************************************************************************
// Encontrar un camino en el laberinto
//*************************************************************************
//Función auxiliar
bool buscarCaminoAux(Laberinto& lab, int fila, int col) {
    if(fila == lab.alto - 2 && col == lab.ancho - 2) {
        lab.mapa[fila][col] = CAMINO;
        mostrarLaberinto(lab);
        return true;
    }
    else {
        if(fila >= 1 && col >= 1 && fila <= lab.alto - 2 && col <= lab.ancho - 2 && lab.mapa[fila][col] == LIBRE) {
            lab.mapa[fila][col] = CAMINO;
            mostrarLaberinto(lab);

            if(buscarCaminoAux(lab, fila - 1, col)) {
            return true;
            }
            if(buscarCaminoAux(lab, fila, col + 1)) {
            return true;
            }
            if(buscarCaminoAux(lab, fila + 1, col)) {
            return true;
            }
            if(buscarCaminoAux(lab, fila, col - 1)) {
            return true;
            }
            else{
                lab.mapa[fila][col] = IMPOSIBLE;
                mostrarLaberinto(lab);
                return false;
            }
        }
        return false;
    }
}
void buscarCamino(Laberinto& lab, bool& encontrado) {
    encontrado = buscarCaminoAux(lab, 1, 1);
}

//*************************************************************************
// Generar el laberinto
//*************************************************************************

void cargarLaberinto(const string nombFichero, Laberinto& lab) {
    unsigned int numCol = 0, numFil = 0;
    ifstream ficheroOrigen;
    ficheroOrigen.open(nombFichero);
    cout << endl;
    if (ficheroOrigen.is_open()) {
        string lineaLeida;
        while (!ficheroOrigen.eof()) {
            getline(ficheroOrigen, lineaLeida);

            for (unsigned int i = 0; i < lineaLeida.length(); i++) {
                lab.mapa[numFil][i] = lineaLeida[i];
            }
            if(numFil == 0) {
                numCol = lineaLeida.length();
            }
            numFil++;
        }
        lab.alto = numFil;
        lab.ancho = numCol;
    }
    else {
        cerr << "No ha sido posible abrir el fichero";
    }
    cout << endl;
}

/*
 * Función para generar el laberinto de manera aleatoria 
 * con una probabilidad de que haya un muro igual a densidad
 * y filas y columnas fila y col respectivamente
*/

//Forma recursiva
void generarLaberinto(Laberinto &lab, double densidad, int fila, int col) {

    if(fila != 0) {
        if(col != 0) {
            if(double(rand()) / RAND_MAX <= densidad) {
                lab.mapa[fila][col] = MURO;
            }
            else {
                lab.mapa[fila][col] = LIBRE;
            }
            generarLaberinto(lab, densidad, fila, col - 1);
        }
        else {
            generarLaberinto(lab, densidad, fila - 1, lab.ancho);
        }
    }
}

//*************************************************************************
// Visualizar el camino encontrado
//*************************************************************************

// Pre:   "lab" es un laberinto correcto
// Post:  Se ha mostrado el laberinto por la salida estándar
// Coms:  Versión iterativa
void mostrarLaberinto(const Laberinto& lab) {
    system("cls");
    for (int i = 0; i < lab.alto; i++) {
        for (int j = 0; j < lab.ancho; j++) {
            cout << lab.mapa[i][j];
        }
        // Al acabar una fila, se cambia de línea
        cout << endl;
    }
}


// Pre:  "lab" es un laberinto correcto
// Post:  Se ha mostrado el laberinto por la salida estándar
// Coms:  Versión recursiva
//Función auxiliar
void mostrarLaberintoAux(const Laberinto& lab, int fila, int col) {
    if(fila != lab.alto) {
        if(col != lab.ancho) {
            cout << lab.mapa[fila][col];
            mostrarLaberintoAux(lab, fila, col + 1);
        }
        else {
            cout << endl;
            mostrarLaberintoAux(lab, fila + 1, 0);
        }
    }
}
void mostrarLaberintoR(const Laberinto& lab) {
    system("cls");
    int fila = 0, col = 0;
    mostrarLaberintoAux(lab, fila, col);
    Sleep(1);
}