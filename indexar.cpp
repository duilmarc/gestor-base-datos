
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool indexar_tabla(string archivo_entrada,int numero_columna,string archivo_salida)
{
    long long int tam=0;
    ifstream is (archivo_entrada, std::ifstream::binary);
    ofstream ind(archivo_salida,std::ofstream::app);
      if (is) {
        char * buffer = new char [200];
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
                    ind.seekp(0,ind.end);
                    ind<<buffer<<","<<posicion<<endl;
                    is.getline(buffer,200);
                    tam++;
                }
            }
        }
        delete[] buffer;
        ind.close();
        is.close();
      }
    else
    {
        return false;    
    }
    cout<<tam;
    return true;
}

void indexar_machine_atributes(int numero_columna)
{
    string entrada="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_attributes/part-00000-of-00001.csv";
    string salida="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_attributes/indice.txt";
    if(indexar_tabla(entrada,numero_columna,salida))
        cout<<"indexacion exitosa";
    else
        cout<<"error durante la indexacion";
}

void indexar_machine_events(int numero_columna)
{
    string entrada="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_events/part-00000-of-00001.csv";
    string salida="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_events/indice.txt";
    if(indexar_tabla(entrada,numero_columna,salida))
        cout<<"indexacion exitosa";
    else
        cout<<"error durante la indexacion";
}

void indexar_task_events(int numero_columna)
{
    string parte1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_events/part-00";
    string parte3="-of-00500.csv";
    string parte2="";
    string entrada;
    string salida="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_events/indice.txt";
    for(int i=0;i<500;i++)
    {
        if(i<10)
        {
           parte2="00"+to_string(i);
        }
        else if(i<100)
        {
           parte2="0"+to_string(i);
        }
        else
        {
            parte2=to_string(i);
        }
        ofstream ind(salida,std::ofstream::app);
        cout<<"indexando parte "+parte2<<endl;
        ind<<"archivo"<<"-"<<parte2<<endl;
        ind.close();
        entrada=parte1+parte2+parte3;
        if(indexar_tabla(entrada,numero_columna,salida))
            cout<<endl<<"indexacion exitosa"<<endl;
        else
            cout<<endl<<"error durante la indexacion"<<endl;

    }
}

void indexar_task_constraints(int numero_columna)
{
    string parte1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_constraints/part-00";
    string parte3="-of-00500.csv";
    string parte2="";
    string entrada;
    string salida="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_constraints/indice.txt";
    for(int i=0;i<500;i++)
    {
        if(i<10)
        {
           parte2="00"+to_string(i);
        }
        else if(i<100)
        {
           parte2="0"+to_string(i);
        }
        else
        {
            parte2=to_string(i);
        }
        ofstream ind(salida,std::ofstream::app);
        cout<<"indexando parte "+parte2<<endl;
        ind<<"archivo"<<"-"<<parte2<<endl;
        ind.close();
        entrada=parte1+parte2+parte3;
        if(indexar_tabla(entrada,numero_columna,salida))
            cout<<endl<<"indexacion exitosa"<<endl;
        else
            cout<<endl<<"error durante la indexacion"<<endl;
    }
}

void indexar_task_usage(int numero_columna)
{
    string parte1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_usage/part-00";
    string parte3="-of-00500.csv";
    string parte2="";
    string entrada;
    string salida="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_usage/indice.txt";
    for(int i=0;i<500;i++)
    {
        if(i<10)
        {
           parte2="00"+to_string(i);
        }
        else if(i<100)
        {
           parte2="0"+to_string(i);
        }
        else
        {
            parte2=to_string(i);
        }
        ofstream ind(salida,std::ofstream::app);
        cout<<"indexando parte "+parte2<<endl;
        ind<<"archivo"<<"-"<<parte2<<endl;
        ind.close();
        entrada=parte1+parte2+parte3;
        if(indexar_tabla(entrada,numero_columna,salida))
            cout<<endl<<"indexacion exitosa"<<endl;
        else
            cout<<endl<<"error durante la indexacion"<<endl;
    }
}
void indexar_job_events(int numero_columna)
{
    string parte1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/job_events/part-00";
    string parte3="-of-00500.csv";
    string parte2="";
    string entrada;
    string salida="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/job_events/indice.txt";
    for(int i=0;i<500;i++)
    {
        if(i<10)
        {
           parte2="00"+to_string(i);
        }
        else if(i<100)
        {
           parte2="0"+to_string(i);
        }
        else
        {
            parte2=to_string(i);
        }
        ofstream ind(salida,std::ofstream::app);
        cout<<"indexando parte "+parte2<<endl;
        ind<<"archivo"<<"-"<<parte2<<endl;
        ind.close();
        entrada=parte1+parte2+parte3;
        if(indexar_tabla(entrada,numero_columna,salida))
            cout<<endl<<"indexacion exitosa"<<endl;
        else
            cout<<endl<<"error durante la indexacion"<<endl;
    }
}
int main(int argc, char *argv[])
{

    //indexar_machine_atributes(2);
    indexar_job_events(2);
    return 0;
}
