#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

struct Nodo *lista = NULL;

// Declaración de funciones
void Insertar(int n);
void Imprimir();
void EliminarInicio();
void EliminarFinal();

int main()
{
    Insertar(10);
    Insertar(5);
    Insertar(40);
    Insertar(85);
    Imprimir();
    EliminarInicio();
    EliminarFinal();
    Imprimir();

    return 0;
}

// Insertar nodos a la lista
void Insertar(int n)
{

    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    if (nuevoNodo != NULL)
    {
        nuevoNodo->dato = n;
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

void EliminarInicio()
{
    struct Nodo *temporal = lista;
    //Si en la lista se encuentran elementos
    if (lista != NULL)
    {
        //Borra el elemento
        lista = lista->siguiente;
        //Libera la memoria
        delete temporal;
    }
    else
    {
        cout << "Lista vacia";
    }
}

void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != NULL)
    {
        //Si el nodo no es el ultimo
        if (temporal->siguiente != NULL)
        {
            //Se realiza la iteraciones hasta encontra el ultimo nodo que apunte a NULL
            while (temporal->siguiente != NULL)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            //Almacena el penultimo nodo sera quien apunte NULL
            temporal2->siguiente = NULL;
            //Se libera la memoria del nodo ultimo 
            delete temporal;
            temporal = NULL;
        }
        else//Si unicamente se encontraba un nodo en la lista
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
    if (lista != NULL)
    {
        while (temporal != NULL)
        {
            cout << "Lista " << temporal->dato << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}