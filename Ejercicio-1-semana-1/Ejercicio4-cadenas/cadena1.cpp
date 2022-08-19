#include <iostream>
#include <string.h>

using namespace std;
using std::string;

int main()
{
    string nombre, apellido, nombreCompleto;
    cout<<"Ingrese su nombre:\n";
    cin >> nombre;
    cout<<"Ingrese su apellido\n";
    cin >> apellido;
    nombreCompleto = nombre +" "+ apellido;
    cout << "\n" + nombreCompleto;
    for (int i = 0; i < nombre.length(); i++){
        nombre[i] = toupper(nombre[i]);
    }
    cout << "\n" + nombre;
}