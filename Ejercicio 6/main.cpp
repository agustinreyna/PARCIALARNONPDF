#include <iostream>
#include "../Cola/Cola.h"
#include "../Cola/Pila.h"
using namespace std;
template <class T>

void ordenar(Cola<T> cola){
    Cola<T> colaAux;
    Pila<T> pila;
    int cont=1;
    while(!cola.esVacia()){
        if(cont%2!=0)pila.push(cola.desencolar());
        else if(cont%2==0)colaAux.encolar(cola.desencolar());
        cont++;
    }
    cout<<"Los valores que quedan en la cola son los siguientes:"<<endl;
    colaAux.imprimir();
    cout<<"Los valores que quedan en la pila son los siguientes:"<<endl;
    pila.imprimir();
    return;
}

int main(){   
    Cola<int> cola;
    int n,dato;
    cout<<"Decime el tamanio de la cola: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Decime el dato"<<endl;
        cin>>dato;
        cola.encolar(dato);
    }
    ordenar(cola);
    return 0;
}
