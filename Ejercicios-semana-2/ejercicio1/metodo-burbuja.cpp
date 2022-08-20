#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int num, inpp;

int main()
{
    int arreglo[num], aux, contar = 0;
    system("cls");
    cout << "Ingrese el tamano del arreglo";
    cin >> num;
    cout << "Los datos de el arreglo desea\n1.ingresarlos\n2.Aleatorios";
    cin >> inpp;
    switch (inpp)
    {
    case 1:
        system("cls");
        for (int i = 0; i < num; i++)
        {
            contar++;
            printf("Ingrese el %d de la cantidad:", contar);
            cin >> arreglo[i];
        }

        break;

    case 2:
        int max, min;
        system("cls");
        cout << "Ingrese el valor minimo(limite -2M digitos):";
        cin >> min;
        system("cls");
        cout << "Ingrese el valor maximo(limite 2M digitos):";
        cin >> max;
        system("cls");
        cout<<"El valor aleatorio se escogio: \n";
        for (int i = 0; i < num; i++)
        {
            arreglo[i] = min + rand() % max;
            cout<<arreglo[i]<<" ";
        }

        break;

    default:
        cout << "Ingrese un numero valido";
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (arreglo[j] > arreglo[j + 1])
            {
                aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
            }
        }
    }
    cout << "\nEl orden final en modo Burbuja es: \n";
    for (int i = 0; i < num; i++)
    {
        cout << arreglo[i] << " ";
    }
    return 0;
}
