#pragma once
#include "Personaje.hpp"

// El Mago se especializa con "mana": su energía mágica (0-100).
// El maná potencia su ataque, protege parte de la salud recibida
// y se recupera un poco cuando su ataque elimina al enemigo.
class Mago : public Personaje {
private:
    int mana;

public:
    // Constructores
    Mago();
    Mago(int vida, int ataque, int nivel, int mana);

    // Getter / Setter del atributo especial
    int getMana() const;
    void setMana(int mana);

    // Métodos sobreescritos
    int calculaAtaque(Personaje& objetivo);
    void recibeAtaque(int ptosAtaque);
    void atacar(Personaje& objetivo);
    void imprimir();
};