#include <iostream>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "datos_12.csv"
using namespace std;



struct Nodo
{
    string datos,descrip,ant;
    struct Nodo *siguiente;
};

struct Nodo *lista = NULL;
void Insertar(string n,string m,string x);
void Imprimir();

int main()
{
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string pal, ant1,descrip;
        // Extraer todos los valores de esa fila
        getline(stream, pal, delimitador);
        getline(stream, ant1, delimitador);
        getline(stream, descrip, delimitador);
        Insertar(pal, ant1, descrip);

    }

    archivo.close();
    Imprimir();
}
void Insertar(string n,string m,string x)
{

    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    if (nuevoNodo != NULL)
    {
        nuevoNodo->datos = n;
        nuevoNodo->ant = m;
        nuevoNodo->descrip = x;
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
            cout << "Lista " << temporal->datos <<" tipo de dato: "<< temporal->ant<<" significado:" << temporal->descrip << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}