#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::sort
#include "estructuras.h"

using namespace std;

/*
int particion(vector<pair<string,int>> A,int p,int r){
    int pivot=stoi(A[r].first);
    int i=(p-1);
    for(int j=p;j<=r-1;j++){
        if(stoi(A[j].first)<=pivot){
            i++;
            swap(A[i].first,A[j].first);
            swap(A[i].second,A[j].second);
        }
    }
    swap(A[i+1].first,A[r].first);
    swap(A[i+1].second,A[r].second);
    return (i+1);
}
void quicksort(vector<pair<string,int>> &A,int p,int r){
    int q;
    if(p<r){
        q=particion(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
*/
/*void quicksort(vector<pair<string,int>> str,int p ,int r){
    int i=p,j=r;
    int mid=str[(p+r)/2].first;
    while(i<=j){
        while(str[i].first<mid)
            i++;
        while(str[j].first>mid)
            j--;
        if(i<=j){
            swap(str[i].first,str[j].first);
            swap(str[i].second,str[j].second);
            i++;j--;
        }
    };
    if(p<j){
        quicksort(str,p,j);
    }
    if(i<r){
        quicksort(str,i,r);
    }
}
*/


void indexar_tabla(string nombre_archivo,int numero_columna)
{
    ifstream is (nombre_archivo, std::ifstream::binary);
    ofstream ind("machine_attributes/part-00000-of-00001_ordenado.txt",ios::out | ios::binary);
      if (is) {
        //long int i=0;
        long int j=0;
        char * buffer = new char [200];
        long int posicion;
        vector<pair<string,int>> index;
        while(!is.eof())
        {
            for(int i=1;i<=numero_columna;i++){
                if(i==1)
                    posicion=is.tellg();

                is.getline(buffer,200,',');
                if(i==numero_columna)
                {
                    index.push_back(make_pair(buffer,posicion));                    
                    is.getline(buffer,200);
                    j++;
                }
            }
        }
        sort(index.begin(),index.end());
        //radix_sort(index);
        for(unsigned long long int i=0;i<index.size()-1;i++){
            ind<<index[i].first<<","<<index[i].second<<endl;
            
        }
        
        delete[] buffer;
        ind.close();
        is.close();
    }
}


int main(int argc, char *argv[])
{

    string nombre="machine_attributes/part-00000-of-00001.csv";
    indexar_tabla(nombre,2);

}
