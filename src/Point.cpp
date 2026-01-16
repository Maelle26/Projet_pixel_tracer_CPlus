// Fichier Point.cpp
# include "Point.h"
# include "Pixel.h"
#include <iostream>
#include <vector>

//Constructeur par défaut: initialise un point à l'origine (0,0)
Point::Point() : posX(0), posY(0) {
    posX = 0;
    posY = 0;
}

//Constructeur paramétré: initialise un point aux coordonnées (x,y)
Point::Point(int x, int y) : posX(x), posY(y) {
    posX = x;
    posY = y;
}

//Constructeur de copie: initialise un point en copiant un autre point
Point::Point(const Point& other) : posX(other.posX), posY(other.posY) {
    posX = other.posX;
    posY = other.posY;
}

//Destructeur: libère les ressources si nécessaire
Point::~Point() {
    // Pas de ressources dynamiques à libérer dans cette classe

}

//Méthode pour afficher les coordonnées du point
void Point::print() const {
    std::cout << "POINT " << posX << " " << posY << std::endl;
}

//Méthode pour assigner un point à un autre
Point& Point::operator=(const Point& other) {
    if (this != &other) {
        posX = other.posX;
        posY = other.posY;
    }
    return *this;
}

//Méthode pour comparer deux points et vérifier s'ils sont égaux
bool Point::operator==(const Point& other) const {
    return (posX == other.posX && posY == other.posY);
}

//Méthode pour convertir le point en une liste de pixels (1 pixel = 1 point)
std::vector<Pixel> Point::toPixels() const {
    std::vector<Pixel> pixels;
    pixels.push_back(Pixel(posX, posY));
    return pixels;
}