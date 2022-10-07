#include <iostream>
#include <conio.h>

using namespace std;

// Variable global,
int inserMen, menu;
float valor;

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

struct Nodo *lista = NULL;

// Declaración de funciones
void principal();
void Insertar(float n);
void Imprimir();
void Eliminar();
void EliminarInicio();
void EliminarFinal();

int main()
{

    principal();

    return 0;
}

void principal()
{
    do
    {
        system("cls");
        menu = 0;
        cout << "Menu: \n\n1.Ingresar valor\n2.Ver cola\n3.Eliminar valor\n4.Salir\n\n";
        cin >> menu;

        switch (menu)
        {
        case 1:
            system("cls");
            cout << "Ingresar valor: ";
            cin >> valor;
            Insertar(valor);
            break;
        case 2:
            system("cls");
            Imprimir();
            cout << "\nOprima una tecla para continuar\n";
            getch();
            break;
        case 3:
            system("cls");
            Eliminar();
            cout << "\nOprima una tecla para continuar\n";
            getch();
            break;
        case 4:
            exit(1);
        default:
            cout << "\nIngrese un valor valido...";
            getch();
        }

    } while (menu != 4);
}

// Insertar nodos a la lista ,inicio o final
void Insertar(float n)
{
    system("cls");
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    inserMen = 0;

    cout << "\nValor a Ingresar: " << n << "\n\n1. Ingresar valor al inicio\n2. Ingresar valor al final\n";
    cin >> inserMen;

    switch (inserMen)
    {
    case 1:

        if (nuevoNodo != NULL)
        {
            nuevoNodo->dato = n;
            nuevoNodo->siguiente = NULL;
            nuevoNodo->anterior = NULL;
            // Si la lista esta vacia
            if (lista == NULL)
            {
                lista = nuevoNodo;
            }
            else
            {

                nuevoNodo->siguiente = lista;
                lista->anterior = nuevoNodo;
                lista = nuevoNodo;
            }
        }
        else
        {
            cout << "No se pueden agregar mas nodos";
        }
        break;
    case 2:

        if (nuevoNodo != NULL)
        {
            nuevoNodo->dato = n;
            nuevoNodo->siguiente = NULL;
            nuevoNodo->anterior = NULL;
            // Si la lista esta vacia
            if (lista == NULL)
            {
                lista = nuevoNodo;
            }
            else
            {
                while (temporal->siguiente != NULL)
                {
                    temporal = temporal->siguiente;
                }
                temporal->siguiente = nuevoNodo;
                nuevoNodo->anterior = temporal;
            }
        }
        else
        {
            cout << "No se pueden agregar mas nodos";
        }
        break;

    default:
        cout << "Ingreso un valor valido!.\nPresione cualquier boton para continuar... \n";
        getch();
        return Insertar(n);
    }
}
// Menu para elegir si borrar inicio o al final
void Eliminar()
{

    inserMen = 0;
    system("cls");
    cout << "1. Eliminar valor del inicio\n2. Eliminar valor del final\n";
    cin >> inserMen;

    switch (inserMen)
    {
    case 1:
        EliminarInicio();
        break;
    case 2:
        EliminarFinal();
        break;
    default:
        cout << "Ingrese un valor valido: \n";
        getch();
        return Eliminar();
    }
}
// Borrar el ultimo de la lista
void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2 = NULL;

    if (lista != NULL)
    {
        if (temporal->siguiente != NULL)
        {
            while (temporal->siguiente != NULL)
            {
                temporal = temporal->siguiente;
            }

            temporal2 = temporal->anterior;
            temporal2->siguiente = NULL;
            delete temporal;
        }
        else
        {
            delete lista;
            lista = NULL;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}

// Borrar el primero de la lista
void EliminarInicio()
{
    struct Nodo *temporal = lista;

    if (lista != NULL)
    {
        if (temporal->siguiente != NULL)
        {
            lista = lista->siguiente;
            delete temporal;
            lista->anterior = NULL;
        }
        else
        {
            delete lista;
            lista = NULL;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (temporal != NULL)
    {
        while (temporal != NULL)
        {
            cout << "Lista " << temporal->dato << " Direccion " << temporal << " siguiente " << temporal->siguiente << " anterior " << temporal->anterior << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}
