#include <iostream>
#include "../Cola/Lista.h"
using namespace std;

int main()
{
    Lista<int> lista;
    int n, valor;
    cout << "Ingrese el tamanio de la lista" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << " de la lista" << endl;
        cin >> valor;
        lista.insertarUltimo(valor);
    }
    cout << "Ingrese la posicion" << endl;
    cin >> n;
    lista.moverNodo(n);
    lista.imprimir();
}