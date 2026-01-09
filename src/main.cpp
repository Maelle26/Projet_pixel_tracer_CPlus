#include <iostream>
#include "../include/Point.h"

int main() {
    // Test du constructeur par défaut (0,0)
    Point p1;
    std::cout << "p1 (defaut) : ";
    p1.print(); // Doit afficher POINT 0 0

    // Test du constructeur paramétré
    Point p2(10, 15);
    std::cout << "p2 (parametre) : ";
    p2.print(); // Doit afficher POINT 10 15

    // Test des Setters et Getters
    p1.setPosX(5);
    p1.setPosY(8);
    std::cout << "p1 modifie : POINT " << p1.getPosX() << " " << p1.getPosY() << std::endl;

    // Test de l'opérateur d'égalité (==)
    Point p3(10, 15);
    if (p2 == p3) {
        std::cout << "Succes : p2 est egal a p3" << std::endl;
    }

    // Test de l'opérateur d'affectation (=)
    p1 = p2;
    std::cout << "p1 apres affectation (doit valoir p2) : ";
    p1.print();

    return 0;
}