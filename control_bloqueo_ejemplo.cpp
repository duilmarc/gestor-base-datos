
//fuente github.com/skdi/OAD/hash.cpp Codigo propio
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct transaccion{
	char state;//G Granted /W Waiting
	string nombre;
	char type;//E Exclusive,S Shared
};

const int TABLE_SIZE=10;
class has{
private:
    int key;
    int value;
    char state='N';//N non a,S shared,X Exclusive
    has *next;
    queue<transaccion*> Tr;
public:
    has(int key,int value);
    int getkey(){return key;}
    int get_value(){return value;}
    char get_state(){return state;}
    void set_value(int value){this->value=value;}
    has *getnext(){return next;}
    void set_next(has* next){this->next=next;}
    void insertar_T(transaccion *T);
    void liberar();
};

class hasmap{
private:
    has **table;
public:
    hasmap(){
        table=new has*[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++)
            table[i]=NULL;
    }
    int get(int key){
        int hash1=(key%TABLE_SIZE);
        if(table[hash1]==NULL){
            return -1;
        }
        else{
            has *entry=table[hash1];
            while(entry!=NULL && entry->getkey()!=key)
                entry=entry->getnext();
            if(entry==NULL)
                return -1;
            else return entry->get_value();
        }
    }
    has *get_node(int key){
        int hash1=(key%TABLE_SIZE);
        if(table[hash1]==NULL){
            cout<<"hash vacio"<<endl;
        }
        else{
            return table[hash1];
        }
    }
    void put(int key,int value);
    void remove(int key);
    ~hasmap(){
        for(int i=0;i<TABLE_SIZE;i++)
            if(table[i]!=NULL){
                has *prev=NULL;
                has *entry=table[i];
                while(entry!=NULL){
                    prev=entry;
                    entry=entry->getnext();
                    delete prev;
                }
            }
        delete[] table;
    }

};


has::has(int key, int value){
    this->key=key;
    this->value=value;
    this->next=NULL;
    //this->Tr=NULL;

}
void has::insertar_T(transaccion *T){
	if(this->state=='N'){
		this->state=T->type;
		T->state='G';

	}else if(this->state=='S' && T->type=='S'){
		T->state='G';

	}else if(this->state='X'){
		T->state='W';
	}
	this->Tr.push(T);
}
void has::liberar(){
    if(this->Tr.empty()){
        cout<<"No quedan mas transacciones"<<endl;
        return;
    }else{
    this->state='N';
	this->Tr.pop();	
	transaccion *temp;
	temp=Tr.front();
	temp->state='G';
	delete temp;
    }
}

void hasmap::put(int key, int value){
    int hash1=key%TABLE_SIZE;
    if(table[hash1]==NULL){
        table[hash1]=new has(key,value);
        return;
    }else
        table[hash1]->set_next(new has(key,value));

}


void hasmap::remove(int key){
    int hash1=key%TABLE_SIZE;
    has *mihash=table[hash1];
    if(mihash==NULL){
        cout<<"vacio"<<endl;
        return;
    }else{
        while(mihash->getnext()!=NULL){
            if(mihash->getkey()==key){
                has *temp=mihash;//guardo la posicion anterior
                mihash=mihash->getnext();//poisicion actual
                has *temp2=mihash->getnext();//posicion sig
                temp->set_next(temp2);
                delete mihash;
            }
            mihash=mihash->getnext();
        }
    }


}


int main(){
    hasmap* mimap=new hasmap();
    transaccion *A=new transaccion();
    transaccion *B=new transaccion();
    transaccion *C=new transaccion();
    //inicializacion de las transacciones
    A->nombre="T1";
    B->nombre="T2";
    C->nombre="T3";
    A->type='x';
    B->type='s';
    C->type='s';
    //inicializacion de los nodos del hash
    mimap->put(2,2);
    mimap->put(6,6);
    mimap->put(7,7);
    //copia de los nodos de mimap(tabla hash) para facilidad de trabajo
    has *has1=mimap->get_node(2);
    has *has2=mimap->get_node(6);
    has *has3=mimap->get_node(7);
    //insercion de las transacciones en los nodos
    if(has1!=NULL && has2!=NULL && has3!=NULL){

        has1->insertar_T(A);

        has2->insertar_T(A);
        has2->insertar_T(B);

        has3->insertar_T(B);
        has3->insertar_T(C);

        //liberando luego de finalizar la transaccion
        cout<<"Estado de Has1 antes de liberar la transaccion A: "<<has1->get_state()<<endl;
        has1->liberar();
        cout<<"Estado de Has1 despues de liberar la transaccion A: "<<has1->get_state()<<endl;
        
        cout<<"Estado de Has2 antes de liberar la transaccion A: "<<has2->get_state()<<endl;
        has2->liberar();
        cout<<"Estado de Has2 despues de liberar la transaccion A: "<<has2->get_state()<<endl;
       
        cout<<"Estado de Has2 antes de liberar la transaccion B: "<<has2->get_state()<<endl;
        has2->liberar();
        cout<<"Estado de Has2 despues de liberar la transaccion B: "<<has2->get_state()<<endl;
        
        cout<<"Estado de Has3 antes de liberar la transaccion B: "<<has3->get_state()<<endl;
        has3->liberar();
        cout<<"Estado de Has3 despues de liberar la transaccion B: "<<has3->get_state()<<endl;
       
        cout<<"Estado de Has3 antes de liberar la transaccion C: "<<has3->get_state()<<endl;
        has3->liberar();
        cout<<"Estado de Has3 despues de liberar la transaccion C: "<<has3->get_state()<<endl;
    

    }

    //liberacion de memoria
    delete A,B,C,mimap;
    return 0;
}
