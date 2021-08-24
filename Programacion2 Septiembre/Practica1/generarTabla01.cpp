#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/*
 * Pre: d <= h
 * Post: Devuelve un número aleatorio del intervalo entero[d,h]
*/
int randInt(const int d, const int h) {
    return d + rand() % (h - d + 1);
}

// Pre: 1 <= n AND d <= h AND ( h - d ) <= R A N D _ M A X
// Post: El vector v[0,n-1] almacena n datos del intervalo [d,h] generados de modo pseudoaleatorio
void generar(int v[], const int n, const int d, const int h) {
    time_t semilla = time(nullptr);
    srand(semilla);

    for (int i = 0; i < n; i++) {
        v[i] = randInt(d, h);
    }
}

/*
 * Pre: --
 * Post: Imprime en una tabla en 10 columnas los valores del vector v
*/
void escribirTabla (int v[], const int numComponentes) {
    unsigned int numeroColumnas = 0;

    for (unsigned int i = 0; i < numComponentes; i++) {
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
    int numComponenetes = atoi(argv[1]);
    int minimo = atoi(argv[2]);
    int maximo = atoi(argv[3]);

    int vector[numComponenetes] = {0};

    generar(vector, numComponenetes, minimo, maximo); //Genero los números y los guardo en el vector

    escribirTabla(vector, numComponenetes);

    return 0;
}
