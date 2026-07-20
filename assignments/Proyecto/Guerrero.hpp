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

    // Métodos sobreescritos (polimorfismo en tiempo de ejecución)
    int calculaAtaque(Personaje& objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    void imprimir() override;

    // Implementación de revive() usando la fuerza como "última oportunidad"
    void revive() override;
};