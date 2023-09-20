#include <iostream>
using namespace std;

int menor(int array[], int men, int tam)
{
    if (tam == 0)
        return men;
    else if (array[tam] < men)
        men = array[tam];
    return menor(array, men, tam - 1);
}

int main(int argc, char const *argv[])
{
    int array[100], men, tam;
    cout << "Decime el tamanio del arreglo" << endl;
    cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        cout << "Decime el valor del arreglo en la posicion " << i + 1 << ": ";
        cin >> array[i];
        cout << endl;
    }
    men = array[0];
    cout << "El valor menor del arreglo es: " << menor(array, men, tam);
    return 0;
}
