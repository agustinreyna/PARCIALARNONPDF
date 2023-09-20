#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;


template <class T>
class Nodo
{
private:
    T dato;
    Nodo<T> *sgte;

public:
    T getDato()
    {
        return dato;
    }
    void setDato(T n)
    {
        dato = n;
    }
    Nodo<T> *getSiguiente()
    {
        return sgte;
    }
    void setSiguiente(Nodo<T> *next)
    {
        sgte = next;
    }
};
#endif //NODO_H