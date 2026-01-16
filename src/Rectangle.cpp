//Fichier Rectangle.cpp
#include "Rectangle.h"
#include "Line.h"
#include "Pixel.h"


//Constructeur
Rectangle::Rectangle(const Point& tl, int w, int h):Shape(),topLeft(tl),width(w),height(h){}

//Constructeur avec coordonnées
Rectangle::Rectangle(int x, int y, int w, int h):Shape(), topLeft(x,y),width(w),height(h){}

//Méthode pour afficher les informations du Rcetangle
void Rectangle::print() const{
    std::cout << "RECTANGLE " << topLeft.getPosX() << " " << topLeft.getPosY()
              << " " << width << " " << height << std::endl;
}

//Méthode pour convertir le rectangle en une liste de pixels
std::vector<Pixel>Rectangle::toPixels() const {
    // Implémentation de l'algorithme d'Andres/Bresenham
    // (sera détaiillée dans la partie 2)
    std::vector<Pixel> pixels;
    //...code de l'algorithme
    return pixels;
}