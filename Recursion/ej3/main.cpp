#include <iostream>
using namespace std;

 int sumaPares(int A[], int suma, int n){
    if(n==0){
        return suma;
    }else{
        if(A[n]%2==0)suma=suma+A[n];
        return sumaPares(A,suma,n-1);
    }
}

int main() {
    int N[100], tam, n;
    int suma=0;
    cout<<"Ingrese el tamanio del arreglo"<<endl;
    cin>>tam;
    for(int i=0; i<tam; i++){
        cout<<"Ingrese el dato"<<endl;
        cin>>N[i];
    }
    cout<<"Decime el n"<<endl;
    do{
        cin>>n;
        if(n%2!=0){
            cout<<"El numero ingresado es impar, no es valido"<<endl;
        }
    }while(n%2!=0);
    cout<<"La suma es "<<sumaPares(N,suma, n-1);
    return 0;
}
