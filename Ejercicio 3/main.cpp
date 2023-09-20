#include <iostream>
#include "../Cola/Cola.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Cola<int> cola;
    int dato, datoNuevo, n;
    cout << "Decime cuantas posiciones va a tener la cola" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dato;
        cola.encolar(dato);
    }
    cola.imprimir();
    cout << "Decime el dato viejo,el dato nuevo,y cuantas veces se deberia repetir el viejo" << endl;
    cin >> dato;
    cin >> datoNuevo;
    cin >> n;
    cola.encolarNuevoConCola(dato, datoNuevo, n);
    cola.imprimir();
    return 0;
}
