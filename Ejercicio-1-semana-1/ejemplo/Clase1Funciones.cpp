//Estructura, tipos de datos, variables, ambito de variables, funciones
#include <iostream>

using namespace std;

//Variables globales
 int numero3 = 14;
 int numero4 = 5; 

//Declaración de las funciones

int main(){

    //variable local 
    int numero1 = 14;
    int numero2 = 5; 

    int suma1 = numero1 + numero2;
    cout<<suma1;
    /* Ejercicio no evaluado
    Imprimir resultado de funcion sumar y restar 
    Solicitar al usuario los valores de la entrada de sumar y restar. */

    //Llamado a las funciones

    return 0;
}

//Definición de las funciones 

//Funciones sin parámetros 
int sumar(){
    //variable local
   int suma2 = numero3 + numero4;
   return suma2;
}
//funciones sin parámetros 
int restar(){
    //variable local 
    int resta = numero3 - numero4;
    return resta;
}