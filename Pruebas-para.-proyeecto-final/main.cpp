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

int gotoxy(USHORT x, USHORT y);
int menu(const char titulo[], const char *opciones[], int n);
void menu_principal();
void menu_suma();
void menu_resta();
void menu_producto();
void menu_division();

int main()
{
    menu_principal();

    return 0;
}

void menu_principal()
{
    bool repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char *titulo = "MENU DE OPCIONES";
    const char *opciones[] = {"Ingresar palabras", "Ver Biblioteca", "Editar", "Eliminar", "Salir"};
    int n = 5; // Numero de opciones

    do
    {
        opcion = menu(titulo, opciones, n);

        switch (opcion)
        {
        case 1:
            menu_suma();
            break;

        case 2:
            menu_resta();
            break;

        case 3:
            menu_producto();
            break;

        case 4:
            menu_division();
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

int gotoxy(USHORT x, USHORT y)
{
    COORD cp = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
void menu_suma()
{
    bool repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char *titulo = "MENU PARA SUMAR";
    const char *opciones[] = {"Sumar enteros", "Sumar flotantes", "Regresar"};

    int n = 3; // Numero de opciones
    int a, b;
    float c, d;
    do
    {
        opcion = menu(titulo, opciones, n);
        system("cls");
        switch (opcion)
        {
        case 1:
            cout << "numero1 = ";
            cin >> a;

            cout << "numero2 = ";
            cin >> b;

            cout << a << " + " << b << " = " << a + b << endl;
            system("pause>nul");
            break;
        case 2:
            cout << "numero1 = ";
            cin >> c;

            cout << "numero2 = ";
            cin >> d;

            cout << c << " + " << d << " = " << c + d << endl;
            system("pause>nul");
            break;
        case 3:
            repite = false;
            break;
        }

    } while (repite);
}

void menu_resta()
{
    bool repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char *titulo = "MENU PARA RESTAR";
    const char *opciones[] = {"Restar enteros", "Restar flotantes", "Regresar"};
    int n = 3; // Numero de opciones
    int a, b;
    float c, d;

    do
    {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion)
        {
        case 1:
            cout << "numero1 = ";
            cin >> a;

            cout << "numero2 = ";
            cin >> b;

            cout << a << " - " << b << " = " << a - b << endl;
            system("pause>nul");
            break;
        case 2:
            cout << "numero1 = ";
            cin >> c;

            cout << "numero2 = ";
            cin >> d;

            cout << c << " - " << d << " = " << c - d << endl;
            system("pause>nul");
            break;
        case 3:
            repite = false;
            break;
        }
    } while (repite);
}

void menu_producto()
{
    bool repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char *titulo = "MENU PARA MULTIPLICAR";
    const char *opciones[] = {"Multiplicar enteros", "Multiplicar flotantes", "Regresar"};
    int n = 3; // Numero de opciones
    int a, b;
    float c, d;
    do
    {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion)
        {
        case 1:
            cout << "numero1 = ";
            cin >> a;

            cout << "numero2 = ";
            cin >> b;

            cout << a << " x " << b << " = " << a * b << endl;
            system("pause>nul");
            break;

        case 2:
            cout << "numero1 = ";
            cin >> c;

            cout << "numero2 = ";
            cin >> d;

            cout << c << " x " << d << " = " << c * d << endl;
            system("pause>nul");
            break;

        case 3:
            repite = false;
            break;
        }

    } while (repite);
}

void menu_division()
{
    bool repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char *titulo = "MENU PARA DIVIDIR";
    const char *opciones[] = {"Dividir enteros", "Dividir flotantes", "Regresar"};
    int n = 3; // Numero de opciones

    int a, b;
    float c, d;

    do
    {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion)
        {
        case 1:
            cout << "numero1 = ";
            cin >> a;

            cout << "numero2 = ";
            cin >> b;

            if (b == 0)
                cout << "No se puede dividir por cero" << endl;
            else
                cout << a << " div " << b << " = " << a / b << endl;

            system("pause>nul");
            break;

        case 2:
            cout << "numero1 = ";
            cin >> c;

            cout << "numero2 = ";
            cin >> d;

            if (d == 0)
                cout << "No se puede dividir por cero" << endl;
            else
                cout << c << " / " << d << " = " << c / d << endl;

            system("pause>nul");
            break;

        case 3:
            repite = false;
            break;
        }

    } while (repite);
}

int menu(const char titulo[], const char *opciones[], int n)
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


    //Imprime un cuadro
        int i
        ,x1=2
        ,y1=1
        ,x2=80
        ,y2=28;
        char m=205,mn=186,xm=201,rm=200,xas=188,dsa=187;

    for (i=x1;i<x2;i++){
		gotoxy(i,y1); printf("%c",m); //linea horizontal superior
		gotoxy(i,y2); printf("%c",m); //linea horizontal inferior
    }
    for (i=y1;i<y2;i++){
		gotoxy(x1,i); printf("%c",mn); //linea vertical izquierda
		gotoxy(x2,i); printf("%c",mn); //linea vertical derecha
	}
    gotoxy(x1,y1); printf("%c",xm);
    gotoxy(x1,y2); printf("%c",rm);
    gotoxy(x2,y1); printf("%c",dsa);
    gotoxy(x2,y2); printf("%c",xas);



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