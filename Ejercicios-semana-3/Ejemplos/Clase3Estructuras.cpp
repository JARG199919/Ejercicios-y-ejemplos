#include <iostream>

/*ACTIVIDAD NO EVALUADA
Determinar el tamaño de la estructura
Hacer uso del método getline para los valores string o char
*/

using namespace std;

// Variable global
int numRegistro = 0;

// Declaración de estructura
struct Alumno
{
  string nombre;
  string codigo;
  int anioNac;
  int edad;

} alumno[10]; // Arreglo TIPO STRUCT

int main()
{

  // Crear un variable auxiliar
  string aux;

  // otra forma de declarar variables tipo struct
  struct Alumno alumno3;
  Alumno alumno4;
  // Otra forma de declaración de un arreglo tipo struct
  Alumno alumnos[5];

  // Declaracion e inicializacion del arreglo
  int lista[] = {1, 2, 3, 4, 5};

  // Acceder un miembro de la estructura
  alumno[1].codigo = "UCA4578";

  // Imprimiendo informacion del miembro
  // cout<<alumno[1].codigo<<endl;

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
  }

  // IMPRIMIR LA INFORMACION
  cout << "Información ingresada" << endl;

  for (int i = 0; i < numRegistro; i++)
  {
    cout << alumno[i].nombre << endl;
    cout << alumno[i].codigo << endl;
    cout << alumno[i].anioNac << endl;
    cout << alumno[i].edad << endl;
  }

  // Llamar a la función

  return 0;
}

// Definir función sin parámetros
void imprimirDatos()
{
}
