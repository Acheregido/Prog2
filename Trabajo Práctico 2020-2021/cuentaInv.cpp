//***************************************************************************
// File:   cuentaInv.cpp
// Author: Acher Egido Mairal
// Date:   mayo-junio 2021
// Coms:   Implementación de las funciones contarInvsFB y contarInvsDC,
//         para el trabajo práctico de programación 2
//***************************************************************************

#include "cuentaInv.hpp"
    
    
// Porgrama que calcula el número de inversiones en un vector de enteros utilizando la estrategia de fuerza bruta
int contarInvsFB(int v[], int n){  
    int contadorInv = 0;                    // contador = 0
    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {   // comparo cada elemento del vector con el resto de elementos
            if (v[i] > v[j]) {              // si el elemento es mayor que alguno de los siguientes aumento el contador
                contadorInv++;
            }
        }
    }
    return contadorInv;
}



// función que calcula el número de inversiones resultado de la mezcla de ambas partes.
int contadorDv(int v[], int p, int mid, int f) {
    int contador = 0; 
    int b[f - 1];           // vector auxiliar
    int i = p;              // i = p
    int j = mid + 1;        // j = mid + 1
    int lastITR = 0;        // variable que utilizo para calcular las iteraciones

    while (i <= mid && j <= f) {      // mezcla hasta recorrer una parte
        if (v[i] <= v[j]) {           // si la componente es menor o igual, no hay inversión por lo tanto paso al siguiente elemento y no incremento el contador
            b[lastITR] = v[i];        // almacena los elementos ya ordenados en el vector auxiliar
            i++;
            lastITR++;
        }
        else {
            b[lastITR] = v[j];        // si es mayor contador y siguiente elemento
            j++;
            lastITR++;
            contador += mid - i + 1;
        }
    }
    return contador;
}

// Voy a usar un método de ordenación por mezcla para calcular el numero de inversiones que hay en el vector.
int contadorInvsDv(int v[], int p, int f) {
    int x = 0, y = 0, z = 0, mid = 0;
    if (p < f) {                                // Hay más de un elemento
        mid = (p + f) / 2;                      // Divido en subproblemas
        x = contadorInvsDv(v, p, mid);          // x = número de inversiones que hay en la mitad izquierda del vector
        y = contadorInvsDv(v, mid + 1, f);      // y = número de inversiones que hay en la mitad derecha del vector
        z = contadorDv (v, p, mid, f);          // z = mezclo ambas partes
        return x+y+z;                           // devuelvo el número total de inversiones
    }
    else {
        return 0;
    }
}


// Porgrama que calcula el número de inversiones en un vector de enteros, usando la estrategia de divide y vencerás
int contarInvsDC(int v[], int n) {
    int contador = 0;                           // contador inicial igual a 0
    contador = contadorInvsDv(v, 0, n-1);       // contador = número de inversiones que hay en el vector
    return contador;
}

