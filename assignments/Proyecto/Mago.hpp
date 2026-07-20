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

    // Métodos sobreescritos (polimorfismo en tiempo de ejecución)
    int calculaAtaque(Personaje& objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    void atacar(Personaje& objetivo) override;
    void imprimir() override;

    // Implementación de revive() usando el maná como "última oportunidad"
    void revive() override;
};