#include <iostream>
using namespace std;

struct nodo {
    int telefono;
    int documento;
    nodo *sig;
};

nodo *cab, *aux, *aux2;
void registrar(){
    aux = (struct nodo *) malloc (sizeof(nodo));
    cout<<"Telefono: ";
    cout<<"Documento: ";
    cin>>aux->telefono;
    cin>>aux->documento;
    aux->sig = NULL;
    if(!cab){
        cab = aux;
    } else {
        aux2=cab;
        while(aux2->sig!=NULL){
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}
void mostrar(){
    aux=cab;
    while(aux!=NULL){
        cout<<"Telefono: "<<aux->telefono<<endl;
        cout<<"Documento: "<<aux->documento<<endl;
        aux = aux->sig;
    }
}
void ordenar(){
    int temporal;
    aux2 = cab;
    while(aux2->sig!=NULL){
        aux = cab;
        while(aux->sig!=NULL){
            if(aux->telefono>aux->sig->telefono){
                temporal = aux->telefono;
                aux->telefono = aux->sig->telefono;
                aux->sig->telefono = temporal;
            }
            aux = aux->sig;
        }
        aux2 =aux2->sig;
    }
}
int main(){
    int opcion;
    do {
        cout<<"Menu"<<endl<<"1. Insertar Contacto"<<endl<<"2. Mostrar Contactos"<<endl<<"3. Ordenar"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrar();
        break;
        case 2:
            mostrar();
        break;
        case 3:
            ordenar();
        break;
        }
    }while(opcion!=5);
}