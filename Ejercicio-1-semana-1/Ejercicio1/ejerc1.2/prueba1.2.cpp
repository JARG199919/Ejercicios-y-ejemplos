#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//variables global
int numero1=0, numero2=0,resultado=0, num;

//Funciones
void entradaDatos(),proceso2(), inicio();
int main(){
    system("cls");
    inicio();
    entradaDatos();
    proceso2();
    printf("la respuesta es: %d",resultado);
    return 0;
}
// Definiciones de funciones
void inicio(){ 
printf("Ingrese un numero\n 1.suma \n 2.resta \n 3.Multiplicacion \n 4.Division\n");
   scanf("%d",&num);
   while (num > 4){
    system("cls");
    printf("Vuelva a ingresar el numero\n 1.suma \n 2.resta \n 3.Multiplicacion \n 4.Division\n");
       scanf("%d",&num);
   }
}
void entradaDatos(){
    system("cls");
    printf("Se ha selecionado ");
    switch (num){
    case 1:printf("Suma\n");
        break;
    case 2:printf("Resta\n");
        break;
    case 3:printf("Multiplicacion\n");
        break;
    case 4:printf("Division\n");
        break;
    }
    printf("Ingrese el primer numero: ");
    scanf("%d",&numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numero2);
}
void proceso2(){
    switch (num){
    case 1:resultado=numero1+numero2;
        break;
    case 2:resultado=numero1-numero2;
        break;
    case 3:resultado=numero1*numero2;
        break;
    case 4:resultado=numero1/numero2;
        break;
    }  
}