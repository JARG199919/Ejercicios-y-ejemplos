#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int num, inpp;

int main()
{
    int arreglo[num], aux, contar = 0, pos;
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
        cout << "Ingrese el valor minimo(limite -200k digitos):";
        cin >> min;
        system("cls");
        cout << "Ingrese el valor maximo(limite 200k digitos):";
        cin >> max;
        system("cls");
        cout << "El valor aleatorio se escogio: \n";
        for (int i = 0; i < num; i++)
        {
            arreglo[i] = min + rand() % max;
            cout << arreglo[i] << " ";
        }

        break;

    default:
        cout << "Ingrese un numero valido";
    }
    for (int i = 0; i < num; i++)
    { // posición actual
        pos = i;
        // Comparación con el número de la izquierda
        aux = arreglo[i];

        while ((pos > 0) && (arreglo[pos - 1] > aux))
        {
            // Cambio con el número de la izquierda
            arreglo[pos] = arreglo[pos - 1];
            // Iteraciones hacia atras
            pos--;
        }
        // Refrescar cada iteración
        arreglo[pos] = aux;
    }

    cout << "\nEl orden final en modo Incercion es: \n";
    for (int i = 0; i < num; i++)
    {
        cout << arreglo[i] << " ";
    }
    return 0;
}