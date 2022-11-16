#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
// Variable global
int menu, contar = 0;
string nombreIN;
string ProductoIN;
float PrecioIN, porcentaje, suma=0,total;

struct Nodo
{

    string nombre = " ", producto = " ";

    float precio;
    struct Nodo *siguiente;
};
struct Nodo *frenteCola = NULL;
struct Nodo *finalCola = NULL;

bool Vacia();
void Insertar(string Nom, string prod, float prec);
int Despachar(string &Nom, string &prod, float &prec);
void Imprimir();
void principal();
void imprimirSUMA();

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
        cout << "Menu: \n\n1. Ingresar orden\n2. Ver pedidos\n3. Total de pedidos(Suma)\n4. Despacho valor\n5. Salir\n\n";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Ingresar su nombre: ";
            cin >> nombreIN;
            /*getline(cin, nombreIN);
            cin.ignore();*/
            cout << "Ingresa el producto: ";
            cin >> ProductoIN;
            /*getline(cin, ProductoIN);
            cin.ignore();*/
            cout << "Ingrese el precio del producto: ";
            cin >> PrecioIN;
            Insertar(nombreIN, ProductoIN, PrecioIN);
            break;
        case 2:
            system("cls");
            Imprimir();

            cout << "\nOprima una tecla para continuar\n";
            getch();
            break;
        case 3:

            imprimirSUMA();

            getch();
            break;

        case 4:
            system("cls");
            Despachar(nombreIN, ProductoIN, PrecioIN);
            cout << "\nOprima una tecla para continuar\n";
            getch();
            break;
        case 5:
            exit(1);
        default:
            cout << "\nIngrese un valor valido...";
            getch();
        }

    } while (menu != 5);
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
void Insertar(string Nom, string prod, float prec)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Asignacion del valor que ingresa el usuario
    nuevoNodo->nombre = Nom;
    nuevoNodo->producto = prod;
    nuevoNodo->precio = prec;
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
int Despachar(string &Nom, string &prod, float &prec)
{
    if (!Vacia())
    {
        Nom = frenteCola->nombre;
        prod = frenteCola->producto;
        prec = frenteCola->precio;
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
        porcentaje = prec * 0.10;
        total=porcentaje+prec;
        cout << "Se ha despachado: " << Nom << "   " << prod << "   " << prec << endl
             << "Costo por envio (10%): $" << porcentaje<<"\nEl total es: $"<<total;


        delete temporal;
        return Nom, prod, prec;
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
        cout << contar << ". Elementos de la cola: " << temporal->nombre << "  " << temporal->producto << "  $" << temporal->precio << endl;
        temporal = temporal->siguiente;
    }

}
void imprimirSUMA()
{
    contar = 0;
    suma=0;
    struct Nodo *temporal = frenteCola;
    while (temporal != NULL)
    {
        contar++;
        cout << contar << ". Elementos de la cola: " << temporal->nombre << "  " << temporal->producto << "  $" << temporal->precio << endl;
        suma = suma+(temporal->precio);
        temporal = temporal->siguiente;
        
    }

    
    cout << "\n\nSuma total de pedidos: $" << suma << endl;
}