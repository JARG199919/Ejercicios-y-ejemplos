 #include <iostream>

using namespace std;

int factorial(int);
int FactorialIterativo(int);

int main()
{

    cout << "Solución Recursiva: " << factorial(3) << endl;
    cout << "Solución Iterativa: " << FactorialIterativo(3);
    return 0;
}

// Recursiva
int factorial(int n)
{ // cálculo de n!
    // Condición de salida
    if (n <= 1)
        return 1;
    else
        // Se realiza el llamado a la función nuevamente
        return n * factorial(n - 1);
}

// Iterativa
int FactorialIterativo(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}