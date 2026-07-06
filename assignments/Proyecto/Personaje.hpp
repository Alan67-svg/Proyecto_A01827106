// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#pragma once
#include <string>

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
    int calculaAtaque(Personaje& objetivo);
    void recibeAtaque(int ptosAtaque);
    void atacar(Personaje& objetivo);
    void imprimir();


};