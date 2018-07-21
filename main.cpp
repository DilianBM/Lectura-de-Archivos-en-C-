/*Dilian Badilla
  clase main
  versión 1
  esta clase es la encargada de  llamar a todos los metodos encargados de la lectura,sacar probas y escritura de archivos
*/
#include <iostream>
#include "Archivo.h"
using namespace std;

int main()
{
    Archivo prueba;
    prueba.openToReadASCII();
    prueba.readASCIIRecord();
    prueba.meteEstadisticas();
    prueba.closeOutfileASCII();

    prueba.openarchivosalida();
    prueba.guardaArchivoSalida();
    prueba.muestraDatos();
    prueba.closearchivosalida();



    return 0;
}
