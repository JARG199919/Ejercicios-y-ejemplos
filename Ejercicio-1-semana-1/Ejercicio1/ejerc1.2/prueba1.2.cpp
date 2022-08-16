#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Calculadora sencilla de dos cifras

//Se tratara de agregar array para poder agregar mas numeros para procesamiento

//variables global
float numero1=0, numero2=0,resultado=0;
int num, repiter=1;

//Funciones
void entradaDatos(),proceso2(), inicio();

//programa principal
int main(){
    system("cls");
    while (repiter==1){
    inicio();
    entradaDatos();
    proceso2();
    printf("la respuesta es: %.2f\n\n1.Volver al inicio\n2.Salir\n",resultado);
    scanf("%d",&repiter);
    system("cls");
    }
}

// Definiciones de funciones

//Pantalla de informacion
void inicio(){ 
printf("Ingrese un numero\n 1.suma \n 2.resta \n 3.Multiplicacion \n 4.Division\n");
   scanf("%d",&num);
   while (num > 4){
    system("cls");
    printf("Vuelva a ingresar el numero\n 1.suma \n 2.resta \n 3.Multiplicacion \n 4.Division\n");
       scanf("%d",&num);
   }
}
//Obtencion de datos de entrada
void entradaDatos(){
    system("cls");
    printf("Se ha selecionado, ");
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
    scanf("%f",&numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%f",&numero2);
}
//Procesamineto de datos
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