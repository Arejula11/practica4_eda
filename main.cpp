/* Pablo Ernesto Angusto Delgado 842255 y  Miguel Aréjula Aisa 850068
*/

#include <iostream>
#include <fstream>
#include "multi.hpp"

using namespace std;

/* Programa de prueba del módulo Multi.hpp que crea un multiconjunto vacío de strings y luego lee un fichero "entrada.txt" 
 * con operaciones a realizar con ese multiconjunto, indicadas con la siguiente sintaxis, y escribe en un fichero "salida.txt" 
 * lo indicado según cada opción:
 * A -> añade un ejemplar del string incluido en la siguiente línea y escribe en salida "AÑADIDO string"
 * Q -> quita (si existe) un ejemplar del string incluido en la siguiente línea y escribe en salida "QUITADO string"
 *      o "NO QUITADO string", según corresponda
 * M -> escribe en salida la multiplicidad (M) del string incluido en la siguiente línea (0, si no existe) con la
 *      sintaxis: MULTIPLICIDAD DE string = M
 * L -> escribe en salida todos los elementos distintos del multiconjunto (sea C el cardinal), uno por línea y con formato:
 *      "string M" (donde M es la multiplicidad de ese string),   
 *      precedidos por una primera línea con "--- CARDINAL = C", y finalizando con una línea con "---". 
 * */

int main() {
    Multi<string> multiconjcad;
    
	// AQUÍ FALTA COMPLETAR CÓDIGO
    
    ifstream inf;
	inf.open("entrada.txt");
	ofstream outf;
	outf.open("salida.txt");
    
    string instruccion;
	string salto;
    string separador = "---";
    
    while (inf >> instruccion) {
        getline(inf, salto); //leer salto de linea
        if (instruccion == "A") {
            string elemento;
            getline(inf,elemento);
			
			// AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << "AÑADIDO " << elemento << endl;
        } else if (instruccion == "Q") {
            string elemento;
            getline(inf,elemento);
            bool borrado;
			
			// AQUÍ FALTA COMPLETAR CÓDIGO (hágase lo más eficiente posible, teniendo
			// en cuenta que la operación cardinal tiene coste constante)
			
            if (borrado) {
                outf << "QUITADO " << elemento << endl;
            } else {
                outf << "NO QUITADO " << elemento << endl;
            }
        } else if (instruccion == "M") {
            string elemento;
            getline(inf,elemento);
			int multipli;
			
			// AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << "MULTIPLICIDAD DE " << elemento << " = " << multipli << endl;
			
        } else if (instruccion == "L") {
			int elcardinal;
			
			// AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << separador << " CARDINAL = " << elcardinal << endl;
			
            // AQUÍ FALTA COMPLETAR CÓDIGO
			
            outf << separador << endl;
        }
    }
    
    outf.close();
	inf.close();
    return 0;
}