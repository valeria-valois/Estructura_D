#include <iostream>
using namespace std;

struct nodo {
    string nombre;
    int codigo;
    float nota;
    nodo *sig;
};

nodo *cab, *aux, *aux2;

void registrar(){
    aux = (struct nodo *) malloc (sizeof(nodo));
    cout<<"Ingrese el primer nombre del estudiante: ";
    cin>>aux->nombre;
    cout<<"Ingrese el código estudiantil: ";
    cin>>aux->codigo;
    cout<<"Ingrese la nota del estudiante: ";
    cin>>aux->nota;
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
        cout<<"Nombre: "<<aux->nombre<<endl;
        cout<<"Código Estudiantil: "<<aux->codigo<<endl;
        cout<<"Nota: "<<aux->nota<<endl;
        aux = aux->sig;
    }
}

void ordenar_codigo(){
    int temporal;
    aux2 = cab;
    while(aux2->sig!=NULL){
        aux = cab;
        while(aux->sig!=NULL){
            if(aux->codigo>aux->sig->codigo){
                temporal = aux->codigo;
                aux->codigo = aux->sig->codigo;
                aux->sig->codigo = temporal;
                string temp = aux->nombre;
                aux->nombre = aux->sig->nombre;
                aux->sig->nombre = temp;
                float tempf = aux->nota;
                aux->nota = aux->sig->nota;
                aux->sig->nota = tempf;
            }
            aux = aux->sig;
        }
        aux2 =aux2->sig;
    }
}

void ordenar_nota(){
    float temporal;
    aux2 = cab;
    while(aux2->sig!=NULL){
        aux = cab;
        while(aux->sig!=NULL){
            if(aux->nota<aux->sig->nota){
                temporal = aux->nota;
                aux->nota = aux->sig->nota;
                aux->sig->nota = temporal;
                int temp = aux->codigo;
                aux->codigo = aux->sig->codigo;
                aux->sig->codigo = temp;
                string temp2 = aux->nombre;
                aux->nombre = aux->sig->nombre;
                aux->sig->nombre = temp2;
            }
            aux = aux->sig;
        }
        aux2 =aux2->sig;
    }
}

float mayor_nota(){
    float max = cab->nota;
    aux = cab;
    while(aux!=NULL){
        if(aux->nota>max){
            max = aux->nota;
        }
        aux = aux->sig;
    }
    return max;
}

float menor_nota(){
    float min = cab->nota;
    aux = cab;
    while(aux!=NULL){
        if(aux->nota<min){
            min = aux->nota;
        }
        aux = aux->sig;
    }
    return min;
}

float promedio_notas(){
    float sum = 0;
    int count = 0;
    aux = cab;
    while(aux!=NULL){
        sum += aux->nota;
        count++;
        aux = aux->sig;
    }
    return sum / count;
}

int main(){
    int opcion;
    do {
        cout<<"Menu"<<endl<<"1. Ingresar datos de estudiantes"<<endl<<"2. Ordenar y mostrar la lista de estudiantes"<<endl<<"3. Mostrar la mayor nota, menor nota y promedio del curso"<<endl<<"4. Salir del programa"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrar();
        break;
        case 2:
            int ordenar_opcion;
            cout<<"Ordenar por:"<<endl<<"1. Código Estudiantil"<<endl<<"2. Nota"<<endl;
            cin>>ordenar_opcion;
            if(ordenar_opcion==1){
                ordenar_codigo();
            } else {
                ordenar_nota();
            }
            mostrar();
        break;
        case 3:
            float max_nota = mayor_nota();
            float min_nota = menor_nota();
            float promedio = promedio_notas();
            aux = cab;
            while(aux!=NULL){
                if(aux->nota==max_nota){
                    cout<<"La mayor nota es de "<<aux->nombre<<" con código estudiantil "<<aux->codigo<<endl;
                }
                if(aux->nota==min_nota){
                    cout<<"La menor nota es de "<<aux->nombre<<" con código estudiantil "<<aux->codigo<<endl;
                }
                aux = aux->sig;
            }
            cout<<"El promedio de notas es: "<<promedio<<endl;
        break;
        }
    }while(opcion!=4);
    return 0;
}