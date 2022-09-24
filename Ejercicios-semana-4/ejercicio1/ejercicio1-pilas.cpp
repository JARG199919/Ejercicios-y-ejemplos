#include <iostream>
#include <conio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>

using namespace std;

struct pilas
{
    int aux;
    pilas *arreglo;
} * cel, *ext;


void pilasEJE();
void ingresar();
void sacar();
void actualizar_pila();

main()
{
    pilasEJE();
}


void pilasEJE()
{
    int y, opc;
    for (;;)
    {
        cout << "\n1. Ingresar datos"
             << "\n2. Sacar datos"
             << "\n0. Terminar"
             << "\n\nIngrese opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            ingresar();
            system("cls");
            //cout<<"Datos ingresados"<<endl;
            break;
        case 2:
            system("cls");
            sacar();
            break;
        case 0:
            exit(1);
        default:
            system("cls");
            cout << "\nOpcion no valida!!\n";
            break;
        }
        actualizar_pila();
        cout << "\nOprima una tecla para continuar\n";
        getch();
    }
}

void ingresar()
{
    if (!cel)
    {
        /*c = new (pilas);
        cout << "Ingrese elemento: ";
        cin >> c->aux;
        c->arreglo = NULL;
        return;*/
    }

    ext = new (pilas);
    cout << "\nIngrese elemento: ";
    cin >> ext->aux;
    ext->arreglo = cel;
    cel = ext;
}

void sacar()
{
    if (!cel)
    {
        cout << "\n\nNo hay elementos!!";
        return;
    }

    ext = new (pilas);
    ext = cel;
    cout << "\n\nElemento eliminado: "<< ext->aux;
    cel = ext->arreglo;
    delete (ext);
}
void actualizar_pila()
{
    int y = 2, i, ca = 0;
    ext = cel;
    while (ext)
    {
        ca++;
        ext = ext->arreglo;
    }

    for (i = 0; i <= ca; i++)
    {
        cout << " ";
    }
    // muestro lo que tiene la pila!!
    i = 0;
    ext = cel;
   
    while (ext)
    {
        cout << "\n";
        cout << ++i << " - " << ext->aux;
        ext = ext->arreglo;
    }
}