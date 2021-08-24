//*****************************************************************
// File:   pruebas01.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2021
// Coms:   Programa de pruebas del comportamiento de las funciones
//         definidas en el módulo calculos
//         Para la práctica 2
//*****************************************************************

#include <iostream>
#include "calculos.hpp"

using namespace std;


// Pre:  <cifra> es el número de cifras de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar numCifras(n, b) es igual
//       a <cifras> o no lo es
void probarNumCifras(const int n, const int b, const int cifras) {
    int r = numCifras(n, b);
    if (r == cifras) {
        cout << "Ok. numCifras(" << n << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. numCifras(" << n << "," << b << ") = " << r << "  pero debiera ser "
             << cifras << endl;
    }
}


// Prueba el comportamiento de numCifras(n,10) para los siguientes valores de n:
// 0, 1, 9, 10, 99, 100, 999, 1000, ... , 99999, 100000, 99999 y 1000000
// y prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
// 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
void probarNumCifras() {
    // Prueba el comportamiento de numCifras(n) para los siguientes valores de n:
    // 0, 1, 9, 10, 99, 100, 999, 1000, ..., 99999, 100000, 99999 y 1000000
    probarNumCifras(0, 10, 1);
    probarNumCifras(1, 10, 1);
    int n = 10;
    int cifras = 2;
    while (n <= 1000000) {
        probarNumCifras(n - 1, 10, cifras-1);
        probarNumCifras(n, 10, cifras);
        n = 10 * n;
        cifras = cifras + 1;
    }
    cout << endl;

}


// Pre:  <n> es el número natural y <b> está comprendido entre 2 y 10
// Post: Informa si los valores devueltos al ejecutar cifra(n, i, b) corresponden
//       o no a la i-ésima cifra de <n>, cuando este número se escribe en base <b>
void probarCifra(const int n, const int i, const int b, const int laCifra) {
    int cifraPrueba = cifra(n, i, b);

    if (cifraPrueba == laCifra) {
        cout << "Ok. cifra(" << n << "," << b << "," << i << ") = " << cifraPrueba << endl;
    }
    else {
        cout << "Mal. cifra(" << n << "," << b << "," <<  i << ") = " << cifraPrueba << "  pero debiera ser "
             << laCifra << endl;
    }
}


// Prueba el comportamiento de cifra(n,i,b) para diferentes números naturales
// en las bases de numeración 2 y 10
void probarCifra() {
    unsigned int cifras = 0;
    for (unsigned int i = 0; i < 100; i += 10) {
        probarCifra(i, 2, 10, cifras);
        cifras++;
    }

    cifras = 0;
    for (unsigned int i = 300; i < 400; i += 10) {
        probarCifra(i, 2, 10, cifras);
        cifras++;
    }

    cifras = 1;
    for (unsigned int i = 100; i < 1000; i += 100) {
        probarCifra(i, 3, 10, cifras);
        cifras++;
    }
}


// Pre:  <n> es el número natural y <b> está comprendido entre 2 y 10 y <laMayor> es
//       el valor de la mayor de las cifras de <n> cuando se escribe en base <b>
// Post: Informa si el valor devuelto al ejecutar cifraMayor(n, b) coincide con el
//       de <laMyor>, cuando <n> se escribe en base <b>
void probarCifraMayor(const int n, const int b, const int laMayor) {
    int mayorPrueba = cifraMayor(n,b);

    if (mayorPrueba == laMayor) {
        cout << "Ok. CifraMayor(" << n << "," << b << ") = " << mayorPrueba << endl;
    }
    else {
        cout << "Mal. CifraMayor(" << n << "," << b << ") = " << mayorPrueba << "  pero debiera ser "
             << laMayor << endl;
    }
}


// Prueba el comportamiento de cifraMayor(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMayor() {
    probarCifraMayor(0, 2, 1);
    probarCifraMayor(1, 2, 1);

    unsigned int mayorPrueba = 0;
    for (unsigned int i = 0; i < 100; i += 10) {
        probarCifraMayor(i, 10, mayorPrueba);
        mayorPrueba++;
    }

    mayorPrueba = 1;
    for (unsigned int i = 110; i < 200; i += 10) {
        probarCifraMayor(i, 10, mayorPrueba);
        mayorPrueba++;
    }

    mayorPrueba = 0;
    for (unsigned int i = 0; i <= 7; i++) {
        probarCifraMayor(i, 8, mayorPrueba);
        mayorPrueba++;
    }

    mayorPrueba = 4;
    for (unsigned int i = 30; i <= 33; i++) {
        probarCifraMayor(i, 8, 3);
    }
    for (unsigned int i = 34; i <= 37; i++) {
        probarCifraMayor(i, 8, mayorPrueba);
        mayorPrueba++;
    }
}


// Pre:  <n> es el número natural y <b> está comprendido entre 2 y 10 y <laMasSignificativa>
//       es el valor de cifra más significativa de <n> cuando se escribe en base <b>
// Post: Informa si el valor devuelto al ejecutar cifraMasSignificativa(n, b) coincide
//       con el de <laMasSignificativa>, cuando <n> se escribe en base <b>
void probarCifraMasSignificativa(const int n, const int b, const int laMasSignificativa) {
    int MasSignificativaPrueba = cifraMasSignificativa (n, b);

    if (MasSignificativaPrueba == laMasSignificativa) {
        cout << "Ok. cifraMasSignificativa(" << n << "," << b << ") = " << MasSignificativaPrueba << endl;
    }
    else {
        cout << "Mal. cifraMasSignificativa(" << n << "," << b << ") = " << MasSignificativaPrueba << "  pero debiera ser "
             << laMasSignificativa << endl;
    }
}


// Prueba el comportamiento de cifraMasSignificativa(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMasSignificativa() {
    probarCifraMasSignificativa(0, 2, 0);
    probarCifraMasSignificativa(1, 2, 1);
    probarCifraMasSignificativa(1001, 2, 1);
    probarCifraMasSignificativa(0110, 2, 0);
    
    unsigned int masPrueba = 0;
    for (unsigned int i = 0; i < 100; i += 10) {
        probarCifraMasSignificativa(i, 10, masPrueba);
        masPrueba++;
    }

    masPrueba = 0;
    for (unsigned int i = 0; i < 1000; i += 100) {
        probarCifraMasSignificativa(i, 10, masPrueba);
        masPrueba++;
    }

    masPrueba = 0;
    for (unsigned int i = 0; i <= 7; i++) {
        probarCifraMasSignificativa(i, 8, masPrueba);
        masPrueba++;
    }

    for(unsigned int i = 30; i <= 37; i++) {
        probarCifraMasSignificativa(i, 8, 3);
    }
}


// Pre:  <n> es el número natural y <b> está comprendido entre 2 y 10 y <laSuma> es
//       el valor de las cifras de <n> cuando se escribe en base <b>
// Post: Informa si el valor devuelto al ejecutar sumaCifras(n, b) coincide
//       con el de <laSuma>, cuando <n> se escribe en base <b>
void probarSumaCifras(const int n, const int b, const int laSuma) {
    int sumaPrueba = sumaCifras(n, b);

    if (sumaPrueba == laSuma) {
        cout << "Ok. sumaCifras(" << n << "," << b << ") = " << sumaPrueba << endl;
    }
    else {
        cout << "Mal. sumaCifras(" << n << "," << b << "i" << ") = " << sumaPrueba << "  pero debiera ser "
             << laSuma << endl;
    }
}

// Prueba el comportamiento de probarSumaCifras(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarSumaCifras() {
    probarSumaCifras(10, 2, 1);
    probarSumaCifras(000, 2, 0);
    probarSumaCifras(1111, 2, 1);

    int suma = 0;
    for (unsigned int i = 0; i < 10; i++) {
        probarSumaCifras(i, 10, suma);
        suma++;
    }
    suma = 1;
    for (unsigned int i = 100; i < 110; i++) {
        probarSumaCifras(i, 10, suma);
        suma++;
    }

    suma = 0;
    for (unsigned int i = 0; i <= 7; i++) {
        probarSumaCifras(i, 8, suma);
        suma++;
    }

    suma = 2;
    for (unsigned int i = 20; i <= 27; i++) {
        probarSumaCifras(i, 8, suma);
        suma++;
    }

    suma = 1;
    for (unsigned int i = 100; i <= 107; i++) {
        probarSumaCifras(i, 8, suma);
        suma++;
    }
}


// Ejecuta una secuencia de pruebas de las funciones definidas
// en el módulo cálculos
int main() {
    // Pruebas del comportamiento de numCifras(n,b)
    probarNumCifras();
    // Pruebas del comportamiento de cifra(n,i,)
    probarCifra();
    // Pruebas del comportamiento de cifraMayor(n,b)
    probarCifraMayor();
    // Pruebas del comportamiento de cifraMasSignificativa(n,b)
    probarCifraMasSignificativa();
    // Pruebas del comportamiento de sumaCifras(n,b)
    probarSumaCifras();
    // Fin del programa de pruebas
    return 0;
}
