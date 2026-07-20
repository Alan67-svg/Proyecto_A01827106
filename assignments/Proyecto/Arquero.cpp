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
}

void Arquero::imprimir() {
    // Reutiliza el imprimir de Personaje y agrega la información propia
    Personaje::imprimir();
    std::cout << "Precision: " << precision << "%" << std::endl;
    std::cout << "----------------------------" << std::endl;
}