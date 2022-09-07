#include <iostream>
#include <stdio.h>


using namespace std;

int **arreglo, numIN,numeroMenu=0,numFilas, numColumnas;

int factorial(int);
void arreglosDinamicos();

int main()
{

    cout << "Opciones: \n1.Factorial !\n2.Mostrar una matriz " << endl;
    cin >> numeroMenu;
    

    switch (numeroMenu)
    {
    case 1:
        cout << "Eleccion de Factorial \nIngrese la inicializacion: " << endl;
        cin >> numIN;
        cout << "\nSolucion Recursiva: " << factorial(numIN) << endl;
        break;
    case 2:

        arreglosDinamicos();
        break;

    default:
        cout << "Ingrese un numero Valido "<<endl;
       break;
    
    }

   return 0;
   
}

// Recursiva
int factorial(int n)
{ // cálculo de n!
    // Condición de salida

    if (n <= 1)
    {
        cout << n << " = ";
        return 1;
    }
    else

        cout << n << " x ";
    // Se realiza el llamado a la función nuevamente
    return n * factorial(n - 1);
}
void arreglosDinamicos(){
    
    cout << "Ingresa el numero de filas: ";
    cin >> numFilas;
    cout << "Ingresa el numero de columnas: ";
    cin >> numColumnas;
    // Reserva de memoria
    arreglo = new int *[numFilas];
    for (int i = 0; i < numFilas; i++)
    {
        arreglo[i] = new int[numColumnas];
    }
    //Capturar los datos 
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            //cout<<"Ingresa valores de filas y columnas";
            //cin>>*(*(arreglo+i)+j);
            arreglo[i][j]=1 + rand() %9;
        }
    //Agregar un multiplicador,un promedio, suma, y ordenamiento
    
    //Mostrar datos
        for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        { 
            cout<<"|"<<*(*(arreglo+i)+j)<<"| ";
        }
        cout<<endl;
    }

    //Liberacion de memoria
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            delete[]arreglo[i];
        }
        
    }
        delete[]arreglo;
}
