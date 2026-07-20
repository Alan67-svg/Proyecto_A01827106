#pragma once
#include "Personaje.hpp"

// El Arquero se especializa con "precision": porcentaje (0-100) de
// probabilidad de acertar un tiro crítico, y también le ayuda a esquivar.
class Arquero : public Personaje {
private:
    double precision;

public:
    // Constructores
    Arquero();
    Arquero(int vida, int ataque, int nivel, double precision);

    // Getter / Setter del atributo especial
    double getPrecision() const;
    void setPrecision(double precision);

    // Métodos sobreescritos
    int calculaAtaque(Personaje& objetivo);
    void recibeAtaque(int ptosAtaque);
    void imprimir();
};