//GEnera la implementación de la clase base Personaje
#include "Personaje.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

// ---------- Constructores ----------

Personaje::Personaje() {
    vida = 100;
    salud = vida;
    ataque = 10;
    nivel = 1;
}

Personaje::Personaje(int vidaMax, int ataqueBase, int nivelInicial) {
    vida = vidaMax;
    salud = vidaMax;
    ataque = ataqueBase;
    nivel = nivelInicial;
}

// ---------- Getters ----------

int Personaje::getVida() const {
    return vida;
}

int Personaje::getSalud() const {
    return salud;
}

int Personaje::getAtaque() const {
    return ataque;
}

int Personaje::getNivel() const {
    return nivel;
}

// ---------- Setters ----------
void Personaje::setVida(int nuevaVida) {
    vida = nuevaVida;
}

void Personaje::setSalud(int nuevaSalud) {
    salud = nuevaSalud;
}

void Personaje::setAtaque(int nuevoAtaque) {
    ataque = nuevoAtaque;
}

void Personaje::setNivel(int nuevoNivel) {
    nivel = nuevoNivel;
}
// ---------- Métodos adicionales ----------

int Personaje::porcentajeSalud() {
    if (vida <= 0) return 0;
    int porcentaje = (salud * 100) / vida;
    if (porcentaje < 0) porcentaje = 0;
    if (porcentaje > 100) porcentaje = 100;
    return porcentaje;
}

void Personaje::imprimeBarra() {
    const int TOTAL_CARACTERES = 20;
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * TOTAL_CARACTERES) / 100;
    int vacios = TOTAL_CARACTERES - llenos;

    std::cout << "[";
    for (int i = 0; i < llenos; i++) {
        std::cout << "%";
    }
    for (int i = 0; i < vacios; i++) {
        std::cout << "=";
    }
    std::cout << "] " << porcentaje << "%" << std::endl;
}

int Personaje::calculaAtaque(Personaje& objetivo) {
    int puntosCalculados;

    if (objetivo.getNivel() > nivel) {
        int mitad = ataque / 2;
        if (mitad < 1) mitad = 1;
        puntosCalculados = (rand() % mitad) + 1;
    } else {
        int mitad = ataque / 2;
        int rango = ataque - mitad + 1;
        if (rango < 1) rango = 1;
        puntosCalculados = mitad + (rand() % rango);
    }

    return puntosCalculados;
}

void Personaje::recibeAtaque(int ptosAtaque) {
    salud -= ptosAtaque;
    if (salud < 0) {
        salud = 0;
    }
}

void Personaje::atacar(Personaje& objetivo) {
    int danio = calculaAtaque(objetivo);
    objetivo.recibeAtaque(danio);
}

void Personaje::imprimir() {
    std::cout << "----------------------------" << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Vida maxima: " << vida << std::endl;
    std::cout << "Salud actual: " << salud << std::endl;
    std::cout << "Ataque: " << ataque << std::endl;
    std::cout << "Barra de vida: ";
    imprimeBarra();
    std::cout << "----------------------------" << std::endl;
}