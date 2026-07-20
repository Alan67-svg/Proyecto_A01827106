#include "Mago.hpp"
#include <iostream>
#include <cstdlib>

// ---------- Constructores ----------

Mago::Mago() : Personaje() {
    mana = 100;
}

Mago::Mago(int vida, int ataque, int nivel, int manaInicial)
    : Personaje(vida, ataque, nivel) {
    mana = manaInicial;
}

// ---------- Getter / Setter ----------

int Mago::getMana() const {
    return mana;
}

void Mago::setMana(int nuevoMana) {
    if (nuevoMana < 0) nuevoMana = 0;
    if (nuevoMana > 100) nuevoMana = 100;
    mana = nuevoMana;
}

// ---------- Métodos sobreescritos ----------

int Mago::calculaAtaque(Personaje& objetivo) {
    // Reutiliza el cálculo base de Personaje
    int ataqueBase = Personaje::calculaAtaque(objetivo);

    if (mana <= 0) {
        // Sin maná, el mago pierde fuerza en sus ataques
        return ataqueBase / 2;
    }

    // Entre más maná tenga, mayor probabilidad de lanzar un hechizo fuerte
    int azar = rand() % 100;
    if (azar < mana) {
        int costoMana = 20;
        if (costoMana > mana) costoMana = mana;
        mana -= costoMana; // usar el hechizo consume maná

        return ataqueBase * 2; // hechizo fuerte: duplica el daño de ese ataque
    }

    return ataqueBase;
}

void Mago::recibeAtaque(int ptosAtaque) {
    int nivelMago = getNivel();
    int danioFinal = ptosAtaque;

    if ((nivelMago == 4 || nivelMago == 5) && mana > 80) {
        danioFinal = ptosAtaque / 3;        // sólo pasa 1/3 del daño
    } else if ((nivelMago == 3 || nivelMago == 4) && mana > 85) {
        danioFinal = ptosAtaque / 2;        // sólo pasa la mitad del daño
    } else if ((nivelMago == 1 || nivelMago == 2) && mana >= 100) {
        danioFinal = (ptosAtaque * 3) / 4;  // sólo pasa 3/4 del daño
    }

    // Reutiliza el recibeAtaque de la clase base con el daño ya ajustado
    Personaje::recibeAtaque(danioFinal);
}

void Mago::atacar(Personaje& objetivo) {
    int danio = calculaAtaque(objetivo);
    objetivo.recibeAtaque(danio);

    // Si el ataque del mago elimina al enemigo, recupera algo de maná
    if (objetivo.getSalud() <= 0) {
        setMana(mana + 15);
    }
}

void Mago::imprimir() {
    // Reutiliza el imprimir de Personaje y agrega la información propia
    Personaje::imprimir();
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "----------------------------" << std::endl;
}