#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

int main() {
    srand((unsigned int)time(nullptr));

    // Vector de apuntadores a la clase base ABSTRACTA Personaje.
    // No se puede hacer "new Personaje(...)" porque revive() es virtual puro,
    // pero sí podemos apuntar a objetos de sus clases derivadas.
    std::vector<Personaje*> combatientes;

    combatientes.push_back(new Guerrero(120, 15, 3, 60));   // combatientes[0]
    combatientes.push_back(new Arquero(90, 12, 3, 55.0));   // combatientes[1]
    combatientes.push_back(new Mago(80, 10, 4, 90));        // combatientes[2]

    // ---------- Imprimir a los 3 personajes ----------
    std::cout << "=== Estado inicial ===" << std::endl;
    for (size_t i = 0; i < combatientes.size(); i++) {
        // Aunque el tipo estático del apuntador es Personaje*, como imprimir()
        // es virtual, en tiempo de ejecución se llama a la version de
        // Guerrero, Arquero o Mago segun corresponda (polimorfismo).
        combatientes[i]->imprimir();
    }

    // ---------- Pelea: el primero ataca al segundo y al tercero ----------
    std::cout << "\n=== Ronda de combate ===" << std::endl;
    for (size_t i = 1; i < combatientes.size(); i++) {
        // atacar() es virtual: si el atacante es un Mago, se ejecuta el
        // atacar() de Mago (que ademas recupera mana si el objetivo muere);
        // calculaAtaque() y recibeAtaque() tambien se resuelven de forma
        // polimorfica del lado del atacante y del atacado respectivamente.
        combatientes[0]->atacar(*combatientes[i]);

        std::cout << "\nEl combatiente 1 ataco al combatiente " << (i + 1)
                  << ", quedando asi:" << std::endl;
        combatientes[i]->imprimir();
    }

    // ---------- Prueba de la sobrecarga del operador << ----------
    std::cout << "\n=== Prueba del operador << sobrecargado ===" << std::endl;
    for (size_t i = 0; i < combatientes.size(); i++) {
        // *combatientes[i] desreferencia el apuntador y nos da el Personaje&;
        // operator<< internamente llama a imprimir() de forma polimorfica.
        std::cout << *combatientes[i];
    }

    // ---------- Liberar la memoria reservada dinamicamente ----------
    for (size_t i = 0; i < combatientes.size(); i++) {
        delete combatientes[i];
    }
    combatientes.clear();

    return 0;
}