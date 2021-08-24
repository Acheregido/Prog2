#include <iostream>
#include <iomanip>
#include <string>
#include "pilaEnt.hpp"

//*****************************************************************
// File:   pilaEnt.hpp
// Author: Acher Egido Mairal
// Date:   febrero 2021
// Coms:   Fichero de interfaz de pilaEnt.cpp, para el manejo
//         de pilas de enteros
//         Para la práctica 2
//*****************************************************************

//  Notación empleada en la especificación de funciones:
//    p = [] la pila está vacía, es decir, almacena 0 datos
//    p = [d_1, d_2, ..., d_K] la pila almacena K datos. El más antiguo
//        es el dato d_1, el segundo más antiguo el dato d_2, etc., etc.,
//        y el más reciente es el dato d_K

// Pre:  ---
// Post: p = []
void vaciar(PilaEnt &p) {
    p.indice = 0;
}

// Pre:  p = [d_1, d_2, ..., d_K] ∧ K >= 0 ∧ K < DIM
// Post: p = [d_1, d_2, ..., d_K, nuevo]
void apilar(PilaEnt &p, const int nuevo) {
    p.pila[p.indice + 1] = nuevo;
    p.indice += 1;
}

// Pre:  p = [d_1, d_2, ...,d_(K-1), d_K] ∧ K > 0
// Post: p = [d_1, d_2, ..., d_(K-1)]
void desapilar(PilaEnt &p) {
    p.pila[p.indice - 1];
}

// Pre:  p = [d_1, d_2, ...,d_(K-1),d_K] ∧ K > 0
// Post: cima(p) = d_K
int cima(const PilaEnt &p) {
    return p.pila[p.indice];
}

// Pre: ---
// Post: estaVacia(p) = (p = [])
bool estaVacia(const PilaEnt &p) {
    return 0 == p.indice;
}

// * Pre: p = [d_1, d_2, ..., d_K]
// * Post: estaLlena(p) = (K = DIM])
bool estaLlena(const PilaEnt &p) {
    return DIM - 1 == p.indice;
}