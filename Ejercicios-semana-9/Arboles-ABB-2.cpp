#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo
{
	int dato;
	Nodo *izq;
	Nodo *der;
	Nodo *padre;
};

int numeros[] = {
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
void buscarParaEliminar(Nodo *&arbol, int numeroEliminar);
void eliminarNodo(Nodo *&arbol);
Nodo *minimoNodo(Nodo *&arbol);
void remplazarNodo(Nodo *arbol, Nodo *nuevo);
void destruirNodo(Nodo *nodoDestruir);
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
		 << "4.- Mostrar arbol en preorden\n"
		 << "5.- Mostrar arbol en inorden\n"
		 << "6.- Mostrar arbol en postorden\n"
		 << "7.- Ingresar datos de ejemplo(Preestablecidos)\n"
		 << "8.- Eliminar nodo\n"
		 << "9.- Salir\n"
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
		cout << "\t ARBOL EN PREORDEN\n";
		preorden(arbol);
		cout << "\n";
		system("pause");
		goto regresaMenu;
		break;
	case 5:
		system("cls");
		cout << "\t ARBOL EN INORDEN\n";
		inorden(arbol);
		cout << "\n";
		system("pause");
		goto regresaMenu;
		break;
	case 6:
		system("cls");
		cout << "\t ARBOL EN POSTORDEN\n";
		postorden(arbol);
		cout << "\n";
		system("pause");
		goto regresaMenu;
		break;
	case 7:
		system("cls");
		cout << "Se ingreso los datos: \n";

		for (int i = 0; i < sizeArray; i++)
		{
			insertarNodo(arbol, numeros[i], NULL);
			cout << numeros[i] << ", ";
		}
		cout << "\n";
		/*insertarNodo(arbol, 10, NULL);
		insertarNodo(arbol, 5, NULL);
		insertarNodo(arbol, 3, NULL);
		insertarNodo(arbol, 8, NULL);
		insertarNodo(arbol, 6, NULL);
		insertarNodo(arbol, 9, NULL);
		insertarNodo(arbol, 7, NULL);
		insertarNodo(arbol, 15, NULL);
		insertarNodo(arbol, 12, NULL);
		insertarNodo(arbol, 20, NULL);
		insertarNodo(arbol, 30, NULL);*/
		system("pause");
		goto regresaMenu;
		break;
	case 8:
		system("cls");
		cout << "\t ARBOL EN PREORDEN\n";
		preorden(arbol);
		cout << "\n";
		cout << "ingresa el nodo a eliminar:";
		cin >> dato;
		buscarParaEliminar(arbol, dato);
		system("pause");
		goto regresaMenu;
		break;
	default:
		return;
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
void buscarParaEliminar(Nodo *&arbol, int numeroEliminar)
{
	if (arbol == NULL)
	{
		return;
	}
	else if (numeroEliminar < arbol->dato)
	{
		buscarParaEliminar(arbol->izq, numeroEliminar);
	}
	else if (numeroEliminar > arbol->dato)
	{
		buscarParaEliminar(arbol->der, numeroEliminar);
	}
	else
	{
		eliminarNodo(arbol);
	}
}
void eliminarNodo(Nodo *&arbol)
{
	if (arbol->izq && arbol->der)
	{ // Si hay sub nodo izq y der
		Nodo *minimo = minimoNodo(arbol->der);
		arbol->dato = minimo->dato;
		eliminarNodo(minimo);
	}
	else if (arbol->izq)
	{ // Si hay sub nodo izq
		remplazarNodo(arbol, arbol->izq);
	}
	else if (arbol->der)
	{ // Si hay sub nodo der
		remplazarNodo(arbol, arbol->der);
	}
	else
	{ // Si no hay sub nodo
		remplazarNodo(arbol, NULL);
	}
}
void remplazarNodo(Nodo *arbol, Nodo *nuevo)
{
	if (arbol->padre)
	{
		if (arbol->padre->izq != NULL)
		{
			if (arbol->dato == arbol->padre->izq->dato)
			{
				arbol->padre->izq = nuevo;
			}
		}
		if (arbol->padre->der != NULL)
		{
			if (arbol->dato == arbol->padre->der->dato)
			{
				arbol->padre->der = nuevo;
			}
		}
	}
	if (nuevo)
	{
		nuevo->padre = arbol->padre;
	}
	destruirNodo(arbol);
}
void destruirNodo(Nodo *nodoDestruir)
{
	nodoDestruir->izq = NULL;
	nodoDestruir->der = NULL;
	nodoDestruir->padre = NULL;
	delete nodoDestruir;
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