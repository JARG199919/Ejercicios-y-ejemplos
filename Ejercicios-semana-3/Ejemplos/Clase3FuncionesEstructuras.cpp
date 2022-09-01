#include <iostream>

using namespace std; 

struct Producto
{
    float precio;
    string nombre;
    int cantidad; 
}producto;

struct Producto capturaDatos(struct Producto);
void imprimirProducto(struct Producto);

int main(){

    //producto = capturaDatos(producto);
   // imprimirProducto(producto);

   imprimirProducto(capturaDatos(producto));

    return 0;
}

struct Producto capturaDatos(struct Producto p){

    cout<<"Ingrese el precio ";
    cin>>p.precio;
    cout<<"Ingrese el nombre de producto ";
    getline(cin,p.nombre);
    cout<<"Ingrese la cantidad ";
    cin>>p.cantidad;

    return p; 

}

void imprimirProducto(struct Producto p){
    cout<<"El precio del producto $"<<p.precio;
    cout<<"El nombre del producto "<<p.nombre;
    cout<<"La cantidad del producto "<<p.cantidad;
}