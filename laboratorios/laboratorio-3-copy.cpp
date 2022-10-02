#include <iostream>

using namespace std;

string nombre1;
double precio1;
int dato, conta;
char opcion;

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
    pila *rese = NULL;
    ingreso();
    return 0;
}

void ingreso()
{
    cout << "Presione entre....";
    do
    {
        conta++;

        cin.ignore();
        cout << "Ingrese el pedido: \n";
        getline(cin, nombre1);

        cout << "Ingrese su precio: \n";
        cin >> precio1;
        push(precio1, nombre1);
        cout << "Desea ingresar mas pedios?(s/n): \n";
        cin >> opcion;
        actualizar_pila();
    } while ((opcion == 's') || (opcion == 'S'));

    cout << "\n";
    for (int i = 0; i < conta; i++)
    {
        pop(precio1, nombre1);
    }
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
    cout << "\nElemento eliminado: " << aux->nombre << "\tCon precio: " << aux->precio;
    rese = aux->siguiente;
    delete (aux);
    // cout << "\n";
}
void actualizar_pila()
{
    int i, ca = 0;
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
        cout << ++i << ".Pedido: " << aux->nombre << "\nPrecio: " << aux->precio;
        aux = aux->siguiente;
    }
    cout << "\n\n";
}