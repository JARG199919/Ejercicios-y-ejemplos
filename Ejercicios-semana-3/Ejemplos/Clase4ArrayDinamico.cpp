#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	
	//Crear una función para la captura de datos 
	
    //Declarar variables y punteros 
    int numEdad; 
    int *ptr;
    cout<<"Ingrese el numero de edades ";
    cin>>numEdad;
    //arreglo estatico en compilacion
    //int ptr[numEdad];
    //Arreglo dinamico en tiempo de ejecucion
    ptr = new int[numEdad]; 

    for( int i = 0; i < numEdad; i++)
    {
        cout<<"Ingrese las edades ";
        cin>>ptr[i];
    }
    

    //Liberar memoria 
    delete[]ptr;

return 0;
}
