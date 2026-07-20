#pragma once
#include "Personaje.hpp"

// El Guerrero se especializa con "fuerza": mientras más fuerza tiene,
// más daño inflige y menos daño recibe de sus enemigos.
class Guerrero : public Personaje {
private:
    int fuerza;

public:
    // Constructores
    Guerrero();
    Guerrero(int vida, int ataque, int nivel, int fuerza);

    // Getter / Setter del atributo especial
    int getFuerza() const;
    void setFuerza(int fuerza);

    // Métodos sobreescritos
    int calculaAtaque(Personaje& objetivo);
    void recibeAtaque(int ptosAtaque);
    void imprimir();
};