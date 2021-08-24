// código fuente para probar la isntalación de gnuplot en tu sistema
// XXX ¡OJO! Se requiere que el fichero "tnumifb.txt", "tnumidv.txt" y 
// el fichero "plot_datos_t.plot" estén al mismo nivel 
// (en el mismo directorio de trabajo) que el fichero compilado
#include <iostream>
using namespace std;

int main(){
    system("gnuplot plot_datos_t.plot");
    cout << "Si has visto un par de ventanas nuevas con dos gráficas, ¡está todo correcto!" << endl;

    return 0;
}
