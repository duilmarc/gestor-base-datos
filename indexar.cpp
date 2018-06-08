#include "mainwindow.h"
#include <QApplication>
#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;
typedef struct table{
    signed long int timestamp;
    signed long int machine_ID;
    char attribute_name[200] ;
    char attribute_value[200];
    bool attribte_deleted;
}   machi_attributes;



void indexar_tabla(char* nombre_archivo,int numero_columna)
{
    ifstream is (nombre_archivo, std::ifstream::binary);
    ofstream ind("/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_attributes/part-00000-of-00001.txt",std::ifstream::binary);
      if (is) {
        //long int i=0;
        long int j=0;
        char * buffer = new char [50];
        long int posicion;
        while(!is.eof())
        {
            for(int i=1;i<=numero_columna;i++){
                if(i==1)
                {
                    posicion=is.tellg();
                }
                is.getline(buffer,50,',');
                if(i==numero_columna)
                {
                    ind<<buffer<<","<<posicion<<endl;
                    is.getline(buffer,1000);
                    j++;
                }
            }
        }
        delete[] buffer;
        ind.close();
        is.close();
      }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    char* nombre="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_attributes/part-00000-of-00001.csv";
    indexar_tabla(nombre,2);

    return a.exec();
}
