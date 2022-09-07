#include <iostream>

using namespace std;

int main()
{

    // Punteros y arreglos
    // Declaración de punteros
    int arreglo[] = {1, 2, 4};
    // Accediendo a una posición
    cout << arreglo[2] << endl;
    //Dirección de memoria 
    cout<<&arreglo[2]<<endl;
    // Accediendo a la posición con punteros
    cout << *(arreglo + 2) << endl;
    // Dirección de memoria
    cout << arreglo << endl;

    // Todo array es un puntero
    int *ptr = arreglo;
    cout << ptr<<endl;
    // Accediendo a una posición
    cout << ptr[2] << endl;
    // Accediendo a la posición con punteros
    cout << *(ptr + 2) << endl;

    for (int i = 0; i < 3; i++)
    {
        cout<<"Elementos del arreglo "<<arreglo[i]<<endl;
        cout<<"Posición de memoria de cada elemento "<<arreglo[i]<<ptr++<<endl;
    }
    
    

    return 0;
}