#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    // Arreglo bidimensional 
    /*    int arreglo[3][2]={{1,2},{4,5},{8,9}};

       for (int i = 0; i < 3; i++)
       {
        for (int j = 0; j < 2; j++)
        {
            cout<<arreglo[i][j];
        }
        cout<<endl;
       } */

    // Punteros doble, arreglo dinámico
    int numFilas, numColumnas;
    int **ptr;

    cout << "Ingresa el numero de filas";
    cin >> numFilas;
    cout << "Ingresa el numero de columnas";
    cin >> numColumnas;
    // Reserva de memoria
    ptr = new int *[numFilas];
    for (int i = 0; i < numFilas; i++)
    {
        ptr[i] = new int[numColumnas];
    }
    //Capturar los datos 
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            cout<<"Ingresa valores de filas y columnas";
            cin>>*(*(ptr+i)+j);
        }
    }
    
    //Mostrar datos
        for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        { 
            cout<<*(*(ptr+i)+j);
        }
        cout<<endl;
    }

    //Liberacion de memoria
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            delete[]ptr[i];
        }
        
    }
        delete[]ptr;



    return 0;
}