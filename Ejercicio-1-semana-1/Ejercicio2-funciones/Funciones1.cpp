#include  <iostream>
#include <stdio.h>

using namespace std;

/* Ejercicio no evaluado
    Imprimir resultado de funcion sumar y restar 
    Solicitar al usuario los valores de la entrada de sumar y restar. */

//variables global
int numero1=0, numero2=0,resultado1,resultado2,num=1;

//Funciones
void entrada(),proceso();

int main(){
    system("cls");
    while (num==1){
    entrada();
    proceso();
    printf("\n1.Volver al inicio\n2.Salir\n");
    scanf("%d",&num);
    system("cls");
    }
    return 0;
}
//definiciones de funciones
void entrada(){
    printf("Ingrese una cifra: ");
    cin>>numero1;
    printf("Ingrese otra cifra: ");
    cin>>numero2;
}
void proceso(){
    resultado1=numero1+numero2;
    resultado2=numero1-numero2;
    printf("Resultado de la suma: %d \nResultado de la resta: %d\n",resultado1,resultado2);
}