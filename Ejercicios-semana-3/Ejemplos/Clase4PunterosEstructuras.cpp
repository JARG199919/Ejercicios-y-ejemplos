#include <iostream>

using namespace std;

struct Persona
{
    char nombre[30];
    int edad;
    float altura;
    float peso;
    // Declaración de variable y puntero
} persona1, *ptr_persona1;

int main()
{
    // Asignando valores a los miembros de la estructura
    persona1 = {"Roberto Nolasco", 36, 1.82, 85};
    // Declaración de puntero de estructura
    Persona *ptr_persona1;
    // Dirección de memoria de la estructura
    ptr_persona1 = &persona1;
    // Acceder a un campo de la estructura utilizando punteros
    ptr_persona1->nombre;
    ptr_persona1->edad;
    ptr_persona1->altura;
    ptr_persona1->peso;

    return 0;
}