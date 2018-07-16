#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::sort
#include "estructuras.h"

using namespace std;

int main(){
	/*string archivo="franco";
	string datos="putin";
	    ofstream is("machine_events/"+archivo+".csv",std::fstream::app);
    	if(!is){
    		cout<<"Error 40X : no se pudo encontrar el archivo deseado"<<endl;
    	}else {is<<datos;is<<"\n";}*/

    machine_attributes *hola=new machine_attributes("francoputin");
    machine_events hola2("");
    
	hola->insert("franco es un putin y nadie lo puede negar ;) ");
	
  delete hola;


	return 0;
}
