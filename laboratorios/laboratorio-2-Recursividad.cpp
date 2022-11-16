#include <iostream>
using namespace std;

void proceso(int *arreglo, float suma, int i);

int main()
{
    int arreglo[] = {3, 2, 6, 4, 8, 1, 6, 7}, suma = 0, i = 0;

    proceso(arreglo, suma, i);
    return 0;
}

void proceso(int *arreglo, float suma, int i)
{

    if (i >= 8)
    {
        // cout<<"Los datos son :"<<arreglo[i]<<endl;
        cout << "promedio :" << suma / 8 << endl;
        return;
    }
    else
    {
        suma += arreglo[i];
        proceso(arreglo, suma, i + 1);
    }
}
