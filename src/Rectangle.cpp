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
std::vector<Pixel> Rectangle::toPixels() const {
    std::vector<Pixel> pixels;
    int x = topLeft.getPosX();
    int y = topLeft.getPosY();

    // 4 côtés du rectangle
    Line top(x, y, x, y + width);
    Line right(x, y + width, x + height, y + width);
    Line bottom(x + height, y + width, x + height, y);
    Line left(x + height, y, x, y);

    auto pixelsTop = top.toPixels();
    auto pixelsRight = right.toPixels();
    auto pixelsBottom = bottom.toPixels();
    auto pixelsLeft = left.toPixels();

    pixels.insert(pixels.end(), pixelsTop.begin(), pixelsTop.end());
    pixels.insert(pixels.end(), pixelsRight.begin(), pixelsRight.end());
    pixels.insert(pixels.end(), pixelsBottom.begin(), pixelsBottom.end());
    pixels.insert(pixels.end(), pixelsLeft.begin(), pixelsLeft.end());

    return pixels;
}
