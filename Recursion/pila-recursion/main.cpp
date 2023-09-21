#include <iostream>
#include "../../Cola/Pila.h"
using namespace std;

template <class T>
void menor(Pila<T> &pila,T men){
    if(pila.esVacia())cout<<"El dato mas chico es: "<< men;
    else {
        if(pila.peek()<men)men=pila.peek();
        pila.pop();
        return menor(pila,men);
    }
}

int main(int argc, char const *argv[])
{
    int men,dato, tam;
    Pila<int> pila;
    cout << "Decime el tamanio de la pila" << endl;
    cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        cout << "Decime el valor del arreglo en la posicion " << i + 1 << ": ";
        cin >> dato;
        pila.push(dato);
    }
    men=pila.peek();
    menor(pila,men);
    return 0;
}
