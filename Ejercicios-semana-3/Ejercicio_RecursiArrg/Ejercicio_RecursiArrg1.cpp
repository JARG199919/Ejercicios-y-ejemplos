#include <iostream>
#include <stdio.h>


using namespace std;

int **arreglo, numIN,numeroMenu=0;

int factorial(int);

int main()
{

    cout << "Opciones: \n1.Factorial !\n2.Ingresar " << endl;
    cin >> numeroMenu;
    

    switch (numeroMenu)
    {
    case 1:
        cout << "Eleccion de Factorial \nIngrese la inicializacion: " << endl;
        cin >> numIN;
        cout << "\nSolucion Recursiva: " << factorial(numIN) << endl;
        break;
    case 2:
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
