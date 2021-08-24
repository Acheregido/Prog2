 /*
 * Programa que presenta por la pantalla, en 10 columnas, una secuencia de datos
 * reales generados de forma pseudoaleatoria. En la propia línea de órdenes de
 * invocación al programa se especificará el número de datos a generar y los valores
 * reales mínimo y máximo de los datos pseudoaleatorios generados
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/*
 * Pre: r <= s
 * Post: Devuelve un número aleatorio del intervalo real[r,s]
*/
double randDouble(const double r, const double s) {
    return (double(rand()) / RAND_MAX) * (s - r) + r;
}

/*
 * Pre: 1 <= n AND r <= s AND (s - r) <= RAND_MAX
 * Post: El vector v[0,n-1] almacena n datos del intervalo[r,s] generados de modo
 *       pseudoaleatorio
*/
void generar(double v[], const int n, const int r, const int s) {
    time_t semilla = time(nullptr);
    srand(semilla);

    for (int i = 0; i < n; i++) {
        v[i] = randDouble(r, s);
    }
}

/*
 * Pre: --
 * Post: Presenta por pantalla en una tabla de 10 columnas los valores del vector v
*/
void escribirTabla(double v[], const int numComponentes) {
    unsigned int numeroColumnas = 0;

    for (unsigned int i = 0; i < numComponentes; i++) {
        cout << setw(5) << setprecision(3) << v[i] << setw(5) << " ";
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
    double minimo = atof(argv[2]);
    double maximo = atof(argv[3]);

    double vector[numComponentes] = {0.0};

    generar(vector, numComponentes, minimo, maximo);

    escribirTabla(vector, numComponentes);

    return 0;
}
