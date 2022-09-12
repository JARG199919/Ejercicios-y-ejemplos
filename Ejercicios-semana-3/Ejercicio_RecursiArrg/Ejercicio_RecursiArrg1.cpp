#include <iostream>
#include <stdio.h>

using namespace std;

int **arreglo, numIN, numeroMenu = 0, numFilas, numColumnas, num, inpp, aux, contar = 0, minimoNum, *arreglo1;
int factorial(int);
void arreglosDinamicos();
void arreglosOrdenamiento();

int main()
{
    do
    {
        system("cls");

        cout << "Opciones: \n1.Factorial !\n2.Mostrar una matriz\n3.Ordenamiento de numeros" << endl;
        cin >> numeroMenu;
        switch (numeroMenu)
        {
        case 1:

            cout << "Eleccion de Factorial \nIngrese la inicializacion: " << endl;
            cin >> numIN;
            cout << "\nSolucion Recursiva: " << factorial(numIN) << endl;
            return 0;
        case 2:
            cout << "Eleccion de Tabla :" << endl;
            arreglosDinamicos();
            break;

        case 3:
            arreglo1 = new int[num];
            cout << "Eleccion de Ordenamiento" << endl;
            arreglosOrdenamiento();
            break;
        default:
            cout << "Ingrese un numero Valido " << endl;
            break;
        }
    } while (numeroMenu != 3);
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
void arreglosDinamicos()
{

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
    // Capturar los datos
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            // cout<<"Ingresa valores de filas y columnas";
            // cin>>*(*(arreglo+i)+j);
            arreglo[i][j] = 1 + rand() % 9;
        }
    } // Agregar un multiplicador,un promedio, suma, y ordenamiento

    // Mostrar datos
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            cout << "|" << *(*(arreglo + i) + j) << "|";
        }
        cout << endl;
    }

    // Liberacion de memoria
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            delete[] arreglo[i];
        }
    }
    delete[] arreglo;
}
void arreglosOrdenamiento()
{
    system("cls");
    cout << "Ingrese el tamano del arreglo (Max 9)\n";
    cin >> num;
    if (num > 10 || num < 1)
    {
        cin >> num;
    }
    do
    {
        system("cls");
        cout << "Los datos de el arreglo desea\n1.ingresarlos\n2.Aleatorios\n";
        cin >> inpp;
        switch (inpp)
        {
        case 1:
            system("cls");
            for (int i = 0; i < num; i++)
            {
                contar++;
                printf("Ingrese el %d de la cantidad:", contar);
                cin >> arreglo1[i];
            }

            break;

        case 2:
            int max, min;
            system("cls");
            cout << "Ingrese el valor minimo (limite -200k digitos):";
            cin >> min;
            system("cls");
            cout << "Ingrese el valor maximo proximado(limite 200k digitos):";
            cin >> max;
            system("cls");
            cout << "El valor aleatorio se escogio: \n";
            for (int i = 0; i < num; i++)
            {
                arreglo1[i] = min + rand() % max;
                cout << arreglo1[i] << " ";
            }

            break;

        default:
            system("cls");
            cout << "Ingrese un numero valido"<<endl;
            system("PAUSE");
            
        }
    }while (inpp != 2); 

    for (int i = 0; i < num; i++)
    {
        // Hipotesis, que el primer valor del arreglo es el menor
        minimoNum = i;
        // Segundo recorrido se inicia en la segunda posición
        for (int j = i + 1; j < num; j++)
        {
            // Comparación entre elemento actual con el primer valor que se estableció como menor
            if (arreglo1[j] < arreglo1[minimoNum])
            {
                // Establecer el elemento actual como el menor valor
                minimoNum = j;
            }
        }
        // Intercambio de valores del arreglo
        aux = arreglo1[i];
        arreglo1[i] = arreglo1[minimoNum];
        arreglo1[minimoNum] = aux;
    }

    cout << "\nEl orden final en modo seleccion es: \n";
    for (int i = 0; i < num; i++)
    {
        cout << arreglo1[i] << " ";
    }
}