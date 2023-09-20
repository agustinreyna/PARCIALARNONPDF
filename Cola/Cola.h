#ifndef COLA_H_
#define COLA_H_
#include "Nodo.h"

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T>
class Cola
{
private:
    Nodo<T> *tope, *fondo;
    int cantPrioridad = 0;

public:
    Cola();

    ~Cola();

    void encolar(T dato);

    T desencolar();

    bool esVacia();

    T peek();

    void encolarConPrioridad(T dato, int prioridad);

    int getCantPrioridad();

    void encolarNuevo(T dato, T datoNuevo, int n);

    void encolarNuevoConCola(T dato, T datoNuevo, int n);

    void imprimir();
};

template <class T>
int Cola<T>::getCantPrioridad()
{
    return cantPrioridad;
}

/**
 * Tomo el valor del tope
 */
template <class T>
T Cola<T>::peek()
{
    if (esVacia())
    {
        throw 404;
    }
    return tope->getDato();
}

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T>
Cola<T>::Cola()
{
    tope = nullptr;
    fondo = nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T>
Cola<T>::~Cola()
{
    while (!esVacia())
    {
        desencolar();
    }
    delete tope;
    delete fondo;
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T>
void Cola<T>::encolar(T dato)
{
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    nuevo->setSiguiente(nullptr);

    if (esVacia())
    {
        tope = nuevo;
    }
    else
    {
        fondo->setSiguiente(nuevo);
    }
    fondo = nuevo;
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T>
T Cola<T>::desencolar()
{
    if (esVacia())
    {
        throw 404;
    }
    T dato = tope->getDato();
    Nodo<T> *aBorrar = tope;
    tope = tope->getSiguiente();

    if (tope == nullptr)
    { // En caso de q el tope sea el último
        fondo = nullptr;
    }

    delete aBorrar;
    return dato;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T>
bool Cola<T>::esVacia()
{
    return tope == nullptr || fondo == nullptr; // El profe coloco 1 nomas.
}

template <class T>
void Cola<T>::encolarConPrioridad(T dato, int prioridad)
{
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    nuevo->setSiguiente(nullptr);

    if (esVacia())
    {
        tope = nuevo;
        fondo = nuevo;
        return;
    }

    if (prioridad == 0)
    {
        nuevo->setSiguiente(tope);
        tope = nuevo;
        cantPrioridad++;
        return;
    }

    Nodo<T> *temp = tope;
    while (temp->getSiguiente() != nullptr && prioridad > 1)
    {
        temp = temp->getSiguiente();
        prioridad--;
    }

    nuevo->setSiguiente(temp->getSiguiente());
    temp->setSiguiente(nuevo);
    if (temp == fondo)
    {
        fondo = nuevo;
    }
}

template <class T>
void Cola<T>::encolarNuevo(T dato, T datoNuevo, int n)
{
    Nodo<T> *nuevoNodo = new Nodo<T>;
    nuevoNodo->setDato(datoNuevo);
    Nodo<T> *aux = tope;
    int cont = 0;

    while (aux != nullptr && cont != n)
    {
        if (aux->getDato() == dato)
            cont++;
        if (cont == n)
            break;
        aux = aux->getSiguiente();
    }

    if (aux == nullptr)
        throw 404;

    nuevoNodo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevoNodo);
}

template <class T>
void Cola<T>::imprimir()
{
    Nodo<T> *aux = tope;
    if (tope == nullptr || fondo == nullptr)
    {
        cout << "La cola esta vacia" << endl;
        return;
    }
    while (aux != nullptr)
    {
        cout << aux->getDato();
        cout << "->";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}

template <class T>
void Cola<T>::encolarNuevoConCola(T dato, T datoNuevo, int n)
{
    Nodo<T> *nuevoNodo = new Nodo<T>;
    nuevoNodo->setDato(datoNuevo);
    Nodo<T> *aux = tope;
    int cont = 0;
    Cola<T> colaAux;

    while (!this->esVacia() && cont != n)
    {

        if (aux->getDato() == dato)
            cont++;
        aux = aux->getSiguiente();
        colaAux.encolar(this->desencolar());
    }

    colaAux.encolar(datoNuevo);

    while (!this->esVacia())
    {

        colaAux.encolar(this->desencolar());
    }
    this->imprimir();
    Nodo<T> *aux2 = colaAux.tope;
    while (!colaAux.esVacia())
    {

        this->encolar(colaAux.desencolar());
    }
    return;
}
#endif // COLA_H_