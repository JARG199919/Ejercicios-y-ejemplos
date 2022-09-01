#include <iostream>

/*ACTIVIDAD NO EVALUADA
Hacer funcional el codigo  haciendo uso da la función imprimirDatos
Opcional crear un función para la captura de Datos 
*/

using namespace std;

// Variable global
int numRegistro = 0;

// Declaración de la función



// Declaración de estructura
struct Direccion
{
    // char municipio[50];
    string municipio;
};

struct Alumno
{
    string nombre;
    string codigo;
    int anioNac;
    int edad;
    struct Direccion dir;

} alumno[10]; // Arreglo TIPO STRUCT

int main()
{

    // Crear un variable auxiliar
    string aux;
    // otra forma de declarar variables tipo struct
    /*  struct Alumno alumno3;
     Alumno alumno4;
     //Otra forma de declaración de un arreglo tipo struct
     Alumno alumnos[5]; */

    // Declaracion e inicializacion del arreglo
    int lista[] = {1, 2, 3, 4, 5};

    // Tamaño del arreglo
    int tamanoArreglo = sizeof(lista) / sizeof(int);
    cout << "Tamaño del arreglo lista: " << tamanoArreglo;

    // Tamaño en bytes
    cout << "Tamaño en bytes " << sizeof(Alumno);
    cout << "Numero de elemento del arreglo tipo struct " << sizeof(alumno) / sizeof(alumno[0]);

    // Acceder un miembro de la estructura
    alumno[1].codigo = "UCA4578";

    // Imprimiendo informacion del miembro
    // cout<<alumno[1].codigo<<endl;

    // Acceder a un miembro de una estructura anidada
    alumno[1].dir.municipio = "Antiguo Cuscatlan";
    cout << alumno[1].dir.municipio << endl;

    // Acceder a todos los miembros y asignarles el valor
    // alumno[5] = {{"Marlen", "92828", 1997},{},{},{},{}}

    cout << "Ingrese el numero de alumnos a registrar ";
    cin >> numRegistro;
    // Limpiando el bufer del teclado
    getline(cin, aux);
    // SOLICITAR LA INFORMACION
    for (int i = 0; i < numRegistro; i++)
    {
        cout << "Ingresa tu nombre ";
        // cin>>alumno1[i].nombre;
        getline(cin, alumno[i].nombre);
        cout << "Ingresa tu codigo ";
        // cin >> alumno[i].codigo;
        getline(cin, alumno[i].codigo);
        cout << "Ingresa tu año de nacimiento ";
        cin >> alumno[i].anioNac;
        alumno[i].edad = 2022 - alumno[i].anioNac;
        // Limpiando el bufer del teclado
        getline(cin, aux);
        cout << "Ingrese el nombre del municipio donde reside ";
        getline(cin, alumno[i].dir.municipio);
    }

        // IMPRIMIR LA INFORMACION
    cout << "Información ingresada" << endl;

    for (int i = 0; i < numRegistro; i++)
    {
        cout << alumno[i].nombre << endl;
        cout << alumno[i].codigo << endl;
        cout << alumno[i].anioNac << endl;
        cout << alumno[i].edad << endl;
        cout << alumno[i].dir.municipio << endl
             << endl;
    }

    // Llamando a la función
    

    return 0;
}

// Definir función sin parámetros
void imprimirDatos()
{

}