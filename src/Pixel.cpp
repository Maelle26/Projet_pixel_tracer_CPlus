// Fichier Pixel.cpp
# include "Pixel.h"

//Constructeur par défaut
Pixel::Pixel() : x(0), y(0) {}

//Constructeur paramétré
Pixel::Pixel(int px, int py) : x(px), y(py) {}

//Constructeur de copie
Pixel::Pixel(const Pixel& other) : x(other.x), y(other.y) {}

//Destructeur
Pixel::~Pixel() {}

//Opérateurs
Pixel& Pixel::operator=(const Pixel& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

//Méthode pour comparer deux pixels et vérifier s'ils sont égaux
bool Pixel::operator==(const Pixel& other) const {
    return (x == other.x && y == other.y);
}
