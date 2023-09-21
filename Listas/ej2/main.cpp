#include <iostream>
#include "../../Cola/Lista.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Lista<int> lista;
    int n, dato, pos;
    cout << "Decime cuantas posiciones va a tener la lista" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dato;
        lista.insertarUltimo(dato);
    }
    cout << "Decime en que posicion" << endl;
    cin >> pos;
    lista.imprimir();
    lista.moverUltimo(pos);
    lista.imprimir();
    return 0;
}
