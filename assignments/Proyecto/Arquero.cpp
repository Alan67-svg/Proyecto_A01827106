#include "Arquero.hpp"
#include <iostream>
#include <cstdlib>

// ---------- Constructores ----------

Arquero::Arquero() : Personaje() {
    precision = 50.0;
}

Arquero::Arquero(int vida, int ataque, int nivel, double precisionInicial)
    : Personaje(vida, ataque, nivel) {
    precision = precisionInicial;
}

// ---------- Getter / Setter ----------

double Arquero::getPrecision() const {
    return precision;
}

void Arquero::setPrecision(double nuevaPrecision) {
    precision = nuevaPrecision;
}

// ---------- Métodos sobreescritos ----------

int Arquero::calculaAtaque(Personaje& objetivo) {
    // Reutiliza el cálculo base de Personaje
    int ataqueBase = Personaje::calculaAtaque(objetivo);

    // Tiro crítico: la probabilidad de acertarlo es igual al % de precisión.
    // Si se logra, el daño aumenta un 50% extra.
    double azar = (rand() % 10000) / 100.0; // número entre 0.0 y 99.99
    if (azar < precision) {
        ataqueBase = ataqueBase + (ataqueBase / 2);
    }

    return ataqueBase;
}

void Arquero::recibeAtaque(int ptosAtaque) {
    // La misma precisión también representa reflejos: una fracción de esa
    // probabilidad le permite esquivar parte del golpe recibido.
    double azar = (rand() % 10000) / 100.0;
    if (azar < (precision / 4.0)) {
        ptosAtaque = ptosAtaque / 2; // esquiva la mitad del daño
    }

    // Reutiliza el recibeAtaque de la clase base con el daño ya ajustado
    Personaje::recibeAtaque(ptosAtaque);

    // Si el golpe lo dejó en 0 de salud, intenta revivir gracias a su precisión
    if (getSalud() <= 0) {
        revive();
    }
}

void Arquero::revive() {
    if (getSalud() > 0) return; // sólo aplica si de verdad quedó en 0

    const double PRECISION_MINIMA = 30.0; // precisión necesaria para revivir
    const double COSTO_PRECISION = 30.0;  // cuánta precisión consume revivir

    if (precision >= PRECISION_MINIMA) {
        int vidaRevivir = getVida() / 5; // revive con el 20% de su vida máxima
        setSalud(vidaRevivir);
        precision -= COSTO_PRECISION; // se debilita, así no revive infinitamente

        std::cout << "Revivio el personaje debido a la precision. "
                  << "Precision restante: " << precision << std::endl;
    } else {
        setSalud(0);
        std::cout << "El Arquero perdio su precision y murio." << std::endl;
    }
}

void Arquero::imprimir() {
    // Reutiliza el imprimir de Personaje y agrega la información propia
    Personaje::imprimir();
    std::cout << "Precision: " << precision << "%" << std::endl;
    std::cout << "----------------------------" << std::endl;
}