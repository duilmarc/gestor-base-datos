#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>    // std::sort
#include "transacciones.h"


using namespace std;

int main(){
	//Variables de apoyo
	string tabla;
    string operacion;
    string data,data2,data3;
    int opcion;
    ///////////////
   /* machine_events *m_events=new machine_events("prueba");
    machine_attributes *m_attributes= new machine_attributes("prueba");
    task_constrains *t_constrains=new task_constrains("prueba");
    task_events *t_events=new task_events("prueba");
    task_usage *t_usage=new task_usage("prueba");
*/

    cout<<"Gesto de Base de datos clusterdata 2011-2 ver. 1.0"<<endl<<endl;
    
    cout<<"Seleccione la tabla en la que desea operar: ";cin>>tabla;
    if(tabla!="job_events" || tabla!="m_attributes"||tabla!="t_constrains"||tabla!="t_events"||tabla!="t_usage"){
    	cout<<"Error al seleccionar la tabla "<<endl;}
    else{

    		cout<<"Menu Index! "<<endl;
        	cout<<"Ingrese el nombre del archivo en el que desea trabajar: ";cin>>operacion;
    		tabla *clase=new tabla(operacion);
    		cout<<"Operaciones :"<<endl;
    		cout<<"Insert 1:"<<endl;
    		cout<<"Delete 2:"<<endl;
    		cout<<"Update 3:"<<endl;
    		cout<<"Select 4:"<<endl;
    		cout<<"Opciones extras:"<<endl;
    		cout<<"llenar y ejecutar transaccion 5:"<<endl;
    		cin>>opcion;
    		if(opcion<0 || opcion>5)
    			cout<<"Opcion Erronea , vuelva a intentarlo"<<endl;
    		else{
    			if(opcion==1){//INSERTAR
	    			cout<<"Ingrese el elemento a insertar en la BD: ";cin>>data;
	    			clase->insert(data);
	    			cout<<"Dato Insertado"<<endl;
	    		}else if(opcion==2){//ELIMINAR
	    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
	    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
	    			clase->delet(data,data2);
	    			cout<<"Dato eliminado"<<endl;
	    		}else if(opcion==3){//ACTUALIZAR
	    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
	    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
	    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
	    			clase->update(data,data2,data3);
	    			cout<<"Dato actualizado"<<endl;
	    		}else if(opcion==4){//
	    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
	    			imprimir(clase->select(data));
	    		}else if(opcion==5){
	    			clase->llenar_transaccion();
	    			clase->ejecutar_transaccion();
	    		}
    		}
    



	
	

	delete clase;
	}
	return 0;
}
