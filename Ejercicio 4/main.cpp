#include <iostream>
using namespace std;

void ordenar(int n){
    if(n<10)cout<<n;
    else {
        cout<<n%10;
        return ordenar(n/10);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Decime el numero"<<endl;
    cin>>n;
    cout<<"El numero invertido es: ";
    ordenar(n);
    return 0;
}
