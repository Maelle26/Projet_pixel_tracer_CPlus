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
    std::vector<Pixel> pixels;
    int x = 0;
    int y = radius;
    int d = radius - 1;
    int cx = center.getPosX();
    int cy = center.getPosY();
    while (y >= x) {
        // 8 octants
        pixels.push_back(Pixel(cx + x, cy + y));
        pixels.push_back(Pixel(cx + y, cy + x));
        pixels.push_back(Pixel(cx - x, cy + y));
        pixels.push_back(Pixel(cx - y, cy + x));
        pixels.push_back(Pixel(cx + x, cy - y));
        pixels.push_back(Pixel(cx + y, cy - x));
        pixels.push_back(Pixel(cx - x, cy - y));
        pixels.push_back(Pixel(cx - y, cy - x));
        if (d >= 2 * x) {
            d -= 2 * x + 1;
            x++;
        } else if (d < 2 * (radius - y)) {
            d += 2 * y - 1;
            y--;
        } else {
            d += 2 * (y - x - 1);
        y--;
        x++;
        }
    }
    return pixels;
}