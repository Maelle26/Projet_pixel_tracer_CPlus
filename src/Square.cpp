//Fichier Square.cpp
#include "Square.h"
#include "Line.h"
# include "Pixel.h"

//Constructeur
Square::Square(const Point& tl, int l):Shape(),topLeft(tl),length(l){}

//Constructeur avec coordonnées
Square::Square(int x, int y, int l):Shape(), topLeft(x,y),length(l){}

//Méthode pour afficher les informations du cercle
void Square::print() const {
    std::cout << "SQUARE " << topLeft.getPosX() << " " << topLeft.getPosY() << " " << length << std::endl;
}

//Méthode pour convertir le carré en une liste de pixels
std::vector<Pixel>Square::toPixels() const {
    // Implémentation de l'algorithme d'Andres/Bresenham
    // (sera détaillée dans la partie 2)
    std::vector<Pixel> pixels;
    //...code de l'algorithme...
    return pixels;
}