#include "Guerrero.hpp"
#include <iostream>

// ---------- Constructores ----------

Guerrero::Guerrero() : Personaje() {
    fuerza = 10;
}

Guerrero::Guerrero(int vida, int ataque, int nivel, int fuerzaInicial)
    : Personaje(vida, ataque, nivel) {
    fuerza = fuerzaInicial;
}

// ---------- Getter / Setter ----------

int Guerrero::getFuerza() const {
    return fuerza;
}

void Guerrero::setFuerza(int nuevaFuerza) {
    fuerza = nuevaFuerza;
}

// ---------- Métodos sobreescritos ----------

int Guerrero::calculaAtaque(Personaje& objetivo) {
    // Reutiliza el cálculo base de Personaje
    int ataqueBase = Personaje::calculaAtaque(objetivo);

    // La fuerza potencia el ataque: cada 10 puntos de fuerza dan 1 punto extra
    int bono = fuerza / 10;

    return ataqueBase + bono;
}

void Guerrero::recibeAtaque(int ptosAtaque) {
    // La fuerza actúa como armadura: reduce el daño recibido hasta un máximo del 50%
    int reduccion = (ptosAtaque * fuerza) / 200; // ej. fuerza=40 -> 20% de reducción
    if (reduccion > ptosAtaque / 2) {
        reduccion = ptosAtaque / 2; // tope de reducción del 50%
    }

    int danioFinal = ptosAtaque - reduccion;
    if (danioFinal < 0) danioFinal = 0;

    // Reutiliza el recibeAtaque de la clase base con el daño ya ajustado
    Personaje::recibeAtaque(danioFinal);
}

void Guerrero::imprimir() {
    // Reutiliza el imprimir de Personaje y agrega la información propia
    Personaje::imprimir();
    std::cout << "Fuerza: " << fuerza << std::endl;
    std::cout << "----------------------------" << std::endl;
}#include "Guerrero.hpp"
#include <iostream>

// ---------- Constructores ----------

Guerrero::Guerrero() : Personaje() {
    fuerza = 10;
}

Guerrero::Guerrero(int vida, int ataque, int nivel, int fuerzaInicial)
    : Personaje(vida, ataque, nivel) {
    fuerza = fuerzaInicial;
}

// ---------- Getter / Setter ----------

int Guerrero::getFuerza() const {
    return fuerza;
}

void Guerrero::setFuerza(int nuevaFuerza) {
    fuerza = nuevaFuerza;
}

// ---------- Métodos sobreescritos ----------

int Guerrero::calculaAtaque(Personaje& objetivo) {
    // Reutiliza el cálculo base de Personaje
    int ataqueBase = Personaje::calculaAtaque(objetivo);

    // La fuerza potencia el ataque: cada 10 puntos de fuerza dan 1 punto extra
    int bono = fuerza / 10;

    return ataqueBase + bono;
}

void Guerrero::recibeAtaque(int ptosAtaque) {
    // La fuerza actúa como armadura: reduce el daño recibido hasta un máximo del 50%
    int reduccion = (ptosAtaque * fuerza) / 200; // ej. fuerza=40 -> 20% de reducción
    if (reduccion > ptosAtaque / 2) {
        reduccion = ptosAtaque / 2; // tope de reducción del 50%
    }

    int danioFinal = ptosAtaque - reduccion;
    if (danioFinal < 0) danioFinal = 0;

    // Reutiliza el recibeAtaque de la clase base con el daño ya ajustado
    Personaje::recibeAtaque(danioFinal);
}

void Guerrero::imprimir() {
    // Reutiliza el imprimir de Personaje y agrega la información propia
    Personaje::imprimir();
    std::cout << "Fuerza: " << fuerza << std::endl;
    std::cout << "----------------------------" << std::endl;
}