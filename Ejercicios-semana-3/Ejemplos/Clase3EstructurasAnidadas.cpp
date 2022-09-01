#include <iostream>

using namespace std;

/*ACTIVIDAD NO EVALUADA
Crear la función para la captura de datos
*/

// variable global
int numRegistro;

// Declarar la función
void imprimirDatos();

// Declaración de una estructura
struct Direccion
{
    string municipio;
    string departamento;
    int numCasa;
    int numPasaje;
};
struct Alumno
{
    // Declarar los miembros o campos
    int codigo;
    string nombre;
    int anioNac;
    int edad;
    // Declarar una variable tipo estruct
    struct Direccion dir;
} alumno[100]; // Declaracion de un arreglo

int main()
{
    string aux;
    // Declaracion de variables segunda forma
    struct Alumno alumno4;
    Alumno alumno5;

    // Asignar a un miembro de la estructura
    // alumno[1].codigo = 7892;
    // cout << alumno[1].codigo;
    // Asignar valores a todos los miembros de la estructura
    /*    alumno1 =  {
           4568,
           "Marlen",
           40
       }; */

    // Tamaño de un arreglo
    int lista[5] = {1, 5, 5, 3, 8};
    cout << sizeof(lista) / sizeof(int) << endl;

    // Tamaño en bytes una estructura
    cout << "Tamaño en bytes de la estructura " << sizeof(Alumno) << endl;
    cout << "Numero de elementos de una estructura de arreglo" << sizeof(alumno) / sizeof(alumno[0]) << endl;

    // Accediendo a un miembro de una estructura anidada
    alumno[1].dir.municipio = "Antiguo Cuscatlan";
    // cout<<alumno[1].dir.municipio<<endl;

    cout << "Ingresa el numero de registros";
    cin >> numRegistro;

    // Solicitar datos
    for (int i = 0; i < numRegistro; i++)
    {
        cout << "Ingresa el código ";
        cin >> alumno[i].codigo;
        // Limpiar el bufer del teclado
        getline(cin, aux);
        cout << "Ingresa el  nombre ";
        // cin >> alumno[i].nombre;
        getline(cin, alumno[i].nombre);
        cout << "Ingresa el municipio donde reside ";
        getline(cin, alumno[i].dir.municipio);
        cout << "Ingresa el año de nacimiento ";
        cin >> alumno[i].anioNac;
        alumno[i].edad = 2022 - alumno[i].anioNac;
    }

    // Invocar a la función
    imprimirDatos();

    return 0;
}

// Definir la función para la captura de datos


// Definir la función
void imprimirDatos()
{
    // Imprimir los datos
    for (int i = 0; i < numRegistro; i++)
    {
        cout << alumno[i].codigo << endl;
        cout << alumno[i].nombre << endl;
        cout << alumno[i].dir.municipio << endl;
        cout << alumno[i].anioNac << endl;
        cout << alumno[i].edad << endl;
    }
}