#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <iostream>
using namespace std;

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 **/
template <class T>
class Lista
{
private:
    Nodo<T> *inicio;
    // T dato;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();

    void imprimir();

    void fnInvierte();

    void insertAfter2(int oldValue, int newValue, int contador);

    void unirlistas(Lista &lista2);

    void moverNodo(int pos);

    void borrarDato(T dato);

    void moverUltimo(int pos);
};

/**
 * Constructor de la clase Lista
 * @tparam T
 **/
template <class T>
Lista<T>::Lista()
{
    inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 **/
template <class T>
Lista<T>::Lista(const Lista<T> &li)
{
    inicio = nullptr;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 **/
template <class T>
Lista<T>::~Lista() {}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 **/
template <class T>
bool Lista<T>::esVacia()
{
    return inicio == nullptr;
}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 **/
template <class T>
int Lista<T>::getTamanio()
{
    Nodo<T> *aux = inicio;
    int tam = 0;

    while (aux != nullptr)
    {
        aux = aux->getSiguiente();
        tam++;
    }
    return tam;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 **/
template <class T>
void Lista<T>::insertar(int pos, T dato)
{
    Nodo<T> *aux = inicio;
    int posActual = 0;
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);

    if (pos == 0)
    {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux != nullptr && posActual < pos - 1)
    {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
    {
        throw 404;
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 **/
template <class T>
void Lista<T>::insertarPrimero(T dato)
{
    insertar(0, dato);
}

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 **/
template <class T>
void Lista<T>::insertarUltimo(T dato)
{
    Nodo<T> *aux = inicio;
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    if (aux == nullptr)
    { // CASO EN EL QUE LA LISTA ESTE VACIA
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr)
    { // EL SIGUIENTE DEL AUXILIAR TIENE QUE SER SI O SI NULL
        aux = aux->getSiguiente();
    }
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T>
void Lista<T>::remover(int pos)
{
    Nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;
    if (pos == 0)
    {
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }

    while (posActual < pos - 1)
    {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
    {
        throw 404;
    }

    aBorrar = aux->getSiguiente();
    aux->setSiguiente(aBorrar->getSiguiente());
    delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T>
T Lista<T>::getDato(int pos)
{
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos - 1)
    {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
    {
        throw 404;
    }

    return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 **/
template <class T>
void Lista<T>::reemplazar(int pos, T dato)
{
    Nodo<T> *aux = inicio;
    int posActual = 0;

    while (aux != nullptr && posActual < pos - 1)
    {
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr)
        throw 404;

    aux->setDato(dato);
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 **/
template <class T>
void Lista<T>::vaciar()
{
    Nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;

    while (aux != nullptr)
    {
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }
    if (aux == nullptr)
    {
        throw 404;
    }
    inicio = nullptr;
}

/*
 * Implementar la función fnInvierte(lista).
 * Esta función invertirá el orden original de los elementos en la lista,
 * de tal forma que el último elemento será ahora el primero, el penúltimo será el segundo,
 * y así hasta que el primero sea el último. Considere que la lista no está vacía y que no se construirá una nueva,
 * sólo se invertirá el orden de los elementos de la lista original.
 */

template <class T>
void Lista<T>::fnInvierte()
{
    Nodo<T> *aux = inicio, *anterior = nullptr, *siguiente = inicio;

    if (esVacia())
    {
        return;
    }
    siguiente = siguiente->getSiguiente();

    while (siguiente != nullptr)
    {
        aux->setSiguiente(anterior);
        anterior = aux;
        aux = siguiente;
        siguiente = siguiente->getSiguiente();
    }
    aux->setSiguiente(anterior);
    inicio = aux;
}

template <class T>
void Lista<T>::imprimir()
{
    Nodo<T> *aux = inicio;
    while (aux != nullptr)
    {
        cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

template <class T>
void Lista<T>::insertAfter2(int oldvalue, int newValue, int n)
{
    int cont = 0;
    Nodo<T> *aux = inicio;
    while (aux != nullptr || cont < n)
    {
        if (aux->getDato() == oldvalue)
        {
            cont++;
            if (cont == n)
                break;
        }
        aux = aux->getSiguiente();
    }
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(newValue);
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

template <class T>
void Lista<T>::unirlistas(Lista<T> &lista2)
{
    Nodo<T> *aux = inicio;
    Nodo<T> *aux2 = lista2.inicio;
    int tam = lista2.getTamanio();

    while (aux->getSiguiente() != nullptr)
    {
        aux = aux->getSiguiente();
    }

    for (int i = 0; i < tam; i++)
    {
        aux->setSiguiente(aux2);
        aux = aux->getSiguiente();
        aux2 = aux->getSiguiente();
    }

    return;
}

template <class T>
void Lista<T>::moverNodo(int pos)
{
    Nodo<T> *aux1 = inicio;
    Nodo<T> *aux2 = inicio;
    int posActual = 0;
    while (aux1 != nullptr && posActual < pos)
    {
        posActual++;
        aux1 = aux1->getSiguiente();
    }
    posActual = 0;
    while (aux2 != nullptr && posActual < pos - 1)
    {
        posActual++;
        aux2 = aux2->getSiguiente();
    }
    aux2->setSiguiente(aux1->getSiguiente());
    aux1->setSiguiente(inicio);
    inicio = aux1;
}

template <class T>
void Lista<T>::borrarDato(T dato)
{
    Nodo<T> *aux = inicio;
    int pos = 0;
    while (aux != nullptr)
    {
        if (aux->getDato() == dato)
        {
            this->remover(pos);
            aux = inicio;
            pos = 0;
        }
        aux = aux->getSiguiente();
        pos++;
    }
}

template <class T>
void Lista<T>::moverUltimo(int pos)
{
    Nodo<T> *prev = inicio, *actual = inicio, *ultimo = inicio;
    int posActual = 0;

    while (ultimo->getSiguiente() != nullptr)ultimo = ultimo->getSiguiente();
        
    if(pos==0){
        ultimo->setSiguiente(inicio);
        inicio=inicio->getSiguiente();
        actual->setSiguiente(nullptr);
    }

    while (actual != nullptr && posActual < pos)
    {
        actual = actual->getSiguiente();
        posActual++;
    }

    posActual = 0;
    while (actual != nullptr && posActual < pos - 1)
    {
        prev = prev->getSiguiente();
        posActual++;
    }
    prev->setSiguiente(actual->getSiguiente());
    ultimo->setSiguiente(actual);
    actual->setSiguiente(nullptr);
}
#endif LISTA_H
