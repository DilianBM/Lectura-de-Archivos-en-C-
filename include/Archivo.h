#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;

class Archivo
{
public:
    Archivo() {}
    virtual ~Archivo() {}
    static void openToReadASCII();
    static void closeOutfileASCII();
    void readASCIIRecord();
    string sacaestadisticas(int);
    void meteEstadisticas();
    void cuentadistintos(int);
    void guardaArchivoSalida();
    void openarchivosalida();
    void closearchivosalida();
    void muestraDatos();

    static ifstream archivoentradatexto;
    static ofstream archivosalidatexto;
    vector< vector<string> > vector2;
    vector<string> vect;

protected:

private:
};


#endif // ARCHIVO_H
