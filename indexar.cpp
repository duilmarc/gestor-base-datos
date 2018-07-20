
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector> // estructura usada 
#include <algorithm> // usado para el ordenamiento
#include <math.h>
using namespace std;
// funcion encargada de leer el archivo .csv y pasarlo a un vector insertando cada indice como la posicion
// en un vector asignado.

bool levantar_registros(int n_archivo, string archivo_entrada,vector<pair<long int,pair<long int,int>>>* index,int numero_columna)
{
    ifstream is (archivo_entrada, std::ifstream::binary);
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
                    index->push_back(make_pair(atol(buffer),make_pair(posicion,n_archivo)));
                    is.getline(buffer,200);
                }
            }
        }
        delete[] buffer;
        is.close();                                                 
    }
    else
    {
        return false;    
    }
    return true;
}

// Funcion encargada de dividir la cantidad total del vector en grupos de la cantidad deseada y agruparlos 
// en distintos archivos numerados en orden los cuales tienen una cabecera del elemento menor y 
// el elemento mayor en dicho archivo el cual tambien agrupa los indices repetidos en una sola fila, 
// solo añadiendo su posicion en el archivo.

unsigned long long int guardar_indices(string salida, int cantidad, vector<pair<long int,pair<long int,int>>> index,unsigned long long int iterador)
{
    long int contador=0;
    long int posicion; //  guarda la posicion para insertar los dos intervalos del grupo
    long int posicion2; // usado para guardar en otro archivo indices y posiciones que apuntan al archivo agrupado 
    if(cantidad ==-1)
    {
        cantidad=round(index.size()/10); // los divide el total en grupos de 10
    }
    unsigned long long int i = iterador;
    long int indice=-100000000000;
    ofstream ind(salida,std::ofstream::binary); // archvio que guarda los indices repetidos ,posiciones y archivo al cual pertenece
    ofstream ind2(salida+"_x",std::ofstream::binary); // archivo que guarda solo indices 
    ind<<index[i].first<<" ";
    posicion=ind.tellp();
    ind<<endl;
    ind<<"--------------------------------"<<endl;
    ind<<"--------------------------------"<<endl; // muestra los rangos de los indices 
    
    for(;i<index.size();i++){
        if(indice!=index[i].first)
        {
            ind<<','<<endl;
            posicion2=ind.tellp();
            indice=index[i].first;
            ind2<<indice<<","<<posicion2<<"|";
            ind<<indice<<","<<index[i].second.first<<"-"<<index[i].second.second;
            contador++;
        }
        else
        {
          ind<<","<<index[i].second.first<<"-"<<index[i].second.second;
        }
        if(contador>cantidad)
        {
            break;
        }
    }
    ind.seekp(posicion);
    ind<<index[i-1].first<<endl;
    cout<<"contador de registros anotados-> "<<contador<<endl;
    ind.close();
    ind2.close();
    return i;
}
// Funcion encargada de procesar nombres del archivo csv y dar como resultados sus indices
void indexar_csv(int numero_columna,string parte1, string salida1,int cantidad,int cantidad_archivos)
{  
    string parte3;
    if(cantidad_archivos<10)
        {
           parte3="-of-0000"+to_string(cantidad_archivos)+".csv";
        }
    else if(cantidad_archivos<100)
        {
           parte3="-of-000"+to_string(cantidad_archivos)+".csv";
        }
    else
        {
           parte3="-of-00"+to_string(cantidad_archivos)+".csv";
        }
    
    string parte2="";
    string entrada;
    
    vector<pair<long int,pair<long int,int>>> index; // crea un vector de una pareja de (indice, posicion , n_archivo)
    vector<pair<long int,pair<long int,int>>> *p_index= &index; // crea un apuntador a ese vector;

    for(int i=0;i<cantidad_archivos;i++)
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
        entrada=parte1+parte2+parte3; // asgina el nombre del archivo
        if(levantar_registros(i,entrada,p_index,numero_columna))
            cout<<endl<<parte2<<endl;
        else
            cout<<endl<<"error"<<endl;
    }
    sort(index.begin(),index.end());
    cout<<endl<<"total de valores encontrados->"<<index.size()<<endl;
    unsigned long long int iterador=0;
    string salida2,salida;
    for(int j=1;iterador<index.size();j++)
    {
        salida2="indice"+to_string(j);
        salida=salida1+salida2;
        iterador=guardar_indices(salida,cantidad,index,iterador);
    }   
}

// funcion encargada de crear un archivo con los intervalos para optimizar la busqueda de archivos

void crear_intervalos(string direccion)
{
    int i=1;
    string archivo_entrada;
    vector<pair<long int,long int>>intervalos;
    vector<int>n_archivo;
    char *intervalo1= new char[50];
    char *intervalo2= new char[50];
    while(true)
    {
        archivo_entrada=direccion+"indice"+to_string(i);
        cout<<archivo_entrada<<endl;
        ifstream ind(archivo_entrada, std::ifstream::binary);
        if(ind)
        {
            ind.getline(intervalo1,50,' ');
            ind.getline(intervalo2,50,'-');
            intervalos.push_back(make_pair(atol(intervalo1),atol(intervalo2)));
            n_archivo.push_back(i);
            ind.close();
        }
        else
            break;
        i++;
    }
    string archivo_salida=direccion+"intervalos";
    ofstream od(archivo_salida,std::ofstream::binary);
    for(int i=0 ; i< intervalos.size();i++)
    {
        if(i==intervalos.size()-1)
        {
           od<<intervalos[i].first<<"-"<<intervalos[i].second<<"-"<<n_archivo[i]; 
        }
        else
            od<<intervalos[i].first<<"-"<<intervalos[i].second<<"-"<<n_archivo[i]<<endl;
    }
    od.close();

}

void indexar_machine_atributes(int numero_columna,int cantidad, int n_csv)
{
    string entrada="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_attributes/part-00";
    string salida1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_attributes/";
    indexar_csv(numero_columna,entrada,salida1,cantidad,n_csv); 
    crear_intervalos(salida1);   
}
void indexar_machine_events(int numero_columna,int cantidad,int n_csv)
{
    string entrada="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_events/part-00";
    string salida1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/machine_events/";    
    indexar_csv(numero_columna,entrada,salida1,cantidad,n_csv); 
    crear_intervalos(salida1);
}

void indexar_task_events(int numero_columna,int cantidad, int n_csv)
{
    string parte1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_events/part-00";
    string salida1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_events/";
    indexar_csv(numero_columna,parte1,salida1,cantidad,n_csv);
    crear_intervalos(salida1);
}
void indexar_task_constraints(int numero_columna,int cantidad, int n_csv){
    string parte1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_constraints/part-00";
    string salida1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_constraints/";
    indexar_csv(numero_columna,parte1,salida1,cantidad,n_csv);
    crear_intervalos(salida1);
}
void indexar_task_usage(int numero_columna, int cantidad, int n_csv){
    string parte1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_usage/part-00";
    string salida1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/task_usage/";
    indexar_csv(numero_columna,parte1,salida1,cantidad,n_csv);
    crear_intervalos(salida1);
}
void indexar_job_events(int numero_columna,int cantidad, int n_csv)
{
    string parte1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/job_events/part-00";
    string salida1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/job_events/";
    indexar_csv(numero_columna,parte1,salida1,cantidad,n_csv);
    crear_intervalos(salida1);
}



int main()
{

   indexar_machine_events(2,-1,1);
    indexar_machine_atributes(2,-1,1);
   indexar_task_events(3,100000,500);
    indexar_job_events(3,100000,500);
    indexar_task_constraints(1,1000000,500);
    indexar_task_usage(5,1000000,500);
    return 0;
}
