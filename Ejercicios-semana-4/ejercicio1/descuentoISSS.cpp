#include <iostream>

using namespace std;

// ejemplo para retroalimentar

int arry, contar = 0;
struct registro
{
    double sueldo, total;

} * datos;

double descuentoISSS(double mat);
void proceso(), mostrar();

int main()
{
    proceso();
    cout << "\n";
    mostrar();

    return 0;
}
double descuentoISSS(double mat)
{
    double des;
    des = mat * 0.15;
    return des;
}
void mostrar()
{
    contar = 0;
    for (int i = 0; i < arry; i++)
    {
        contar++;
        cout << contar << ".Salario: " << datos[i].sueldo << "\nDescuento: " << descuentoISSS(datos[i].sueldo) << "\nTotal: " << datos[i].total << endl
             << endl;
    }
}
void proceso()
{
    cout << "Ingrese la cantidad a guardar: " << endl;
    cin >> arry;

    datos = new registro[arry];

    for (int i = 0; i < arry; i++)
    {
        contar++;
        cout << "Ingrese el " << contar << " salario: " << endl;
        cin >> datos[i].sueldo;
        datos[i].total = datos[i].sueldo - descuentoISSS(datos[i].sueldo);
    }
}