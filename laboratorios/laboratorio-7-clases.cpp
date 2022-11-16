#include <iostream>
#include <string.h>
#include "juegos.h"

using namespace std;


string titulo, plataforma;
int anio, horas, contar = 0;

void Menu();

int main()
{
    bool salir = true;
    int p, c, d;
    Juego game1("papas", "psp", 22, 0);
    Juego game2("casa", "pc", 19, 0);
    Juego game3("god", "psp y xbox", 20, 0);
    do
    {
        system("cls");
        cout << "-------Juego 1------\n";
        game1.mostrar();
        cout << "-------Juego 2------\n";
        game2.mostrar();
        cout << "-------Juego 3------\n";
        game3.mostrar();
        int inicio;
        cout << "\ndesea agregar horas a los juegos? 1.si o 2.no\n";
        cin >> d;
        if (d == 1)
        {
            cout << "Ingrese el juego que quiere agregar horas de los tres juegos\n";
            cin >> p;
            if (p == 1)
            {
                system("cls");
                cout << "Ingrese la cantidad de horas\n";
                cin >> c;
                game1.addhoras(c);
            }
            else if (p == 2)
            {
                cout << "Ingrese la cantidad de horas\n";
                cin >> c;
                game2.addhoras(c);
            }
            else if (p == 3)
            {
                cout << "Ingrese la cantidad de horas\n";
                cin >> c;
                game3.addhoras(c);
            }
            else if (p != 3)
            {
                cout << "Ingrese correctamente el dato!!\n";
                system("pause");
                
            }
        }
        if ((d > 2) || (d < 1))
        {
            cout << "Error!!, ingrese los datos correctamente\n";
            system("pause");
        }
        system("cls");
        cout << "-----Juego 1------\n";
        game1.mostrar();
        cout << "-----Juego 2------\n";
        game2.mostrar();
        cout << "-----Juego 3------\n";
        game3.mostrar();
        int gam;
        cout << "\nDesea editar mas horas? 1.si 2.no(salir)\n";
        cin >> gam;
        if (gam == 1)
        {
            salir = 1;
        }
        else if (gam == 2)
        {
            return 0;
        }
        else if (gam != 2)
        {
            cout << "Error, ingrese correctamente el dato!!\n";
            system("pause");
        }
    } while (salir != 2);
    cout << "Fin del Sistema" << endl;
    return 0;
}

void Menu()
{
    /*int opcion;
    bool continueAction = true;
    // return opcion;
    do
    {
        system("cls");
        cout << "Bienvenidos" << endl;
        cout << "1. Agregar Juego" << endl;
        cout << "2. Mostrar Juegos" << endl;
        cout << "3. Agregar horas de juego" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "Ingrese datos del juego: \n"
                 << "Ingrese el nombre: " << endl;
            cin >> titulo;
            cout << "Ingrese la plataforma: " << endl;
            cin >> plataforma;
            cout << "Ingrese el año: " << endl;
            cin >> anio;
            if (contar == 0)
            {
                Juego game1(titulo, plataforma, anio, 0);
                contar++;
                game1.inserDatos(titulo, plataforma, anio);
            }
            else if (contar == 1)
            {
                Juego game2(titulo, plataforma, anio, 0);
                contar++;
                game2.inserDatos(titulo, plataforma, anio);
            }
            else if (contar == 2)
            {
                Juego game3(titulo, plataforma, anio, 0);
                contar++;
                game3.inserDatos(titulo, plataforma, anio);
            }
            else if (contar > 3)
            {
                cout << "Limite de 3 juegos, y este ya esta alcanzado\n";
                system("pause");
                return Menu();
            }
            cout << "Juego agregado" << endl;
            break;
        case 2:
            system("cls");
            if (contar == 1)
            {
                cout << "Juego 1\n";
                game1.mostrar();
                system("pause");
            }
            else if (contar == 2)
            {
                cout << "Juego 1\n";
                game1.mostrar();
                cout << "Juego 2\n";
                game2.mostrar();
                system("pause");
            }
            else if (contar == 3)
            {
                cout << "Juego 1\n";
                game1.mostrar();
                cout << "Juego 2\n";
                game2.mostrar();
                cout << "Juego 3\n";
                game3.mostrar();
                system("pause");
            }
            else if (contar == 0)
            {
                cout << "Ingrese primero un dato!!\n";
                system("pause");
                return Menu();
            }
            break;
        case 3:
            system("cls");
            int p, c;
            cout << "Ingrese el juego que quiere agregar horas de los tres juegos\n";
            cin >> p;
            if (p == 1)
            {
                cout << "Ingrese la cantidad de horas\n";
                cin >> c;
                game1.addhoras(c);
            }
            else if (p == 2)
            {
                cout << "Ingrese la cantidad de horas\n";
                cin >> c;
                game2.addhoras(c);
            }
            else if (p == 3)
            {
                cout << "Ingrese la cantidad de horas\n";
                cin >> c;
                game3.addhoras(c);
            }
            else
            {
                cout << "Ingrese correctamente el dato!!\n";
                system("pause");
            }
            break;
        case 4:
            continueAction = false;
            break;
        }
    } while (continueAction);*/
}