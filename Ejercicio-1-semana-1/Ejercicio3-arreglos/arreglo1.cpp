#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int numero, in1, proceso, contar;

int main()
{
    int arreglo[numero];
    system("cls");
    printf("Operaciones con arreglos de una fila. \n Ingrese la cantidad de filas a guardar: ");
    cin >> numero;
    for (int i = 0; i < numero; i++)
    {
        contar++;
        printf("\nIngresa la %d cantidad: ", contar);
        cin >> arreglo[i];
    }
    contar = 0;
    system("cls");
    printf("Con los datos ingresados que desea hacer.\n1.Sumar\n2.Resta\n3.Multiplicacion\n");
    cin >> in1;
    system("cls");

    switch (in1)
    {
    case 1:
        printf("Selecion suma\n");
        for (int i = 0; i < numero; i++)
        {
            contar++;
            printf("Numero Ingresado %d: %d\n", contar, arreglo[i]);
            proceso += arreglo[i];
        }
        printf("La suma de todo el arreglo es: %d", proceso);
        break;
    case 2:
        proceso = arreglo[0];
        printf("Selecion resta\n");
        for (int i = 0; i < numero; i++)
        {
            contar++;

            printf("Numero Ingresado %d: %d\n", contar, arreglo[i]);
            proceso = proceso - arreglo[i];
        }
        proceso = proceso + arreglo[0];
        printf("La resta de todo el arreglo es: %d", proceso);
        break;
    case 3:
        proceso = 1;
        printf("Selecion Multiplicacion\n");
        for (int i = 0; i < numero; i++)
        {
            contar++;
            printf("Numero Ingresado %d: %d\n", contar, arreglo[i]);
            proceso *= arreglo[i];
        }
        printf("La Multiplicacion de todo el arreglo es: %d", proceso);
        break;
    default:
        printf("Ingrese un numero valido");
    }
    return 0;
}
