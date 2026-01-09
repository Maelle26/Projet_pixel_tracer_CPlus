// Fichier Point.cpp
# include "Point.h"

//Méthodes

//Constructeur par défaut: initialise un point à l'origine (0,0)
Point::Point() : posX(0), posY(0) {
    posX = 0;
    posY = 0;
}
Point::Point(int x, int y) : posX(x), posY(y) {}
Point::Point(const Point& other) : posX(other.posX), posY(other.posY) {}
Point::~Point() {
    // Rien à libérer car pas d'allocation dynamique
}

void Point::print() const {
    std::cout << "POINT " << posX << " " << posY << std::endl;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        posX = other.posX;
        posY = other.posY;
    }
    return *this;
}

bool Point::operator==(const Point& other) const {
    return (posX == other.posX && posY == other.posY);
}