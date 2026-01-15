// Ficher Line.cpp
# include "Line.h"
# include "Pixel.h"
# include <cmath>

//Constructeur
Line::Line(const Point& point1, const Point& point2)
: Shape(), p1(point1), p2(point2) {}

//Constructeur paramétré avec coordonnées
Line::Line(int x1, int y1, int x2, int y2)
: Shape(), p1(x1, y1), p2(x2, y2) {}

//Méthode pour afficher les informations de la ligne
void Line::print() const {
    std::cout << "LINE " << p1.getPosX() << " " << p1.getPosY()
    << " " << p2.getPosX() << " " << p2.getPosY()
    << std::endl;
}

//Méthode pour convertir la ligne en une liste de pixels
std::vector<Pixel> Line::toPixels() const {
    // Implémentation de l'algorithme de Bresenham
    // (sera détaillée dans la partie 2)
    std::vector<Pixel> pixels;
    // ... code de l'algorithme ...
    return pixels;
}