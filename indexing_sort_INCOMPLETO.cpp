#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::sort
#include "estructuras.h"

using namespace std;




void indexar_tabla(char* nombre_archivo,int numero_columna)
{
    ifstream is (nombre_archivo, std::ifstream::binary);
    ofstream ind("machine_attributes/part-00000-of-00001_ordenado.txt",ios::out | ios::binary);
      if (is) {
        //long int i=0;
        long int j=0;
        char * buffer = new char [50];
        long int posicion;
        vector<pair<string,int>> index;
        while(!is.eof())
        {
            for(int i=1;i<=numero_columna;i++){
                if(i==1)
                    posicion=is.tellg();

                is.getline(buffer,50,',');
                if(i==numero_columna)
                {
                    index.push_back(make_pair(buffer,posicion));                    
                    is.getline(buffer,1000);
                    j++;
                }
            }
        }
        //sort (index.begin(), index.end(),index);
        for(unsigned long long int i=0;i<index.size();i++){
            ind<<index[i].first<<","<<index[i].second<<endl;
        }
        
        delete[] buffer;
        ind.close();
        is.close();
    }
}


int main(int argc, char *argv[])
{

    char* nombre="machine_attributes/part-00000-of-00001.csv";
    indexar_tabla(nombre,2);

}
