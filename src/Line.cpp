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
    std::vector<Pixel> pixels;

    int x1 = p1.getPosX();
    int y1 = p1.getPosY();
    int x2 = p2.getPosX();
    int y2 = p2.getPosY();

    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int delta = dx - dy;

    while (x1 != x2 || y1 != y2) {
        pixels.push_back(Pixel(x1, y1));

        int e = 2 * delta;

        if (e > -dy) {
            delta -= dy;
            x1 += sx;
        }
        if (e < dx) {
            delta += dx;
            y1 += sy;
        }
    }

    // dernier pixel
    pixels.push_back(Pixel(x2, y2));

    return pixels;
}