#include <iostream>
#include <conio.h>

using namespace std;

string nombre1;
double precio1;

struct pila
{

    string nombre;
    double precio;
    pila *siguiente;
} * rese, *aux;

void ingreso();
void actualizar_pila();
void push(double, string);
void pop(double &, string &);

int main()
{

    pila *siguiente3 = NULL;

    int y, opc;
    for (;;)
    {
        system("cls");
        cout << "\n1. Ingresar juegos"
             << "\n2. Sacar elemento"
             << "\n0. Terminar"
             << "\n\nIngrese opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            ingreso();
            push(precio1, nombre1);
            break;
        case 2:
            system("cls");
            pop(precio1, nombre1);
            break;
        case 0:
            exit(1);
        default:
            cout << "\nOpcion no valida!!\n";
            break;
        }
        actualizar_pila();

        cout << "\nOprima una tecla para continuar\n";
        getch();
    }

    return 0;
}
void ingreso()
{

    cout << "Ingrese un juego " << endl;
    cin.ignore();
    getline(cin, nombre1);
    cout << "Ingrese su precio: " << endl;
    cin >> precio1;
}
void push(double c, string n)
{

    aux = new (pila);
    aux->nombre = n;
    aux->precio = c;
    aux->siguiente = rese;
    rese = aux;
}
void pop(double &c, string &n)
{
    if (!rese)
    {
        cout << "\n\nNo hay elementos!!";
        return;
    }
    aux = new (pila);
    aux = rese;
    n = aux->nombre;
    c = aux->precio;
    cout << "\n\nElemento eliminado: " << aux->nombre << "\tCon precio: " << aux->precio;
    rese = aux->siguiente;
    delete (aux);
    cout << "\n";
}
void actualizar_pila()
{
    int y = 2, i, ca = 0;
    aux = rese;
    while (aux)
    {
        ca++;
        aux = aux->siguiente;
    }

    for (i = 0; i <= ca; i++)
    {
        cout << " ";
    }

    i = 0;
    aux = rese;

    while (aux)
    {
        cout << "\n";
        cout << ++i << ".Juego: " << aux->nombre << "\nPrecio: " << aux->precio;
        aux = aux->siguiente;
    }
    cout << "\n";
}