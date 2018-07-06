#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
typedef unsigned long long int lli;
typedef char* T;
using namespace std;


class tabla_maestra
{
public:
	tabla_maestra();
	virtual bool insert(string);
	virtual bool delet(T,string);
	virtual bool update(T,string);
	virtual string select(T);

};


class job_events:public tabla_maestra
{
public:
    lli size=0;    
    string archivo;
    job_events(string archivoX){
    	this->archivo=archivoX;
    }
    bool insert(string datos){
    	ofstream is("job_events/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    }
    bool delet(T,string);
    bool update(T,string);
    string select(T);
};

class machine_attributes:public tabla_maestra
{
public:

	lli size=0;
	string archivo;
	machine_attributes(string archivoX){
		this->archivo=archivoX;
	}
    bool insert(string datos){
    	ofstream is("machine_attributes/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n"; size++;}
    
    }
    bool delet(T,string);
    bool update(T,string);
    string select(T);


};

class machine_events:public tabla_maestra
{
public:
	string archivo;
	machine_events(string archivoX){
		this->archivo=archivoX;
	}
    lli size=0;
    bool insert(string datos){
    	ofstream is("machine_events/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    }
    bool delet(T,string);
    bool update(T,string);
    string select(T);

};



class task_constraints:public tabla_maestra
{
public:
    
    lli size=0;  
    string archivo;
    task_constraints(string archivoX){
    	this->archivo=archivoX;
    }
    bool insert(string datos){
    	ofstream is("task_constraints/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    
    }
    bool delet(T,string);
    bool update(T,string);
    string select(T);

};

class task_events:public tabla_maestra
{
public:
    string archivo;
    lli size=0;  
    task_events(string archivoX){
    	this->archivo=archivoX;
    }
    bool insert(string datos){
    	ofstream is("task_events/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    
    }
    bool delet(T,string);
    bool update(T,string);
    string select(T);

};

class task_usage:public tabla_maestra
{
public:

	lli size=0;
	string archivo;
	task_usage(string archivoX){
		this->archivo=archivoX;
	}
    bool insert(string datos){
    	ofstream is("task_usage/"+this->archivo+".csv",fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";  size++;}
    
    }
    bool delet(T,string);
    bool update(T,string);
    string select(T);

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


#endif //ESTRUCTURA_H
