#include <iostream>
using namespace std;
#include "../Cola/Cola.h"

int main(int argc, char const *argv[])
{
    Cola<int> cola1,cola2;
    int n,dato;
    cout<<"Decime el tamanio de ambas colas"<<endl;
    cin>>n;
    cout<<"Cola 1:"<<endl;
    for(int i=0;i<n;i++){
        cin>>dato;
        cola1.encolar(dato);
    }
    cout<<"Cola 2:"<<endl;
    for(int i=0;i<n;i++){
        cin>>dato;
        cola2.encolar(dato);
    }
    cout<<"Cola 1:";
    cola1.imprimir();
    cout<<"Cola 2:";
    cola2.imprimir();
    cola1.intercambiar(cola2);
    cout<<"Cola 1:";
    cola1.imprimir();
    cout<<"Cola 2:";
    cola2.imprimir();
    return 0;
}
