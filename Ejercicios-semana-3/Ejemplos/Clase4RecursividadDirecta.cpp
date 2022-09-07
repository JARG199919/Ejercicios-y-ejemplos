#include <iostream>

using namespace std;
void cuentaRegresiva(int);

int main(){

    cuentaRegresiva(10);
    
    return 0;
}

//Recursividad directa 
void cuentaRegresiva(int n){
    //Caso base
    if(n>0){
        cout<<n;
        cuentaRegresiva(n-1);
    }else if(n<0){
        cout<<"El numero es menor que 0";
    }
}

