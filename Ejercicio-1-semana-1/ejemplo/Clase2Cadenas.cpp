#include <iostream>
#include <string.h>

using namespace std;

int main (){

    /************************Cadenas ***************************/

//Declaración e inicializacion char 
char nombre [] = {'M','a','r','l','e','n','e'};
char apellido [] = {'A','g','u','i','l','a','r'};
char nombre2 [] = "Marlene";

string nombre3 = "Marlene";

string apellido3 = "Aguilar";

///Actividad no evaluada 

//Solicitar al usuario nombre, apellido, aplicar concatenacion, y mayusculas a nombre y apellido, si ya es mayúscula
//entonces solo aplicar la concatenación. 

//Decidir utilizar char o string y hacer uso de getline()

//Operaciones con cadena de caracteres 

//función concatenar char 
strcat(nombre,apellido);
//Función convertir a mayúscula
strupr(nombre);

//Operaciones con string

//Concatenar utilizando el operador + 
string nombreCompleto = nombre3 + apellido3;
//Concatenar utilizando la función
string nombreCompleto = nombre3.append(apellido3);








}