#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "bloqueo.h"

using namespace std;
typedef unsigned long long int lli;
//typedef pair<vector<int>,pair<char,char>> transaccion;
//variable referenciar a indice
typedef string T;

void imprimir(vector<string> select){
	for(int i=0;i<select.size()-1;i++){
		cout<<select[i]<<endl;
	}
	cout<<"--------------------------"<<endl;
}

//Clase abstracta de la cual heredan las tablas de la BD
//esto se hace para que todas las demas tablas requieran implementar los siguientes 
//metodos , tales como inser,delete,update y select para sus respectivos campos
class tabla_maestra
{
public:
	tabla_maestra();
	//funcion que inserta al final de la BD de la tabla seleccionada creando un nuevo
    //archivo a menos que ya exista
	virtual bool insert(string);
	//funcion que pone los campos del indice elegido a NULL por defecto 
	virtual bool delet(T,string);
	//funcion que sustituye los campos del indice elegido por unos nuevos valores
	virtual bool update(T,string,string);
	//funcion qie busca y devuelve los campos del indice elegido
	virtual vector<string> select(T);

};


class job_events:public tabla_maestra
{
   
public:
    lli size=0;    
    string archivo;
    vector<int> orden;
    char state;
    char type;
    transaccion tr;
    job_events(string archivoX){
    	this->archivo=archivoX;
    	this->state='N';//G Granted /W Waiting /N None
    	this->type='S';//E Exclusive,S Shared
    	this->tr.first=orden;//orden de la transaccion
    	this->tr.second.first=state;//estado de la transaccion
    	this->tr.second.second=type;//tipo de la funcion ejecutada en la transaccion
    }

    bool insert(string datos){
    	this->type='E';
    	ofstream is("job_events/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    }
    bool delet(T,string){
    	this->type='E';
    }
    bool update(T,string,string){
    	this->type='E';
    }
   	vector<string> select(T){
   		this->type='S';
   	}

   	bool llenar_transaccion(){
   		int a=0;
    	cout<<"transaccion Menu:"<<endl;
    	cout<<"Insert 1:"<<endl;
    	cout<<"Delete 2:"<<endl;
    	cout<<"Update 3:"<<endl;
    	cout<<"Select 4:"<<endl;
    	cout<<"Exit 5:"<<endl;
    	//se inserta el orden de las operaciones en un array que se ejecutara simulando la transaccion
    	while(true){
    		cin>>a;
    		if(a==5){
    			cout<<"operacion completada: "<<endl;
    			break;
    		}
    		else{
    			orden.push_back(a);
    		}
    	}
   	}
    bool ejecutar_transaccion(){
    	string data;
    	string data2;
    	string data3;
    	//se ejecuta el array anterior mente llenado por las operaciones requeridas
    	for(int i=0;i<this->orden.size()-1;i++){
    		if(this->orden[i]==1){//INSERTAR
    			cout<<"Ingrese el elemento a insertar en la BD: ";cin>>data;
    			insert(data);
    			cout<<"Dato Insertado"<<endl;
    		}else if(this->orden[i]==2){//ELIMINAR
    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
    			delet(data,data2);
    			cout<<"Dato eliminado"<<endl;
    		}else if(this->orden[i]==3){//ACTUALIZAR
    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
    			update(data,data2,data3);
    			cout<<"Dato actualizado"<<endl;
    		}else if(this->orden[i]==4){//
    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
    			imprimir(select(data));
    		}
    	}
    }
};

class machine_attributes:public tabla_maestra
{
public:
	vector<int> orden;
	lli size=0;
	string archivo;
	char state;
	char type;
	transaccion tr;
	machine_attributes(string archivoX){
		this->archivo=archivoX;
    	this->state='N';//G Granted /W Waiting /N None
    	this->type='S';//E Exclusive,S Shared
    	this->tr.first=orden;//orden de la transaccion
    	this->tr.second.first=state;//estado de la transaccion
    	this->tr.second.second=type;//tipo de la funcion ejecutada en la transaccion
	}
    bool insert(string datos){
    	ofstream is("machine_attributes/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n"; size++;}
    
    }
    bool delet(T,string){
    	
    }

    bool update(T index,string valor,string datos){
    	fstream is("machine_attributes/"+this->archivo+".csv",fstream::in | fstream::out);
    	long int position=0;
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {
    		unsigned cont=0;
    		char *buffer= new char[200];
    		while(cont<stoi(index)){
    			is.getline(buffer,200);
    			cont++;
    		}

    		is<<datos<<"\n";
    		is.close();
    	}
    }
    vector<string> select(T index){
    }
   	bool llenar_transaccion(){
   		int a=0;
    	cout<<"transaccion Menu:"<<endl;
    	cout<<"Insert 1:"<<endl;
    	cout<<"Delete 2:"<<endl;
    	cout<<"Update 3:"<<endl;
    	cout<<"Select 4:"<<endl;
    	cout<<"Exit 5:"<<endl;
    	//se inserta el orden de las operaciones en un array que se ejecutara simulando la transaccion
    	while(true){
    		cin>>a;
    		if(a==5){
    			cout<<"operacion completada: "<<endl;
    			break;
    		}
    		else{
    			orden.push_back(a);
    		}
    	}
   	}
    bool ejecutar_transaccion(){
    	string data;
    	string data2;
    	string data3;
    	//se ejecuta el array anterior mente llenado por las operaciones requeridas
    	for(int i=0;i<this->orden.size()-1;i++){
    		if(this->orden[i]==1){//INSERTAR
    			cout<<"Ingrese el elemento a insertar en la BD: ";cin>>data;
    			insert(data);
    			cout<<"Dato Insertado"<<endl;
    		}else if(this->orden[i]==2){//ELIMINAR
    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
    			delet(data,data2);
    			cout<<"Dato eliminado"<<endl;
    		}else if(this->orden[i]==3){//ACTUALIZAR
    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
    			update(data,data2,data3);
    			cout<<"Dato actualizado"<<endl;
    		}else if(this->orden[i]==4){//
    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
    			imprimir(select(data));
    		}
    	}
    }    


};

class machine_events:public tabla_maestra
{
public:
	vector<int> orden;
	string archivo;
	char state;
	char type;
	transaccion tr;
	machine_events(string archivoX){
		this->archivo=archivoX;
    	this->state='N';//G Granted /W Waiting /N None
    	this->type='S';//E Exclusive,S Shared
    	this->tr.first=orden;//orden de la transaccion
    	this->tr.second.first=state;//estado de la transaccion
    	this->tr.second.second=type;//tipo de la funcion ejecutada en la transaccion
	}
    lli size=0;
    bool insert(string datos){
    	ofstream is("machine_events/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    }
    bool delet(T,string);
    bool update(T,string,string);
    vector<string> select(T);
   	bool llenar_transaccion(){
   		int a=0;
    	cout<<"transaccion Menu:"<<endl;
    	cout<<"Insert 1:"<<endl;
    	cout<<"Delete 2:"<<endl;
    	cout<<"Update 3:"<<endl;
    	cout<<"Select 4:"<<endl;
    	cout<<"Exit 5:"<<endl;
    	//se inserta el orden de las operaciones en un array que se ejecutara simulando la transaccion
    	while(true){
    		cin>>a;
    		if(a==5){
    			cout<<"operacion completada: "<<endl;
    			break;
    		}
    		else{
    			orden.push_back(a);
    		}
    	}
   	}
    bool ejecutar_transaccion(){
    	string data;
    	string data2;
    	string data3;
    	//se ejecuta el array anterior mente llenado por las operaciones requeridas
    	for(int i=0;i<this->orden.size()-1;i++){
    		if(this->orden[i]==1){//INSERTAR
    			cout<<"Ingrese el elemento a insertar en la BD: ";cin>>data;
    			insert(data);
    			cout<<"Dato Insertado"<<endl;
    		}else if(this->orden[i]==2){//ELIMINAR
    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
    			delet(data,data2);
    			cout<<"Dato eliminado"<<endl;
    		}else if(this->orden[i]==3){//ACTUALIZAR
    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
    			update(data,data2,data3);
    			cout<<"Dato actualizado"<<endl;
    		}else if(this->orden[i]==4){//
    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
    			imprimir(select(data));
    		}
    	}
    }
};



class task_constraints:public tabla_maestra
{
public:
	vector<int> orden;    
    lli size=0;  
    string archivo;
    char state;
	char type;
	transaccion tr;
    task_constraints(string archivoX){
    	this->archivo=archivoX;
    	this->state='N';//G Granted /W Waiting /N None
    	this->type='S';//E Exclusive,S Shared
    	this->tr.first=orden;//orden de la transaccion
    	this->tr.second.first=state;//estado de la transaccion
    	this->tr.second.second=type;//tipo de la funcion ejecutada en la transaccion
    }
    bool insert(string datos){
    	ofstream is("task_constraints/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    
    }
    bool delet(T,string);
    bool update(T,string,string);
    vector<string> select(T);
   	bool llenar_transaccion(){
   		int a=0;
    	cout<<"transaccion Menu:"<<endl;
    	cout<<"Insert 1:"<<endl;
    	cout<<"Delete 2:"<<endl;
    	cout<<"Update 3:"<<endl;
    	cout<<"Select 4:"<<endl;
    	cout<<"Exit 5:"<<endl;
    	//se inserta el orden de las operaciones en un array que se ejecutara simulando la transaccion
    	while(true){
    		cin>>a;
    		if(a==5){
    			cout<<"operacion completada: "<<endl;
    			break;
    		}
    		else{
    			orden.push_back(a);
    		}
    	}
   	}
    bool ejecutar_transaccion(){
    	string data;
    	string data2;
    	string data3;
    	//se ejecuta el array anterior mente llenado por las operaciones requeridas
    	for(int i=0;i<this->orden.size()-1;i++){
    		if(this->orden[i]==1){//INSERTAR
    			cout<<"Ingrese el elemento a insertar en la BD: ";cin>>data;
    			insert(data);
    			cout<<"Dato Insertado"<<endl;
    		}else if(this->orden[i]==2){//ELIMINAR
    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
    			delet(data,data2);
    			cout<<"Dato eliminado"<<endl;
    		}else if(this->orden[i]==3){//ACTUALIZAR
    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
    			update(data,data2,data3);
    			cout<<"Dato actualizado"<<endl;
    		}else if(this->orden[i]==4){//
    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
    			imprimir(select(data));
    		}
    	}
    }
};

class task_events:public tabla_maestra
{
public:
	vector<int> orden;
    string archivo;
    char state;
	char type;
	transaccion tr;
    lli size=0;  
    task_events(string archivoX){
    	this->archivo=archivoX;
    	this->state='N';//G Granted /W Waiting /N None
    	this->type='S';//E Exclusive,S Shared
    	this->tr.first=orden;//orden de la transaccion
    	this->tr.second.first=state;//estado de la transaccion
    	this->tr.second.second=type;//tipo de la funcion ejecutada en la transaccion
    }
    bool insert(string datos){
    	ofstream is("task_events/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    
    }
    bool delet(T,string);
    bool update(T,string,string);
    vector<string> select(T);
   	bool llenar_transaccion(){
   		int a=0;
    	cout<<"transaccion Menu:"<<endl;
    	cout<<"Insert 1:"<<endl;
    	cout<<"Delete 2:"<<endl;
    	cout<<"Update 3:"<<endl;
    	cout<<"Select 4:"<<endl;
    	cout<<"Exit 5:"<<endl;
    	//se inserta el orden de las operaciones en un array que se ejecutara simulando la transaccion
    	while(true){
    		cin>>a;
    		if(a==5){
    			cout<<"operacion completada: "<<endl;
    			break;
    		}
    		else{
    			orden.push_back(a);
    		}
    	}
   	}
    bool ejecutar_transaccion(){
    	string data;
    	string data2;
    	string data3;
    	//se ejecuta el array anterior mente llenado por las operaciones requeridas
    	for(int i=0;i<this->orden.size()-1;i++){
    		if(this->orden[i]==1){//INSERTAR
    			cout<<"Ingrese el elemento a insertar en la BD: ";cin>>data;
    			insert(data);
    			cout<<"Dato Insertado"<<endl;
    		}else if(this->orden[i]==2){//ELIMINAR
    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
    			delet(data,data2);
    			cout<<"Dato eliminado"<<endl;
    		}else if(this->orden[i]==3){//ACTUALIZAR
    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
    			update(data,data2,data3);
    			cout<<"Dato actualizado"<<endl;
    		}else if(this->orden[i]==4){//
    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
    			imprimir(select(data));
    		}
    	}
    }
};

class task_usage:public tabla_maestra
{
public:
	vector<int> orden;
	lli size=0;
	string archivo;
	char state;
	char type;
	transaccion tr;
	task_usage(string archivoX){
		this->archivo=archivoX;
    	this->state='N';//G Granted /W Waiting /N None
    	this->type='S';//E Exclusive,S Shared
    	this->tr.first=orden;//orden de la transaccion
    	this->tr.second.first=state;//estado de la transaccion
    	this->tr.second.second=type;//tipo de la funcion ejecutada en la transaccion
	}
    bool insert(string datos){
    	ofstream is("task_usage/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    
    }
    bool delet(T,string);
    bool update(T,string,string);
    vector<string> select(T);
   	bool llenar_transaccion(){
   		int a=0;
    	cout<<"transaccion Menu:"<<endl;
    	cout<<"Insert 1:"<<endl;
    	cout<<"Delete 2:"<<endl;
    	cout<<"Update 3:"<<endl;
    	cout<<"Select 4:"<<endl;
    	cout<<"Exit 5:"<<endl;
    	//se inserta el orden de las operaciones en un array que se ejecutara simulando la transaccion
    	while(true){
    		cin>>a;
    		if(a==5){
    			cout<<"operacion completada: "<<endl;
    			break;
    		}
    		else{
    			orden.push_back(a);
    		}
    	}
   	}
    bool ejecutar_transaccion(){
    	string data;
    	string data2;
    	string data3;
    	//se ejecuta el array anterior mente llenado por las operaciones requeridas
    	for(int i=0;i<this->orden.size()-1;i++){
    		if(this->orden[i]==1){//INSERTAR
    			cout<<"Ingrese el elemento a insertar en la BD: ";cin>>data;
    			insert(data);
    			cout<<"Dato Insertado"<<endl;
    		}else if(this->orden[i]==2){//ELIMINAR
    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
    			delet(data,data2);
    			cout<<"Dato eliminado"<<endl;
    		}else if(this->orden[i]==3){//ACTUALIZAR
    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
    			update(data,data2,data3);
    			cout<<"Dato actualizado"<<endl;
    		}else if(this->orden[i]==4){//
    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
    			imprimir(select(data));
    		}
    	}
    }
};

















/*

template <class tt>
struct machine_atributtes{
	tt timestamp;
	tt machine_id;
	tt attribute_name;
	tt attribute_value;
	bool attribute_deleted;
};
template <class tt>
struct machine_evets{
	tt timestamp;
	tt machine_id;
	tt event_type;
	tt plataform_id;
	tt capacity_cpu;
	tt capacity_memory;
};
template <class tt>
struct job_events{
	tt timestamp;
	tt missing_info;
	tt job_id;
	tt event_type;
	tt user_name;
	tt scheduling_class;
	tt job_name;
	tt logical_job_name;
};
template <class tt>
struct tast_events{
	tt timestamp;
	tt missing_info;
	tt job_id;
	tt task_index;
	tt machine_id;
	tt event_type;
	tt user_name;
	tt scheduling_class;
	tt priority;
	tt request_cpu;
	tt request_ram;
	tt request_disk;
	tt different_machine;
};

template <class tt>
struct task_contrains{
	tt timestamp;
	tt job_id;
	tt task_index;
	tt attribute_name;
	tt attribute_value;
	tt comparison_operator;
};

template <class tt>
struct task_usage{
	tt start_time;
	tt end_time;
	tt job_id;
	tt task_index;
	tt machine_id;
	tt mean_cpu_usage_rate;
	tt canocical_memory_usage;
	tt assigned_memory_usage;
	tt unmapped_page_cache_memory_usage;
	tt total_page_cache_memory_usage;
	tt maximum_memory_usage;
	tt mean_disk_io_time;
	tt mean_local_disk_space_used;
	tt maximum_cpu_usage;
	tt maximum_disk_io_time;
	tt cycles_per_instruction_cpi;
	tt memory_acceses_per_instruccion_mai;
	tt sample_portion;
	tt aggregation_type;
	tt sampled_cpu_usage;
};*/


#endif //TRANSACCIONES_H
