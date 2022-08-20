#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int num, inpp;

int main()
{
    int arreglo[num];
    int aux, contar = 0,minimoNum;
    system("cls");
    cout << "Ingrese el tamano del arreglo (Max 9)\n";
    cin >> num;
    if (num > 10 || num < 1 ){
       cin >> num;
    }
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
            cin >> arreglo[i];
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
            arreglo[i] = min + rand() % max;
            cout << arreglo[i] << " ";
        }

        break;

    default:
        cout << "Ingrese un numero valido";
    }
    
    for (int i = 0; i < num; i++)
    {
        //Hipotesis, que el primer valor del arreglo es el menor
        minimoNum = i;
        //Segundo recorrido se inicia en la segunda posición
        for (int j = i + 1; j < num; j++)
        {
            //Comparación entre elemento actual con el primer valor que se estableció como menor
            if(arreglo[j]<arreglo[minimoNum]){
                //Establecer el elemento actual como el menor valor
                minimoNum = j;
            }
        }
        //Intercambio de valores del arreglo
        aux = arreglo[i];
        arreglo[i]=arreglo[minimoNum];
        arreglo[minimoNum] = aux; 
    }

    cout << "\nEl orden final en modo selecion es: \n";
    for (int i = 0; i < num; i++)
    {
        cout << arreglo[i] << " ";
    }
    return 0;
}