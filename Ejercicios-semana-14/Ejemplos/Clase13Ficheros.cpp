#include <iostream>
#include <fstream>

using namespace std;

void Agregar(ofstream &ficheroEscritura);
bool Comprobar(string _placa);
void Imprimir(ifstream &ficheroLectura);
void Modificar(ifstream &ficheroLectura);
void Eliminar(ifstream &ficheroLectura);

int main()
{
    ofstream ficheroEscritura;
    ifstream ficheroLectura;
    Agregar(ficheroEscritura);
    Imprimir(ficheroLectura);
    Modificar(ficheroLectura);
    Eliminar(ficheroLectura);
    Imprimir(ficheroLectura);

    return 0;
}

bool Comprobar(string _placa)
{
    ifstream FicheroLectura("Informacion.txt", ios::in);
    string placa;
    string marca;
    FicheroLectura >> placa;
    // Leer hasta llegar al final
    while (!FicheroLectura.eof())
    {
        FicheroLectura >> marca;
        if (placa == _placa)
        {
            cout << "✋ Placa ya existe";
            FicheroLectura.close();
            return false;
        }
        FicheroLectura >> placa;
    }
    FicheroLectura.close();
    // Permite escribir en el archivo
    return true;
}

void Agregar(ofstream &ficheroEscritura)
{
    string placa;
    string marca;
    ficheroEscritura.open("Informacion.txt", ios::out | ios::app);
    cout << "Ingresa el número de placa " << endl;
    cin >> placa;
    cout << "Ingresa la marca " << endl;
    cin >> marca;
    if (Comprobar(placa))
    {
        ficheroEscritura << placa << " " << marca << " "
                         << "\n";
    }
    ficheroEscritura.close();
}

void Modificar(ifstream &ficheroLectura)
{
    string placa;
    string marca;
    string temp_p;
    string temp_m;

    ficheroLectura.open("Informacion.txt", ios::in);
    ofstream temp("tmp.txt", ios::out);

    if (ficheroLectura.is_open())
    {
        cout << "Ingrese el numero de placa";
        cin >> temp_p;
        ficheroLectura >> placa;
        while (!ficheroLectura.eof())
        {
            ficheroLectura >> marca;
            if (placa == temp_p)
            {
                cout << "Ingrese la marca";
                cin >> temp_m;
                cout << "Registro actualizado" << endl;
                temp << temp_p << " " << temp_m << " "
                     << "\n";
            }
            else
            {
                temp << placa << " " << marca << " "
                     << "\n";
            }
            ficheroLectura >> placa;
        }
        ficheroLectura.close();
        temp.close();
    }
    else
    {
        cout << "Error al abrir el archivo";
    }

    remove("Informacion.txt");
    rename("tmp.txt", "Informacion.txt");
}

void Eliminar(ifstream &ficheroLectura)
{
    string placa;
    string marca;
    string temp_p;

    ficheroLectura.open("Informacion.txt", ios::in);
    ofstream temp("tmp.txt", ios::out);

    if (ficheroLectura.is_open())
    {
        cout << "Ingrese el numero de placa";
        cin >> temp_p;
        ficheroLectura >> placa;
        while (!ficheroLectura.eof())
        {
            ficheroLectura >> marca;
            if (placa == temp_p)
            {
                cout << "Registro eliminado";
            }
            else
            {
                temp << placa << " " << marca << " "
                     << "\n";
            }
            ficheroLectura >> placa;
        }
        ficheroLectura.close();
        temp.close();
    }
    else
    {
        cout << "Error al abrir el archivo";
    }
    remove("Informacion.txt");
    rename("tmp.txt", "Informacion.txt");
}

void Imprimir(ifstream &ficheroLectura)
{
    string placa;
    string marca;
    ficheroLectura.open("Informacion.txt", ios::in);
    if (ficheroLectura.is_open())
    {
        ficheroLectura >> placa;
        while (!ficheroLectura.eof())
        {
            ficheroLectura >> marca;
            cout << "Placa : " << placa << endl;
            cout << "Marca : " << marca << endl;
            cout << "*********************" << endl;
            ficheroLectura >> placa;
        }

        ficheroLectura.close();
    }
    else
    {
        cout << "Error al abrir el archivo" << endl;
    }
}
