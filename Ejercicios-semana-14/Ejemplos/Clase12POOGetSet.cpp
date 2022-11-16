#include <iostream>

using namespace std;

class Car
{
private:
    // Atributos
    string marca;
    string modelo;
    int anio;
    int estado;
    float kilometraje;
    float gasolina;

public:

    Car();
    Car(string _marca, string _modelo, int _anio, int _estado, float _kilometraje, float _gasolina);
    // Métodos constructores modificadores setter/getter
    void setEstado(int);
    int getEstado();
    void setKilometraje(float);
    int getKilometraje();
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

// Metodo setter/getter
void Car::setEstado(int _estado)
{
    estado = _estado;
}

int Car::getEstado()
{
    return estado;
}
void Car::setKilometraje(float _km)
{
    kilometraje = _km;
}

int Car::getKilometraje()
{
    return kilometraje;
}

void Car::Estado(int estado)
{
    if (estado == 1)
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

float Car::Kilometraje(float _kilometraje)
{
    return kilometraje += _kilometraje;
}

int main()
{
    // Creación del objeto carro
    Car carro1;
    carro1.setEstado(1);
    cout << carro1.getEstado() << endl;
    // Accediendo a un método
    carro1.Estado(carro1.getEstado());
    carro1.setKilometraje(466.62);
    cout << "El kilometraje " << carro1.getKilometraje()<<endl;
    int d = carro1.Distancia(60, 2);
    cout<<"La distancia recorrida en km "<< d <<endl;
    cout<< "El kilometraje actual "<<carro1.Kilometraje(d);

    return 0;
} 