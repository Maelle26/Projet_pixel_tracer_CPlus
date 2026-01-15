// Fichier Circle.cpp
# include "Circle.h"
# include "Pixel.h"

//Constructeurs
Circle::Circle(const Point& c, int r) : Shape(), center(c), radius(r) {}

//Constructeur paramétré avec coordonnées
Circle::Circle(int x, int y, int r) : Shape(), center(x, y), radius(r) {}

//Méthode pour afficher les informations du cercle
void Circle::print() const {
    std::cout << "CIRCLE " << center.getPosX() << " "
    << center.getPosY() << " " << radius << std::endl;
}

//Méthode pour convertir le cercle en une liste de pixels
std::vector<Pixel> Circle::toPixels() const {
    // Implémentation de l'algorithme d'Andres/Bresenham
    // (sera détaillée dans la partie 2)
    std::vector<Pixel> pixels;
    // ... code de l'algorithme ...
    return pixels;
}