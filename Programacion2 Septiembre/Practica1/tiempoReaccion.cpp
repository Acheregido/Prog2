#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

//Programa que pide pulsar un cierto número de veces la tecla de fin de línea y que informa del tiempo transcurrido en cada una (entre la aparición del mensaje y el momento en 
// el cual el usuario pulsa la tecla).

void medirTiempo(unsigned int i) {
    cout << i << ") Pulse la tecla de fin de línea, por favor ..." << endl;
    clock_t t1 = clock();
    getch();
    clock_t t2 = clock();
    float tiempo = (t2-t1) / CLOCKS_PER_SEC;
    cout << "Su tiempo de reacción ha sido de " << tiempo << "segundos" << endl;
}

int main (int argc, char* argv[]) {
    int it = 0;
    if (argc > 1) {
        it = atoi(argv[1]); //Tengo que usar el atoi, para pasar el argv a entero, porque de normal es una cadena de caracteres.
    }
    else {
        it = 1;
    }
    for (unsigned int i = 1; i <= it; i++) {
        medirTiempo(i);
    }
    return 0;
} 

