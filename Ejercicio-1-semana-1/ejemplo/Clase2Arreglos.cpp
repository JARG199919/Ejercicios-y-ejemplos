#include <iostream>

using namespace std;


int main(){
    //Arreglos, declaración, asignación, cambio de valor a traves de indice, recorrido 
    //Declaración e inicialización del arreglo/array

    //Actividad, solicitar al usuario el tamaño y los valores del arreglo, convertir a función el recorrido y suma del mismo
    int listado [] = {4,5,2,6,3};
    int sumaArreglo;
    
    //cout<<listado[1]<<endl;
    //Accediendo a una posición
    listado[1] = 8;
   // cout<<listado[1];

    //Obtener el numero de valores de un arreglo/array
    int tam = sizeof(listado)/sizeof(int);
    cout<<tam<<endl;

  //Recorrer el arreglo 
    for (int i = 0; i < tam; i++)
    {
        cout<<"Listado "<<listado[i]<<endl;
        sumaArreglo += listado[i];
        
    } 
    cout<<"El resultado total "<<sumaArreglo;






    return 0;
}
