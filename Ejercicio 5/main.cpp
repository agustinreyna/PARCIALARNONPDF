#include <iostream>
#include "../Cola/Lista.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Lista<int> lista;
    int n,dato;
    cout<<"Decime el tamanio de la lista: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Decime el dato"<<endl;
        cin>>dato;
        lista.insertarUltimo(dato);
    }
    cout<<"Decime el dato a borrar"<<endl;
    cin>>dato;
    lista.imprimir();
    lista.borrarDato(dato);
    lista.imprimir();
    return 0;
}
