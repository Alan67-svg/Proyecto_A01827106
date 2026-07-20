#pragma once
#include <string>
#include <iostream>

// Personaje es la clase base (Unidad/Combatiente). Al tener un método
// virtual puro (revive) se convierte en una clase ABSTRACTA: no se pueden
// crear objetos de tipo Personaje directamente, sólo de sus clases derivadas.
class Personaje{
private:
    int vida;    // puntos de vida máximos
    int salud;   // puntos de vida actuales
    int ataque;  // puntos máximos de ataque
    int nivel;   // nivel del personaje
public:
//constructores
Personaje();
Personaje(int vida, int ataque, int nivel);

// Destructor virtual: obligatorio porque vamos a borrar objetos derivados
// a través de un apuntador a la clase base (Personaje*).
virtual ~Personaje();

    // Getters
    int getVida() const;
    int getSalud() const;
    int getAtaque() const;
    int getNivel() const;

    // Setters
    void setVida(int vida);
    void setSalud(int salud);
    void setAtaque(int ataque);
    void setNivel(int nivel);

    // Métodos adicionales
    int porcentajeSalud();
    void imprimeBarra();

    // Se marcan como "virtual" para que las clases derivadas puedan
    // sobreescribirlos y se resuelvan en tiempo de ejecución (polimorfismo).
    virtual int calculaAtaque(Personaje& objetivo);
    virtual void recibeAtaque(int ptosAtaque);
    virtual void atacar(Personaje& objetivo);
    virtual void imprimir();

    // Método virtual puro: no tiene implementación en Personaje porque
    // "estar vivo o no" depende del atributo especial de cada clase derivada.
    // Esto es lo que vuelve abstracta a la clase.
    virtual void revive() = 0;
};

// Sobrecarga del operador de flujo de salida. Al recibir un Personaje&,
// si el objeto real es un Guerrero/Arquero/Mago, se invoca el imprimir()
// correspondiente de forma polimórfica gracias a que imprimir() es virtual.
std::ostream& operator<<(std::ostream& os, Personaje& personaje);