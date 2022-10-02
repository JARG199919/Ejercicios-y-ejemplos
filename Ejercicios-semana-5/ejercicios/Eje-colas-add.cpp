#include <iostream>
#include <conio.h>

using namespace std;
// Variable global
int valor, menu, adicional/*Por si acaso se agrega mas variables*/, contar = 0;

struct Nodo
{
    int dato;
    
    struct Nodo *siguiente;
};
struct Nodo *frenteCola = NULL;
struct Nodo *finalCola = NULL;

// Declaracion de funciones
bool Vacia();
void Insertar(int);
int Eliminar(int &);
void Imprimir();
void principal();

/*void ImprimirFrente();
void ImprimirFinal();*/

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
            // cout<<"\nInicio de cola: "<<ImprimirFrente<<endl;
            // cout<<"\nFinal de cola: "<<ImprimirFinal<<endl;
            cout << "\nOprima una tecla para continuar\n";
            getch();
            break;
        case 3:
            system("cls");
            Eliminar(valor);
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
// Operación vacia
bool Vacia()
{
    if (frenteCola == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Encolar -- final de la lista
void Insertar(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Asignacion del valor que ingresa el usuario
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = NULL;
    if (Vacia())
    {
        frenteCola = nuevoNodo;
    }
    else
    {
        finalCola->siguiente = nuevoNodo;
    }
    // Se establece el final de la cola con el nuevo nodo agregado
    finalCola = nuevoNodo;
}

// Desencolar -- inicio de la lista
int Eliminar(int &n)
{
    if (!Vacia())
    {
        n = frenteCola->dato;
        struct Nodo *temporal = frenteCola;
        if (frenteCola == finalCola)
        {
            frenteCola = NULL;
            finalCola = NULL;
        }
        else
        {
            frenteCola = frenteCola->siguiente;
        }
        cout << "Elemento eliminado: " << n << "\n";
        delete temporal;
        return n;
    }
    else
    {
        cout << "No se encontro nungun elemento...";
        return -1;
    }
}

// Imprimir elementos de la cola
void Imprimir()
{
    contar = 0;
    struct Nodo *temporal = frenteCola;
    while (temporal != NULL)
    {
        contar++;
        cout << contar << ".Elementos de la cola " << temporal->dato << endl;
        temporal = temporal->siguiente;
    }
}

/*// Frente, imprimir elemento del frente de la cola
void ImprimirFrente()
{
    struct Nodo *temporal = frenteCola;
    if (temporal != NULL)
    {
        cout << "Frente cola" << temporal->dato;
    }
}

// Final, imprimir elemento del final de la cola
void ImprimirFinal()
{
    struct Nodo *temporal = finalCola;
    if (temporal != NULL)
    {
        cout << "Final cola" << temporal->dato;
    }
}*/