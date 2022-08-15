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
printf("Ingrese un numero\n 1.suma \n 2.resta \n");
   scanf("%d",&num);
   while (num > 2){
    system("cls");
    printf("Vuelva a ingresar el numero\n 1.suma \n 2.resta \n");
       scanf("%d",&num);
   }
}
void entradaDatos(){
    system("cls");
   if (num==1){
    printf("Suma\n");
   }else{
    printf("Resta\n");
   }
    printf("Ingrese el primer numero: ");
    scanf("%d",&numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numero2);
}
void proceso2(){
    if(num==1){
        resultado=numero1+numero2;
    }else{
        resultado=numero1-numero2;
    }  
}