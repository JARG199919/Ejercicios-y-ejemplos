#include <iostream>

using namespace std;

//variable global
//se uso punteros
int suma,num;

//Estructura

struct datos1
{
    string nombre;
    float precio;
    int cantidad;

} *InDatos;
//Funciones
//struct datos1 principal(struct datos1 );
void Inentrada();
void salida();

int main()
{
    Inentrada();
    
    for (int i = 0; i < num; i++)
    {
    cout<<"Ingrese el nombre de producto :";

    getline(cin,InDatos[i].nombre);
    cin.ignore();
    cout<<"Ingrese el precio ";
    cin>>InDatos[i].precio;
    cout<<"Ingrese la cantidad ";
    cin>>InDatos[i].cantidad;
    }
    salida();
      
   

    return 0;
}
void Inentrada(){
    system("cls");
    cout<<"Ingrese la cantidad de productos a guardar:"<<endl;
    cin>>num;
    datos1 InDatos[num];
    cin.ignore();
    
}
/*struct datos1 principal(struct datos1 *p){
    for (int i = 0; i < num; i++)
    {
    cout<<"Ingrese el nombre de producto ";
    getline(cin,InDatos.nombre[i]);
    cout<<"Ingrese el precio ";
    cin.ignore();
    cin>>InDatos.precio[i];
    cout<<"Ingrese la cantidad ";
    cin>>InDatos.cantidad[i];
    }
    return *p;
}*/
void salida(){

    for (int i = 0; i < num; i++)
    {
    cout<<"El nombre del producto "<<InDatos[i].nombre<<ends;
    cout<<"El precio del producto $"<<InDatos[i].precio<<ends;
    cout<<"La cantidad del producto "<<InDatos[i].cantidad<<endl<<endl;
      suma +=InDatos[i].cantidad;
    }
    
    cout<<"El total de la cantidad ingresada: "<<suma<<endl;
    

    
    
}
