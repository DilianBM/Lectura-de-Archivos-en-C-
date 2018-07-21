/*Dilian Badilla
  clase Archivo
  versión 1
  esta clase de leer el archivo y con base en este sacar las estadisticas por columnas y luego guarda estas en un txt
*/
#include "Archivo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;
ifstream Archivo::archivoentradatexto;
ofstream Archivo::archivosalidatexto;
/*
apertura del archivo en modo de entrada
*/
void Archivo::openToReadASCII()
{
    archivoentradatexto.open("paises.csv");
    //archivoentradatexto.open("prod.csv");
}

void Archivo::closeOutfileASCII()
{
    archivoentradatexto.close();
}
/*
lee el archivo  linea por linea y lo mete en un vector de vectores no recibe ni retorna nada
*/
void Archivo::readASCIIRecord()
{
    if (archivoentradatexto)
    {
        string entrada;
        std::vector<string> ni;
        string entra;
        int cont=0;
        while(getline(archivoentradatexto, entrada))
        {
           char k=*entrada.rbegin();
            if (k==',')
                entrada+=" ";
            istringstream ss(entrada);
            while( (getline(ss, entra, ',') ))      //se tokeniza mediante comas
            {
                ni.push_back(entra);
            }
            vector2.push_back(ni);
            ni.clear();
        }
    }
    else
    {
        cout << "File not open for reading!" << endl;
    }

}
/*
este metodo recibe como parametro un indice que indica la columna a la cual se le calculara estadisticas
y retorna estas estadisticas en una string
*/
string Archivo::sacaestadisticas(int indice)
{

    double prom=0;
    double mencolun;
    double maycolun=atof(vector2[2][indice].c_str());
    if(vector2[2][indice]!=" " && vector2[2][indice]!="" ){
    mencolun=atof(vector2[2][indice].c_str());}
    stringstream os;
    double probabilidad=0;
    double desviacionEstandar=0;
    double resultado=0;
    int contador=0;
    string cadena="";
    string palabra="";
    for(int i=2; i<vector2.size(); i++)
    {
        if(vector2[i][indice]!=" " &&vector2[1][indice]=="2" &&vector2[i][indice]!="")//este if omite los vacios
        {
            prom+= atof(vector2[i][indice].c_str());
            contador++;//este contador nos permite saber cuantos elementos tiene la columna sin los valores omisos
            if(maycolun<atof(vector2[i][indice].c_str()))
            {
                maycolun=atof(vector2[i][indice].c_str());

            }
            if(mencolun>atof(vector2[i][indice].c_str()))
            {
                mencolun=atof(vector2[i][indice].c_str());
            }

        }
        else
        {

            if(vector2[i][indice]!=" " && vector2[1][indice]=="1" && vector2[i][indice]!="")
            {
                vector<string> v;
                for(int i=2; i<vector2.size(); i++)
                {
                    if(vector2[i][indice]!="" && vector2[i][indice]!=" ")
                    {
                        v.push_back(vector2[i][indice]);
                    }

                }
                for(int i=0; i<v.size(); i++)
                {
                    string temp=v[i];
                    for(int j = 0; j < temp.length(); j++)
                    {
                        temp[j] = tolower(temp[j]);
                    }
                    v[i]=temp;

                }
                for(int i=0; i<v.size(); i++)
                {
                    for(int j=i+1; j<v.size(); j++)
                    {
                        if(v[i]==v[j])
                        {

                            v[j]="";
                        }
                    }


                }
                int cont=0;
                for(int i=0; i<v.size(); i++)
                {
                    if(v[i]!="")
                    {
                        cont++;

                    }

                }
                stringstream stream;
                stream << cont;
                palabra = stream.str();


            }
        }

    }
    if(vector2[1][indice]=="1")
    {
        os<<palabra<<" distintos valores para esta columna "<<vector2[0][indice];
        os<<endl;
    }


    if(vector2[1][indice]=="2" )
    {
        resultado=prom/contador;
        for(int i=2; i<vector2.size(); i++)
        {
            if(vector2[i][indice]!=" "&& vector2[i][indice]!="")
            {
                probabilidad+=(atof(vector2[i][indice].c_str())-resultado)*(atof(vector2[i][indice].c_str())-resultado);
            }
        }
        probabilidad=probabilidad/contador;
        desviacionEstandar=sqrt(probabilidad);//calcula la desviacion estandar
        if(contador>0)
        {
            os<<vector2[0][indice]<<" Promedio: "<<setprecision(10)<<resultado<<" Valor Mayor: "<<maycolun<<" Valor Menor: "<<mencolun<<endl<< "Desviacion Estandar:"<<desviacionEstandar;
            os<<endl;
        }
    }


    cadena=os.str();
    return cadena;
}

/*
este metodo recorre las cantidad de colunas de la matriz donde estan los datos y llama al metodo  que calcula las estadisticas y
mete estas estadisticas en un vector y no recibe ni retorna nada
*/
void Archivo::meteEstadisticas()
{
    string h="";
    for(int i=0; i<vector2[0].size(); i++)
    {
        h=sacaestadisticas(i);
        vect.push_back(h);


    }

}
/*
este metodo no recibe ni retorna nada, recorre el vector donde se guardaron las estadisticas y las guarda en el
archivo de salida
*/
void Archivo::guardaArchivoSalida()
{
    if (archivosalidatexto)
    {
        for(int i=0; i<vect.size(); i++)
        {
            archivosalidatexto << vect[i] << endl;
            archivosalidatexto << endl;
        }

    }
    else
    {
        cout << "ASCII file not open for writing!" << endl;
    }
}
void Archivo::openarchivosalida()
{
    archivosalidatexto.open("Datos-Estadisticos.txt");
}
void Archivo::closearchivosalida()
{
    archivosalidatexto.close();
}
/*
no recibe ni retorna nada y muestra todos los datos estadisticos del archivo leido
*/
void Archivo::muestraDatos()
{
    cout<<"--------Datos Estadisticos--------"<<endl;

    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<endl;

    }

}

