#include <iostream>
#include <string.h>

using namespace std;

class Juego
{
private:
    string titulo;
    string plataforma;
    int anio;
    int horas;

public:
    Juego();
    Juego(string, string, int, int);

    string getTitulo();
    void setTitulo(string title);

    string getPlataforma();
    void setPlataforma(string platform);

    int getAnio();
    void setAnio(int year);

    int getHoras();
    void setHoras(int hours);

    void mostrar();
    void addhoras(int addHORAS);
    //void inserDatos(string titular, string plat, int year);
    string mostrarS(string til, string plat);
    int mostrarI(int m, int c);
};

Juego::Juego()
{
}
Juego::Juego(string titular,string plat,int lanzamiento, int hora)
{
    titulo = titular;
    plataforma = plat;
    anio = lanzamiento;
    horas = hora;
}
/*void Juego::inserDatos(string titular, string plat, int year){
    Juego::setTitulo(titular);
    Juego::setPlataforma(plat);
    Juego::setAnio(year);
}*/

void Juego::mostrar()
{
    cout << "Nombre del juego: " << titulo << "\n"
         << "Plataforma: " << plataforma << "\n"
         << "Lanzamiento: " << anio << "\n"
         << "Horas jugadas: " << horas << "\n";
}
void Juego::addhoras(int addHORAS)
{
    Juego::setHoras(addHORAS);
}
void Juego::setTitulo(string title)
{
    titulo = title;
}
void Juego::setPlataforma(string platform)
{
    plataforma = platform;
}
void Juego::setAnio(int year)
{
    anio = year;
}
void Juego::setHoras(int hours)
{
    horas = hours;
}
string Juego::getTitulo()
{
    return titulo;
}
string Juego::getPlataforma()
{
    return plataforma;
}
int Juego::getAnio()
{
    return anio;
}
int Juego::getHoras()
{
    return horas;
}