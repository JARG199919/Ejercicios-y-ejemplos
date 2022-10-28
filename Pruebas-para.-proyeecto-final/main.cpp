// Se usa la función getch implementada mediante la API de Windows
// Pude encontrar una función getch que sí funciona, ya lo puse :D
// Solo las teclas w s para arriba y abajo

#include <iostream>
#include <windows.h>
#include <conio.h>

/*#define ARRIBA 72
#define ABAJO 80
#define ENTER 13*/

#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13
/*
#define ARRIBA 1
#define ABAJO 0
#define ENTER 13
#define INVALIDO -1
*/
using namespace std;

int inserMen, menu, x1 = 2, y1 = 1, x2 = 80, y2 = 28;
string singnificado,palabra;



struct Nodo
{
    string palabras, signi;
    struct Nodo *siguiente;
};

struct Nodo *lista = NULL;

// Declaración de funciones
void Insertar(string n, string m);
void Imprimir();
bool buscador(string n);
void EliminarInicio();
void EliminarFinal();
void principal();
void Eliminar();
void imprimeCuadro();

int gotoxy(USHORT x, USHORT y);
int menu1(const char titulo[], const char *opciones[], int n);
void menu_principal();

int main()
{
    menu_principal();

    return 0;
}

void menu_principal()
{
    bool encontrado,repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char *titulo = "MENU DE OPCIONES";
    const char *opciones[] = {"Ingresar palabras", "Ver Biblioteca", "Editar", "Eliminar", "Salir"};
    int n = 5; // Numero de opciones

    do
    {   
        
        y2=28;
        opcion = menu1(titulo, opciones, n);
       

        switch (opcion)
        {
        case 1:

            //encontrado = true;
            system("cls");
            imprimeCuadro();
            gotoxy(15, 3);
            cout << "Ingresar la nueva palabra:";
            gotoxy(15, 4);
            cin >> palabra;
            encontrado = buscador(palabra);
            // cout << encontrado ;
            if (!encontrado)
            {   
                gotoxy(15, 5);
                cout << "Ingrese el significado(Obligatorio):";
                // cin >> nombre;
                cin.ignore();
                gotoxy(15, 6);
                getline(cin, singnificado);
                //
                Insertar(palabra, singnificado);
            }
            else
            {   
                cout << "!! La palabra que ingreso ya esta registrada !!\n";
            }
            getch();
            break;

        case 2:
            system("cls");
            cout<<"\n";
            Imprimir();
            cout << "\n\t\t\tOprima una tecla para continuar\n";
            imprimeCuadro();
            getch();
            break;

        case 3:
            break;

        case 4:
            system("cls");
            imprimeCuadro();
            Eliminar();
            cout << "\n\t\t\tOprima una tecla para continuar\n";
            getch();
            break;

        case 5:
            cout << "\n\t\t\tEl programa se cerrara!! ADIOS" << endl;
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
}
char getch2()
{
    char c = 0;
    DWORD modo, contador;
    HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

    // Desactivamos escritura en terminal
    SetConsoleMode(ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
    ReadConsoleA(ih, &c, 1, &contador, NULL);
    if (c == 0)
    {
        ReadConsoleA(ih, &c, 1, &contador, NULL);
    }
    SetConsoleMode(ih, modo); // Devolvemos control normal
    return c;
}
void imprimeCuadro(){
        // Imprime un cuadro
        //int i, x1 = 2, y1 = 1, x2 = 80, y2 = 28;
        int i;
        char m = 205, mn = 186, xm = 201, rm = 200, xas = 188, dsa = 187;

        for (i = x1; i < x2; i++)
        {
            gotoxy(i, y1);
            printf("%c", m); // linea horizontal superior
            gotoxy(i, y2);
            printf("%c", m); // linea horizontal inferior
        }
        for (i = y1; i < y2; i++)
        {
            gotoxy(x1, i);
            printf("%c", mn); // linea vertical izquierda
            gotoxy(x2, i);
            printf("%c", mn); // linea vertical derecha
        }
        gotoxy(x1, y1);
        printf("%c", xm);
        gotoxy(x1, y2);
        printf("%c", rm);
        gotoxy(x2, y1);
        printf("%c", dsa);
        gotoxy(x2, y2);
        printf("%c", xas);

}

int gotoxy(USHORT x, USHORT y)
{
    COORD cp = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

int menu1(const char titulo[], const char *opciones[], int n)
{
    int opcionSeleccionada = 1; // Indica la opcionSeleccionada

    int tecla;

    bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER

    do
    {
        system("cls");
        system("color f0");
        /*
    0 = Negro       8 = Gris
    1 = Azul        9 = Azul claro
    2 = Verde       A = Verde claro
    3 = Aguamarina  B = Aguamarina claro
    4 = Rojo        C = Rojo claro
    5 = Púrpura     D = Púrpura claro
    6 = Amarillo    E = Amarillo claro
    7 = Blanco      F = Blanco brillante */

        imprimeCuadro();

        gotoxy(5, 3 + opcionSeleccionada);
        cout << "==>" << endl;

        // Imprime el título del menú
        gotoxy(15, 2);
        cout << titulo;

        // Imprime las opciones del menú
        for (int i = 0; i < n; ++i)
        {
            gotoxy(10, 4 + i);
            cout << i + 1 << ") " << opciones[i];
        }

        // Solo permite que se ingrese ARRIBA, ABAJO o ENTER

        do
        {
            tecla = getch2();
            // gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

        switch (tecla)
        {

        case ARRIBA: // En caso que se presione ARRIBA

            opcionSeleccionada--;

            if (opcionSeleccionada < 1)
            {
                opcionSeleccionada = n;
            }

            break;

        case ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n)
            {
                opcionSeleccionada = 1;
            }

            break;

        case ENTER:
            repite = false;
            break;
        }

    } while (repite);

    return opcionSeleccionada;
}
bool buscador(string n)
{
    struct Nodo *temporal = lista;
    bool found;
    while (temporal != NULL)
    {
        if (temporal->palabras == n)
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
void Insertar(string n, string m)
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
            nuevoNodo->palabras = n;
            nuevoNodo->signi = m;
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
            nuevoNodo->palabras = n;
            nuevoNodo->signi = m;
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
    int contm=0;
    
    struct Nodo *temporal = lista;
    if (lista != NULL)
    {   
        while (temporal != NULL)
        {   
            contm++;
            cout << "\n\t\t"<<contm << "." << temporal->palabras<<"\n\t\tconcepto: " << temporal->signi << endl;
            temporal = temporal->siguiente;
            

        }
    }
    else
    {  
        cout << "\n\t\t!!!Lista vacia!!!";
    }
    y2=5*contm;
}