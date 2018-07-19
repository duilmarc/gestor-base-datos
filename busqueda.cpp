#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;


//Busqueda el elemento en forma binaria en un arreglo y retorna la 2 posicion
int busquedaBinaria(const vector<pair<long int,long int>> indices, long int key)
{
  long int Iarriba = indices.size();
  long int Iabajo = 0;
  long int Icentro;
  while (Iabajo <= Iarriba)
  {
      Icentro = round((Iarriba + Iabajo)/2);
      if (indices[Icentro].first == key)
 			return Icentro;
      else
 		if (key < indices[Icentro].first)
   			Iarriba=Icentro-1;
 	  	else
   			Iabajo=Icentro+1;
  }
  return -1;
}
// BsuquedaBinaria Aplicada a intervalos
int busqueda_en_intervalos(const vector<pair<long int,long int>> intervalos, long int key)
{
  long int Iarriba = intervalos.size();
  long int Iabajo = 0;
  long int Icentro;
  while (Iabajo <= Iarriba)
  {
      Icentro = round((Iarriba + Iabajo)/2);
      if (intervalos[Icentro].first <= key && intervalos[Icentro].second >= key)
 			return Icentro;
      else
 		if (key < intervalos[Icentro].first)
   			Iarriba=Icentro-1;
 	  	else
   			Iabajo=Icentro+1;
  }
  return -1;
}

class Tabla
{
public:
	// Datos de la misma tabla
	vector<vector<pair<long int ,long int>>> indices;
	vector<pair<long int, long int>> intervalos;
	int cantidad_intervalos;
	string direccion; // direccion de carpeta
	int n_archivo ; //usado para la busqueda en los indicesrepetidos 
	long int pos_limite; // usado para limitar el archivo con el hash
	Tabla(string direccion);
	bool crear_intervalos();
	long int busqueda(long int index);
	bool asignar_indice(int n);
	void imprimir_intervalos();
	void imprimir_indices();
	void obtener_posiciones(vector<pair<long int,int>>& pos_pos_a,long int posicion);
	~Tabla();
	
};

// INICIA LA TABLA CON UNA DIRECCION
Tabla::Tabla(string direccion)
{
	this->direccion=direccion;
	crear_intervalos(); // se levanta a memoria los intervalos para el uso de clustering

}
// DESTRUCTOR DE LA CLASE
Tabla::~Tabla()
{

}
// IMPRIME LA CANTIDAD DE INDICES LEVANTADOS A MEMORIA REFIRIENDOSE A CADA 
// ARCHIVO
void Tabla::imprimir_indices()
{
	for(int i=0;i < indices.size();i++)
	{
		cout<<indices[i].size()<<endl;

	}
}

// MUESTA LOS INTERVALOS DE INDICES QUE EXISTEN PARA ESA TABLA
void Tabla::imprimir_intervalos()
{
	for(int i=0;i < intervalos.size();i++)
	{
		cout<<intervalos[i].first<<" "<<intervalos[i].second;
		cout<<endl;
	}
}
// LEVANTA A MEMORIA LOS INTERVALOS LEYENDO EL ARCHIVO "intervalos" de la 
// TABLA REFERIDA
bool Tabla::crear_intervalos()
{

	ifstream a_intervalos(this->direccion+"intervalos",std::ifstream::binary);
	int n_intervalos=0;
	if(a_intervalos)
	{
		char *rango1= new char[50];
		char *rango2= new char[50];
		char *n_archivo=new char[10];
		long int limite1,limite2;

		while(!a_intervalos.eof()){
			a_intervalos.getline(rango1,50,'-');
			a_intervalos.getline(rango2,50,'-');
			a_intervalos.getline(n_archivo,50);
			limite1=atol(rango1);
			limite2=atol(rango2);
			this->intervalos.push_back(make_pair(limite1,limite2));
			this->indices.push_back(vector<pair<long int ,long int>>());
			n_intervalos++;

		}
		a_intervalos.close();	
		this->cantidad_intervalos=n_intervalos; 
		return true;
	}
	else
	{
		return false;
	}
}

// LEVANTA A MEMORIA UN VECTOR DE INDICE Y POSICIONES DEL NUMERO DE ARCHIVO DESSEADO

bool Tabla::asignar_indice(int nu_archivo)
{	
	string numero_archivo=to_string(nu_archivo+1);
	string archivo_busqueda=this->direccion+"indice"+numero_archivo+"_x";
	//cout<<archivo_busqueda<<endl;
	ifstream is(archivo_busqueda,std::ifstream::binary);
	long int pos,ind;
	if(is)
	{
		char *indice=new char[50];
		char *posicion=new char[50];
		while(!is.eof())
		{
			is.getline(indice,50,',');
			is.getline(posicion,50,'|');
			pos=atol(posicion);
			ind=atol(indice);
			this->indices[nu_archivo].push_back(make_pair(ind,pos));
		}
		is.close();
		return true;
	}
	else
	{

		return false;
	}
} 

// BUSQUEDA POR INDICES, 1 EN EL INTERVALO LUEGO BUSCA EN EL VECTOR DE INDICES Y POSICIONES
// CASO EL VECTOR ESTE VACIO. LEVANTA A MEMORIA LOS INDICES RESPECTIVOS PARA REALIZAR LA BUSQUEDA
// CASO NO LO ENCUENTRE DA COMO RETORNA UNA POSICION -1

long int Tabla::busqueda(long int indice)
{
	int posicion=busqueda_en_intervalos(this->intervalos,indice); // busca el indice en los intervalos
	this->n_archivo=posicion+1;
	if(indices[posicion].size()==0) // si el vector esta vacio
	{
		if(!asignar_indice(posicion))
		{
			cout<<"error";
			return -1;
		}
		
	}
	int pos_archivo;
	pos_archivo=busquedaBinaria(this->indices[posicion],indice);
	if(pos_archivo!=-1)
	{
		if(indices[posicion].size()==pos_archivo+1)
		{
			this->pos_limite=-1; // en el caso de que desborde el tamaño del array
		}
		else
		{
			this->pos_limite=this->indices[posicion][pos_archivo+1].second;
		}
		return indices[posicion][pos_archivo].second;
	}
	else
	{
		return -1;
	}
}

// obtiene las posiciones y las guarda en un vector de posiciones 
void Tabla::obtener_posiciones( vector<pair<long int, int>>& pos_pos_a,long int posicion)
{
	string dir=this->direccion+"indice"+to_string(this->n_archivo);
	long int posicion2;
	fstream hashin(dir,  fstream::in |fstream::out | fstream::binary);
	hashin.seekg(posicion,ios::beg);
	posicion2=hashin.tellg();
	if(hashin)
	{
		char *indice= new char[50];
		long int posicion;
		long int n_archivo;
		char *pos= new char[50];
		char *n_ar=new char[50];		
		hashin.getline(indice,50,',');
		if(this->pos_limite==-1)
		{
			this->pos_limite==posicion+10;
		}
		while(posicion2<this->pos_limite)	
		{
			if(hashin.eof())
			{
				return;
			}
			hashin.getline(pos,50,'-');
			hashin.getline(n_ar,50,',');
			posicion2=hashin.tellg();
			if(posicion2<this->pos_limite)
				pos_pos_a.push_back(make_pair(atol(pos),atol(n_ar)));
		}
			
	}
}

int main()
{
	string salida1="/home/duilmarc/Documents/bd2/proyecto_Base_Datos/clusterdata-2011-2/job_events/";	
	Tabla *jobEvents= new Tabla(salida1);
	long int posicion=jobEvents->busqueda(6423593867);
	vector<pair<long int,int>> pos;
	jobEvents->obtener_posiciones(pos,posicion);
	for(int i=0;i<pos.size();i++)
	{
		cout<<pos[i].first<<" "<<pos[i].second<<endl;
	}

	

	return 0;
}
