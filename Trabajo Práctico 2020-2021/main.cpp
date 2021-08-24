//***************************************************************************
// File:   main.cpp
// Author: Acher Egido Mairal
// Date:   mayo-junio 2021
// Coms:   main para el trabajo práctico de programación 2
//***************************************************************************

#include "cuentaInv.hpp"

int main() {
    ofstream ficheroFB;
    ficheroFB.open("tnumifb.txt");
    if(ficheroFB.is_open()) {
        int a = minN; // Tamaño mínimo del vector (100)
        int b = maxN; // Tamaño máximo del vector (1000)  
        float resul = 0;
        while (a <= b) {    
            int v[a];                            // Este while me creará el fichero para el programa de fuerza bruta, y luego haré otro para el divide y vencerás
            time_t semilla = time(nullptr);             // Creo la semilla
            srand(semilla);                                                
            for (unsigned int i = 0; i <= a - 1; i++) { // Bucle que me genera el vector aleatorio
                v[i] = 1 + rand() % 10000 - 1 + 1;      // Pongo 10.000 como valor máximo de los números aleatorios y 1 como el valor mínimo.
            }
            clock_t t_total = 0;
            clock_t t_final;
            clock_t t_inicio = clock();
            contarInvsFB(v, a);
            t_final = clock();
            t_total = t_final - t_inicio;  
            resul = float(t_total) /  CLOCKS_PER_SEC;
            ficheroFB << a << "\t" << resul << endl;;
            a = a + stepN;
        }
        ficheroFB.close();
    }

    else {
        cerr << "No se ha podido abrir el fichero";
    }
    // Fichero para el programa resuleto mediante la estrategia de divide y vencerás
    ofstream ficheroDC;
    ficheroDC.open("tnumidv.txt");
    if(ficheroDC.is_open()) {
        int a = minN; // Tamaño mínimo del vector (100)
        int b = maxN; // Tamaño máximo del vector (1000)
        double resul = 0;
        // hago el while que genera el vector aleatorio del programa de divide y vencerá
        while (a <= b) {     
            int v[a];                         
            time_t semilla = time(nullptr);             // Creo la semilla
            srand(semilla);                                                    
            for (unsigned int i = 0; i <= a - 1; i++) { // Bucle que me genera el vector aleatorio
                v[i] = 1 + rand() % 10000 - 1 + 1;      // Pongo 10.000 como valor máximo de los números aleatorios y 1 como el valor mínimo.
            }
            clock_t t_total = 0;
            clock_t t_final;
            clock_t t_inicio = clock();
            contarInvsDC(v, a);
            t_final = clock();
            t_total = t_final - t_inicio;  
            resul = (double(t_total) /  CLOCKS_PER_SEC);
            ficheroDC << a << "\t" << resul << endl;;
            a = a + stepN;
            }
        ficheroDC.close();
    }
    else {
        cerr << "No se ha podido abrir el fichero";
    }
    system("gnuplot plot_datos_t.plot");
}