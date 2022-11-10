#include <iostream>

using namespace std;
struct Nodo
{
    string datos;
    struct Nodo *siguiente;
};

struct Nodo *lista = NULL;

// Declaración de funciones
void Insertar(string n);
void Imprimir();
void eliminarNodo(Nodo **cabeza, string dato);


int main()
{
    Insertar("papa");
    Insertar("Tasa");
    Insertar("Casa");
    Insertar("Vista");
    Imprimir();
    cout<<"--------------------\n\n";
    eliminarNodo(&lista,"Casa");
    Imprimir();

    return 0;
}

// Insertar nodos a la lista
void Insertar(string n)
{

    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    if (nuevoNodo != NULL)
    {
        nuevoNodo->datos = n;
        nuevoNodo->siguiente = NULL;
        // Si la lista esta vacia se agrega el primer nodo
        if (lista == NULL)
        {
            lista = nuevoNodo;
        }
        else
        {
            // Agregar un nodo al final
            while (temporal->siguiente != NULL)
            {
                temporal = temporal->siguiente;
            }
            temporal->siguiente = nuevoNodo;

            // Agregar un nodo al inicio
            /*    nuevoNodo->siguiente = lista;
               lista = nuevoNodo; */
        }
    }
    else
    {
        cout << "No se pueden agregar mas nodos";
    }
}


void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != NULL)
    {
        while (temporal != NULL)
        {
            cout << "Lista " << temporal->datos << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}


void eliminarNodo(Nodo **cabeza, string dato)
{
    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;
    while ((actual != NULL) && (actual->datos != dato))
    {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL)
    {
        if (*cabeza == NULL)
            cout << "la lista esta vacia\n";
        else
            cout << "Nose encontro el elemento\n";
    }
    else
    {
        if (*cabeza == actual)
        {
            *cabeza = actual->siguiente;
        }
        else
        {
            anterior->siguiente = actual->siguiente;
            delete actual;
        }
    }
}