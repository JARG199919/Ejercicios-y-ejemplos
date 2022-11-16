#include <iostream>

#include <stdlib.h>
#include <stdio.h>


using namespace std;

struct Nodo
{

	int dato;
	Nodo *izq;
	Nodo *der;
	Nodo *padre;
};

int numeros[] = { // Datos preestablecidos
	10,
	5,
	3,
	8,
	6,
	9,
	7,
	15,
	12,
	20,
	30};

int sizeArray = (sizeof(numeros) / sizeof(*numeros));

Nodo *arbol = NULL;
Nodo *crearNodo(int dato, Nodo *padre);
void insertarNodo(Nodo *&arbol, int dato, Nodo *padre);
void mostrarArbol(Nodo *&arbol, int cont);
bool buscarNodoArbol(Nodo *&arbol, int numBuscar);
void preorden(Nodo *&arbol);
void inorden(Nodo *&arbol);
void postorden(Nodo *&arbol);
int BuscarMaximo(Nodo *arbol);
int BuscarMinimo(Nodo *arbol);

void menu();
int main()
{
	menu();
	system("pause");
	return 0;
}
void menu()
{
	int opcion, dato;
regresaMenu:
	system("cls");
	cout << "\tMENU\n";
	cout << "1.- Insertar un nodo\n"
		 << "2.- Mostrar arbol\n"
		 << "3.- Buscar un nodo en el arbol\n"
		 << "4.- Mostrar arbol en orden\n"
		 << "5.- Ingresar datos de ejemplo(Preestablecidos)\n"
		 << "6.- Mostrar el menor y mayor \n"
		 << "7.- Salir\n"
		 << "ingresa una opcion:\n";
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		system("cls");
		cout << "Ingresa el numero del nodo a insertar:";
		cin >> dato;
		insertarNodo(arbol, dato, NULL);
		system("pause");
		goto regresaMenu;
		break;
	case 2:
		system("cls");
		cout << "\n\tARBOL\n";
		mostrarArbol(arbol, 0);
		cout << "\n";
		system("pause");
		goto regresaMenu;
		break;
	case 3:
		system("cls");
		cout << "Ingrese el numero a buscar en el arbol:";
		cin >> dato;
		if (buscarNodoArbol(arbol, dato) == true)
		{
			cout << "El dato " << dato << " si se encontro en el arbol\n";
		}
		else
		{
			cout << "El dato " << dato << " no se encontro en el arbol\n";
		}
		system("pause");
		goto regresaMenu;
		break;
	case 4:
		system("cls");
		cout << "\n";
		preorden(arbol);
		cout << "\t ARBOL EN PREORDEN\n";
		inorden(arbol);
		cout << "\t ARBOL EN INORDEN\n";
		postorden(arbol);
		cout << "\t ARBOL EN POSTORDEN\n";
		cout << "\n";
		system("pause");
		goto regresaMenu;
		break;
	case 5:
		system("cls");
		cout << "Se ingreso los datos: \n";

		for (int i = 0; i < sizeArray; i++)
		{
			insertarNodo(arbol, numeros[i], NULL);
			cout << numeros[i] << ", ";
		}
		cout << "\n";
		system("pause");
		goto regresaMenu;
		break;
	case 6:
		preorden(arbol);
		cout << "\t ARBOL EN PREORDEN\n";
		cout << "Menor es: " << BuscarMinimo(arbol) << "\n";
		cout << "Menor es: " << BuscarMaximo(arbol) << "\n";
		system("pause");
		goto regresaMenu;
		break;

	case 7:
		system("cls");
		cout << "Usted esta saliendo, !Gracias por utilizar el programa\n\n";
		return;
		break;

	default:
		system("cls");
		cout << "Ingresa correctamente el dato (Solo numeros 1-9)\n";
		system("pause");
		goto regresaMenu;
		break;
	}
}
Nodo *crearNodo(int dato, Nodo *padre)
{
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato = dato;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	nuevoNodo->padre = padre;
}
void insertarNodo(Nodo *&arbol, int dato, Nodo *padre)
{
	if (arbol == NULL)
	{
		Nodo *nuevoNodo = crearNodo(dato, padre);
		arbol = nuevoNodo;
	}
	else
	{
		int valorRaiz = arbol->dato;
		if (dato < valorRaiz)
		{
			insertarNodo(arbol->izq, dato, arbol);
		}
		else
		{
			insertarNodo(arbol->der, dato, arbol);
		}
	}
}
void mostrarArbol(Nodo *&arbol, int cont)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++)
		{
			cout << "       ";
		}
		cout << arbol->dato << "\n";
		mostrarArbol(arbol->izq, cont + 1);
	}
}
bool buscarNodoArbol(Nodo *&arbol, int numBuscar)
{
	if (arbol == NULL)
	{
		return false;
	}
	else if (arbol->dato == numBuscar)
	{
		return true;
	}
	else if (numBuscar < arbol->dato)
	{
		return buscarNodoArbol(arbol->izq, numBuscar);
	}
	else
	{
		return buscarNodoArbol(arbol->der, numBuscar);
	}
}
void preorden(Nodo *&arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		cout << arbol->dato << " - ";
		preorden(arbol->izq);
		preorden(arbol->der);
	}
}
void inorden(Nodo *&arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		inorden(arbol->izq);
		cout << arbol->dato << " - ";
		inorden(arbol->der);
	}
}
void postorden(Nodo *&arbol)
{
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		postorden(arbol->izq);
		postorden(arbol->der);
		cout << arbol->dato << " - ";
	}
}

Nodo *minimoNodo(Nodo *&arbol)
{
	if (arbol == NULL)
	{
		return NULL;
	}
	else if (arbol->izq)
	{
		return minimoNodo(arbol->izq);
	}
	else
	{
		return arbol;
	}
}

int BuscarMinimo(Nodo *arbol)
{
    int minimo;
    while(arbol->izq != NULL)
    {
        arbol = arbol->izq;
        minimo = arbol->dato;
    }
    return minimo;

}

int BuscarMaximo(Nodo *arbol)
{

	int maximo;
	while (arbol->der != NULL)
	{
		arbol = arbol->der;
		maximo = arbol->dato;
	}
	return maximo;
}