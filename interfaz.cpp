#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>    // std::sort
#include "transacciones.h"


using namespace std;

int main(){
	string tabla;
    string archivo;
    string data,data2,data3;
    int opcion;

 /*   
    machine_events *m_events=new machine_events("prueba");
    task_constraints *t_constrains=new task_constraints("prueba");
    task_events *t_events=new task_events("prueba");
    task_usage *t_usage=new task_usage("prueba");
*/

    cout<<"Gesto de Base de datos clusterdata 2011-2 ver. 1.0"<<endl<<endl;
    cout<<"Menu Index!!"<<endl;
    while(true){
	    cout<<"job_events		machine_attributes		machine_events		task_constraints 		task_events		task_usage "<<endl;
	    cout<<"Seleccione la tabla en la que desea operar: ";cin>>tabla;
	    //Control de bloqueo 
	    hasmap * block=new hasmap();
	    block->put(1,1);
	    block->put(2,2);
	    //rutas para el bloqueo de las operaciones
	    //se eligieron 2 rutas por facilidad
	    has *ruta1=block->get_node(1);
	    has *ruta2=block->get_node(2);
	    if(tabla=="Exit")
	    	return 0;
	    else{
	    	cout<<"Ingrese el nombre del archivo en el que desea trabajar: ";cin>>archivo;
		    while(1){
		    	if(tabla=="job_events"){
		    		cout<<"Tabla Seleccionada"<<endl;
		    		job_events *j_events=new job_events(archivo);
		    		ruta1->insertar_T(j_events->tr);
		    		cout<<"Operaciones :"<<endl;
		    		cout<<"Insert 1:"<<endl;
		    		cout<<"Delete 2:"<<endl;
		    		cout<<"Update 3:"<<endl;
		    		cout<<"Select 4:"<<endl;
		    		cout<<"Opciones extras:"<<endl;
		    		cout<<"llenar y ejecutar transaccion 5:"<<endl;
		    		cin>>opcion;
		    		if(opcion<0 || opcion>5){
		    			cout<<"Opcion Erronea , vuelva a intentarlo"<<endl;
		    			break;
		    		}
		    		else{
		    			if(opcion==1){//INSERTAR
			    			cout<<"Ingrese el elemento a insertar en la BD: ";cin>>data;
			    			j_events->insert(data);
			    			cout<<"Dato Insertado"<<endl;
			    			ruta1->liberar();

			    		}else if(opcion==2){//ELIMINAR
			    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
			    			j_events->delet(data,data2);
			    			cout<<"Dato eliminado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==3){//ACTUALIZAR
			    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
			    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
			    			j_events->update(data,data2,data3);
			    			cout<<"Dato actualizado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==4){//
			    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
			    			imprimir(j_events->select(data));
			    		}else if(opcion==5){
			    			j_events->llenar_transaccion();
			    			j_events->ejecutar_transaccion();
			    			ruta1->liberar();
			    		}
		    		}
		    		delete j_events;
		    	}
		    	else if(tabla=="machine_attributes"){

		    	    cout<<"Tabla Seleccionada"<<endl;
		    		machine_attributes *m_attributes=new machine_attributes(archivo);
		    		ruta1->insertar_T(m_attributes->tr);
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
			    			m_attributes->insert(data);
			    			cout<<"Dato Insertado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==2){//ELIMINAR
			    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
			    			m_attributes->delet(data,data2);
			    			cout<<"Dato eliminado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==3){//ACTUALIZAR
			    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
			    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
			    			m_attributes->update(data,data2,data3);
			    			cout<<"Dato actualizado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==4){//
			    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
			    			imprimir(m_attributes->select(data));
			    		}else if(opcion==5){
			    			m_attributes->llenar_transaccion();
			    			m_attributes->ejecutar_transaccion();
			    			ruta1->liberar();
			    		}
		    		}
		    		delete m_attributes;
		    	}
		    	else if(tabla=="machine_events"){

		    	    cout<<"Tabla Seleccionada"<<endl;
		    		machine_events *m_events=new machine_events(archivo);
		    		ruta1->insertar_T(m_events->tr);
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
			    			m_events->insert(data);
			    			cout<<"Dato Insertado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==2){//ELIMINAR
			    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
			    			m_events->delet(data,data2);
			    			cout<<"Dato eliminado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==3){//ACTUALIZAR
			    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
			    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
			    			m_events->update(data,data2,data3);
			    			cout<<"Dato actualizado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==4){//
			    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
			    			imprimir(m_events->select(data));
			    		}else if(opcion==5){
			    			m_events->llenar_transaccion();
			    			m_events->ejecutar_transaccion();
			    			ruta1->liberar();
			    		}
		    		}
		    		delete m_events;
		    	}
		    	else if(tabla=="task_constraints"){

		    	    cout<<"Tabla Seleccionada"<<endl;
		    		task_constraints *t_constraints=new task_constraints(archivo);
		    		ruta1->insertar_T(t_constraints->tr);
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
			    			t_constraints->insert(data);
			    			cout<<"Dato Insertado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==2){//ELIMINAR
			    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
			    			t_constraints->delet(data,data2);
			    			cout<<"Dato eliminado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==3){//ACTUALIZAR
			    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
			    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
			    			t_constraints->update(data,data2,data3);
			    			cout<<"Dato actualizado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==4){//
			    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
			    			imprimir(t_constraints->select(data));
			    		}else if(opcion==5){
			    			t_constraints->llenar_transaccion();
			    			t_constraints->ejecutar_transaccion();
			    			ruta1->liberar();
			    		}
		    		}
		    		delete t_constraints;
		    	}
		    	else if(tabla=="task_events"){

		    	    cout<<"Tabla Seleccionada"<<endl;
		    		task_events *t_events=new task_events(archivo);
		    		ruta1->insertar_T(t_events->tr);
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
			    			t_events->insert(data);
			    			cout<<"Dato Insertado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==2){//ELIMINAR
			    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
			    			t_events->delet(data,data2);
			    			cout<<"Dato eliminado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==3){//ACTUALIZAR
			    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
			    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
			    			t_events->update(data,data2,data3);
			    			cout<<"Dato actualizado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==4){//
			    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
			    			imprimir(t_events->select(data));
			    			ruta1->liberar();
			    		}else if(opcion==5){
			    			t_events->llenar_transaccion();
			    			t_events->ejecutar_transaccion();
			    			ruta1->liberar();
			    		}
		    		}
		    		delete t_events;
		    	}
		    	else if(tabla=="task_usage"){

		    	    cout<<"Tabla Seleccionada"<<endl;
		    		task_usage *t_usage=new task_usage(archivo);
		    		ruta1->insertar_T(t_usage->tr);
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
			    			t_usage->insert(data);
			    			cout<<"Dato Insertado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==2){//ELIMINAR
			    			cout<<"Ingrese el indice del elemento a eliminar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a eliminar de la BD: ";cin>>data2;
			    			t_usage->delet(data,data2);
			    			cout<<"Dato eliminado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==3){//ACTUALIZAR
			    			cout<<"Ingrese el indice del elemento a actualizar de la BD: ";cin>>data;
			    			cout<<"Ingrese el elemento a insertar de la BD: ";cin>>data2;
			    			cout<<"ingrese el elemento a actualizar de la BD: ";cin>>data3;
			    			t_usage->update(data,data2,data3);
			    			cout<<"Dato actualizado"<<endl;
			    			ruta1->liberar();
			    		}else if(opcion==4){//
			    			cout<<"Ingrese el indice del elemento a buscar en la BD: ";cin>>data;
			    			imprimir(t_usage->select(data));
			    			ruta1->liberar();
			    		}else if(opcion==5){
			    			t_usage->llenar_transaccion();
			    			t_usage->ejecutar_transaccion();
			    			ruta1->liberar();
			    		}
		    		}
		    		delete t_usage;
		    	}
		    	else
		    		cout<<"Error al seleccionar la tabla "<<endl;
		    
		    }
		}
	}

        

}
