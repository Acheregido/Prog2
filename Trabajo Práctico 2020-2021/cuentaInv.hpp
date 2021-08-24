//*****************************************************************
// File:   cuentaInv.hpp
// Author: Acher Egido Mairal
// Date:   mayo-junio 2021
// Coms:   Fichero de interfaz de cuentaInv.cpp
//         Para el trabajo obligatorio de Programación 2
//*****************************************************************

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

// Tamaños de vector en los que calcular el número de inversiones
const int minN = 100; // Mínimo tamaño del vector
const int maxN = 10000; // Máximo tamaño del vector
const int stepN = 100; // Incremento 


// Pre: 100 ≤ n ≤ 10000 
// Post: contarInvsFB(v, n) = ∑ λ ∊ [0,n]. ∑ μ ∊ [λ+1,n]. v[λ] > v[μ]
int contarInvsFB(int v[], int n);


// Pre: 100 ≤ n ≤ 10000 
// Post: contarInvsDC(v, n) = ∑ λ ∊ [0,n]. ∑ μ ∊ [λ+1,n]. v[λ] > v[μ]
int contarInvsDC(int v[], int n);
