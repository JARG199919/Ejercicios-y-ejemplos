#include <iostream>
#include <string.h>

using namespace std;
//variable global
int num;
//estreuctura
struct Alumno
{
    string nombre;
    string codigo;
    int yearold,edad;

} * alumno1;//se utilizo un puntero para evitar algunos errores

int main(){
    system("cls");
    int contar=0;
    // Ingreso de el tamano de el arreglo tipo estructura
    cout<<"Ingrese la cantidad de nombres a guardar(SOLO NUMEROS): \n";
    cin>>num;
    struct Alumno alumno1[num];
    system("cls");

    // SOLICITAR LA INFORMACION

    for (int i = 0; i < num; i++)
    {   
        contar++;
        cout << "Ingresa el nombre "<<contar<<endl;
        cin.ignore();//ignora el valor nulo del buffer de getline
        getline(cin, alumno1[i].nombre);
        cout << "Ingresa el codigo\n";
        getline(cin, alumno1[i].codigo);
        cout << "Ingresa la fecha de nacimiento\n";
        cin >> alumno1[i].yearold;
        cout << "Ingresa la edad\n";
        cin >> alumno1[i].edad;
        system("cls");
    }

    // IMPRIMIR LA INFORMACION
    system("cls");
    cout << "Los datos ingresados son:\n";
    contar=0;
    for (int i = 0; i < num; i++)
    {   
        contar++;
        cout << contar<<".";
        cout << alumno1[i].nombre + "\n\t";
        cout << "Cod: "<<alumno1[i].codigo + "\t";
        cout << "Fecha: "<<alumno1[i].yearold<<"\tEdad: "<<alumno1[i].edad<<endl;
    }

    return 0;
}