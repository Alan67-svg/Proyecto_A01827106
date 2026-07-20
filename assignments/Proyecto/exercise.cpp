#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

int main() {
    srand((unsigned int)time(nullptr));

    Guerrero guerrero(120, 15, 3, 40);
    Arquero arquero(90, 12, 3, 65.0);
    Mago mago(80, 10, 4, 90);

    std::cout << "=== Estado inicial ===" << std::endl;
    guerrero.imprimir();
    arquero.imprimir();
    mago.imprimir();

    std::cout << "\n=== Ronda de combate ===" << std::endl;

    guerrero.atacar(arquero);
    std::cout << "Guerrero ataca a Arquero." << std::endl;
    arquero.imprimir();

    arquero.atacar(mago);
    std::cout << "Arquero ataca a Mago." << std::endl;
    mago.imprimir();

    mago.atacar(guerrero);
    std::cout << "Mago ataca a Guerrero." << std::endl;
    guerrero.imprimir();
    std::cout << "Mana restante del mago: " << mago.getMana() << std::endl;

    return 0;
}