#include <iostream>

using namespace std;

class Car
{
public:
    string marca;
    string modelo;
    int anio;
    int estado;
    float kilometraje;
    float gasolina;
    // Constructor por defecto
   Car();
    // Constructor con parametros
    Car(string _marca, string _modelo, int _anio, int _estado, float _kilometraje, float _gasolina);
    string Marca();
    void Estado(int estado);
    float Distancia(float velocidad, float tiempo);
    float Kilometraje(float kilometraje);
};

// Constructor por defecto
Car::Car() {}

// Constructor con parametros
Car::Car(string _marca, string _modelo, int _anio, int _estado, float _kilometraje, float _gasolina)
{
    marca = _marca;
    modelo = _modelo;
    anio = _anio;
    estado = _estado;
    kilometraje = _kilometraje;
    gasolina = _gasolina;
}

void Car::Estado(int _estado)
{
    if (_estado == 1)
    {
        cout << "Estoy encendido" << endl;
    }
    else
    {
        cout << "Estoy apagado" << endl;
    }
}
float Car::Distancia(float velocidad, float tiempo)
{
    int distancia;
    // d = v.t
    distancia = velocidad * tiempo;
    return distancia;
}

float Car::Kilometraje(float _kilometraje){
   return kilometraje += _kilometraje;
}


int main()
{
    // Creación del objeto carro1 
    Car carro1("Nissan", "Sentra", 2020, 0, 466.2, 1.5);
    cout<<carro1.marca<<", " <<carro1.modelo <<", "<<carro1.anio<<", "<<carro1.kilometraje<<", "<<carro1.gasolina<<endl;
    // Accediendo a un método
    carro1.Estado(carro1.estado);
    cout << "El kilometraje actual " <<carro1.kilometraje<<endl;
    int d = carro1.Distancia(60,2);
    cout << "La distancia recorrida km " <<d<<endl;
    cout<<"Kilometraje actual "<< carro1.Kilometraje(d);
    return 0;
}