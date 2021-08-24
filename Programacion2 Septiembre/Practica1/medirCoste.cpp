/*
 * Programa que al que al ser invocado deberán aportarse tres parámetros en la línea de órdenes: el número de datos al generar y los valores mínimo y máximo de dichos
 * datos.
 * Al lanzar su ejecución, el programa generará una secuencia del número de datos a generar dado, comprendidos en el intervalo dado. Después de generar dichos datos
 * mostrará por pantalla los 20 primeros y los 20 últimos datos de dicha secuencia e informará que está procediendo a su ordenación (de menor a mayor valor). Tras
 * haber concluido la ordenación de la secuencia, mostrará de nuevo los 20 primeros y los 20 últimos datos (que deberían salir ahora ordenados). Por último informará
 * del tiempo de CPU invertido en dicha ordenación.
*/

#include "ordenar.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * Pre: a <= b
 * Post: devuelve un número aleatorio del intervalo entero[a,b]
*/
int randInt(const int a, const int b) {
    return a + rand() % (b - a + 1);
}

/*
 *Pre: 1 <=n AND d <= h AND (h - d) <= RAND_MAX
 *Post: El vector v[0,n-1] almacena n datos del intervalo [d,h] generados de modo
 *      pseudoaleatorio. Haciendo uso de la función randInt(a,b) especificada e
 *      implementada más arriba.
*/
void generar(int v[], const int numComponentes, const int minimo, const int maximo) {
    time_t semilla = time(nullptr);
    srand(semilla);

    for (int i = 0; i < numComponentes; i++) {
        v[i] = randInt(minimo, maximo);
    }
}

/*
 * Pre: --
 * Post: Presenta por pantalla los 20 primeros dígitos del vector
 *       y los 20 últimos
*/
void escribirDigitos(int v[], const int numComponentes) {
    unsigned int numeroColumnas = 0;

    for(unsigned int i = 0; i < 20; i++) {
        cout << setw(5) << v[i] << setw(5);
        numeroColumnas++;
        if (numeroColumnas == 10) {
            cout << endl;
            numeroColumnas = 0;
        }
    }
    cout << endl << "                     ..." << endl << endl;
    
    numeroColumnas = 0;
    for (unsigned int i = numComponentes - 20; i < numComponentes; i++) {
        cout << setw(5) << v[i] << setw(5);
        numeroColumnas++;
        if (numeroColumnas == 10) {
            cout << endl;
            numeroColumnas = 0;
        }
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    int numComponentes = atoi(argv[1]);
    int minimo = atoi(argv[2]);
    int maximo = atoi(argv[3]);
    int vector[numComponentes] = {0};

    generar(vector, numComponentes, minimo, maximo);
    cout << "Datos a ordenar: " << endl;
    escribirDigitos(vector, numComponentes);
    cout << endl << "Ordenando " << numComponentes << " datos enteros  ..." << endl << endl;

    clock_t tiempoInicial = clock();

    ordenar(vector, numComponentes);

    clock_t tiempoFinal = clock();
    float tiempoTranscurrido = float(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC;

    cout << endl << endl;
    cout << "Datos ordenados: " << endl;
    escribirDigitos(vector, numComponentes);
    cout << endl << endl;
    cout << "Tiempo de CPU para ordenar " << numComponentes << " enteros: " << tiempoTranscurrido << " segundos" << endl << endl;

    return 0;
}

