#include <iostream>

using namespace std;

// Constante
#define tamano 5

struct Nodo
{
    int frenteCola;
    int finalCola;
    int elemento[tamano];
} nodo;

// Declaracion de funciones / creacion de prototipo
void Crear(struct Nodo *);
bool Vacia(struct Nodo *);
int Llena(Nodo *);
void Insertar(struct Nodo *, int);
void Mover(struct Nodo *);
void Eliminar(struct Nodo *);

int main()
{
    Crear(&nodo);
    Insertar(&nodo, 45);
    Insertar(&nodo, 55);
    Insertar(&nodo, 5);
    Insertar(&nodo, 8);
    cout<<"Posicion "<<nodo.frenteCola<<" Elemento "<<nodo.elemento[nodo.frenteCola]<<endl;
    cout<<"Posicion "<<nodo.finalCola<<" Elemento "<<nodo.elemento[nodo.finalCola]<<endl;
    Eliminar(&nodo);
    cout<<"Posicion "<<nodo.frenteCola<<" Elemento "<<nodo.elemento[nodo.frenteCola]<<endl;
    cout<<"Posicion "<<nodo.finalCola<<" Elemento "<<nodo.elemento[nodo.finalCola]<<endl;
    return 0;
}

// Crear Cola vacía
void Crear(Nodo *p)
{
    p->frenteCola = -1;
    p->finalCola = -1;
}

// Vacia
bool Vacia(Nodo *p)
{
    if (p->finalCola == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Llena
int Llena(Nodo *p)
{
    if (p->finalCola == tamano - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Encolar -- final de la lista
void Insertar(Nodo *p, int n)
{
    if (!Llena(p))
    {
        // Si la cola esta vacia
        if (Vacia(p))
        {
            p->frenteCola = 0;
        }
        p->finalCola++;
        p->elemento[p->finalCola] = n;
    }
    else
    {
        cout << "Cola esta llena";
    }
}

// Correr elementos
void Mover(Nodo *p)
{
    for (int i = 1; i <= p->finalCola; i++)
    {
        p->elemento[i - 1] = p->elemento[i];
    }
    p->finalCola--;
}

// Desencolar -- inicio de la lista
void Eliminar(Nodo *p){
    if (!Vacia(p))
    {
        if (p->finalCola==0)
        {
            p->frenteCola = -1;
            p->finalCola = -1;
        }else{
            Mover(p);
        }
            
    }else{
        cout<<"Cola esta vacia";
    }
    
}

