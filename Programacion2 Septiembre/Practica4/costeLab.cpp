//Librerías y ficheros necesarios
#include "laberinto.hpp"

//Definición de constantes
const int M = 80;
const string nombreFichero = "tdens.txt";

//Guarda en el fichero los datos para imprimir por pantalla
void guardarResultado(double intermedio, double resultado) {
    
}

//Calcula el coste de ejecución de la función generarLaberinto
void calcularCoste(int dMin, int dMax, double step, int nrep) {
   ofstream fichero;
    fichero.open(nombreFichero);
    if(fichero.is_open()) {
        int i = 1;
        double resultado = 0;
        double intermedio = 0;
        bool encontrado = false;
        Laberinto lab;
        lab.ancho = M;
        lab.alto = M;
        double densidad = dMin;

        while (i != nrep) {
            encontrado = false;
            generarLaberinto(lab, densidad, M, M);
            lab.mapa[1][1] = LIBRE;
            lab.mapa[lab.alto - 2][lab.ancho - 2] = LIBRE;

            clock_t tiempoTotal = 0;
            clock_t tiempoInicial = clock();
            buscarCamino(lab, encontrado);
            clock_t tiempoFinal = clock();

                tiempoTotal = tiempoFinal - tiempoInicial;
                intermedio = dMin + (i - 1) * step;
                resultado += (1000000/CLOCKS_PER_SEC * double(tiempoTotal)) / nrep;
                fichero << intermedio << "\t" << resultado << endl;               

            i++;
        }
        fichero.close();
    }
    else {
        cerr << "No se ha podido abrir el fichero correctamente" << endl;
    }
    system("gnuplot -e \"set terminal gif; set xlabel 'densidad'; set ylabel 'T[ms]';"
            "set style data lines; plot 'tdens.txt'\" > tdens.gif");
}


int main() {
    calcularCoste(0.1, 0.42, 0.01, 100);
    return 0;
}