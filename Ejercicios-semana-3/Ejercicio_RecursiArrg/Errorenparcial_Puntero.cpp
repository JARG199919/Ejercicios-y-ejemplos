#include <iostream>

using namespace std;

int main()
{
   /* int arreglo[4]={2,3,4,5};
    int *ptr;


    for (*ptr= 0; *ptr < 4; *ptr++)
    {
        cout<<arreglo[*ptr]<<endl;
    }
*/
   int vector[5]={0,1,2,3,4};
    int *p;
    int i;

    p=&vector[0];//puntero apunte a la dirección del primer elemento del vector

    for(i=0; i<5; i++)
    {
        printf("%d \n\n", *p);
        p++;//El puntero se incrementa para apuntar al siguiente entero
    

    }
    return 0;
}
