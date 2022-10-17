#include <iostream>
#include <conio.h>

using namespace std;

int inserMen, menu, valor;
string nombre;

struct Nodo
{
    int carnet;
    string nombre;
    struct Nodo *siguiente;
};

struct Nodo *lista = NULL;

// Declaración de funciones
void Insertar(int n, string m);
void Imprimir();
bool buscador(int n);
void EliminarInicio();
void EliminarFinal();
void principal();
void Eliminar();

int main()
{
    principal();
    return 0;
}

void principal()
{
    bool encontrado;
    do
    {
        system("cls");
        menu = 0;
        cout << "Menu: \n\n1.Ingrese el nuevo estudiante \n2.Ver lista \n3.Eliminar alumno\n4.Salir\n\n";
        cin >> menu;

        switch (menu)
        {
        case 1:
            system("cls");
            encontrado = true;
            cout << "Ingresar el carnet de estudiante:\n";
            cin >> valor;
            encontrado = buscador(valor);
            // cout << encontrado ;
            if (!encontrado)
            {
                cout << "Ingresa el nombre del estudiante:\n";
                //cin >> nombre;
                cin.ignore();
                getline(cin,nombre);
               // 
                Insertar(valor, nombre);
            }
            else
            {
                cout << "!! El carnet que ingreso ya esta registrado !!\n";
            }
            getch();
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

bool buscador(int n)
{
    struct Nodo *temporal = lista;
    bool found;
    while (temporal != NULL)
    {
        if (temporal->carnet == n)
        {
            found = true;
        }
        temporal = temporal->siguiente;
        return found;
    }
}

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

// Insertar nodos a la lista
void Insertar(int n, string m)
{
    system("cls");
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    inserMen = 0;

    cout << "\nCarnet a Ingresar: " << n << "\tNombre: " << m << "\n\n1. Ingresar valor al inicio\n2. Ingresar valor al final\n";
    cin >> inserMen;

    switch (inserMen)
    {
    case 1:

        if (nuevoNodo != NULL)
        {
            nuevoNodo->carnet = n;
            nuevoNodo->nombre = m;
            nuevoNodo->siguiente = NULL;

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
            }
        }
        else
        {
            cout << "Error. no se pueden agregar mas nodos";
        }
        break;
    case 2:

        if (nuevoNodo != NULL)
        {
            nuevoNodo->carnet = n;
            nuevoNodo->nombre = m;
            nuevoNodo->siguiente = NULL;
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
        return Insertar(n, m);
    }
}
void EliminarInicio()
{
    struct Nodo *temporal = lista;
    // Si en la lista se encuentran elementos
    if (lista != NULL)
    {
        // Borra el elemento
        lista = lista->siguiente;
        // Libera la memoria
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
        // Si el nodo no es el ultimo
        if (temporal->siguiente != NULL)
        {
            // Se realiza la iteraciones hasta encontra el ultimo nodo que apunte a NULL
            while (temporal->siguiente != NULL)
            {
                temporal2 = temporal;
                temporal = temporal->siguiente;
            }
            // Almacena el penultimo nodo sera quien apunte NULL
            temporal2->siguiente = NULL;
            // Se libera la memoria del nodo ultimo
            delete temporal;
            temporal = NULL;
        }
        else // Si unicamente se encontraba un nodo en la lista
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
            cout << "Nombre: " << temporal->nombre << "\tCarnet:" << temporal->carnet /*<< " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente */<< endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}