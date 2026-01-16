// Déclaration du fichier Point.h
# ifndef POINT_H
# define POINT_H

# include <iostream>
# include <vector>
# include "Shape.h"
#include "Pixel.h"

// Déclaration anticipée
class Pixel;

class Point : public Shape {
private:
    int posX;
    int posY;

public:
    // Constructeurs
    Point();
    Point(int x, int y);
    Point(const Point& other);

    // Destructeur
    ~Point();

    // Getters
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }

    // Setters
    void setPosX(int x) { posX = x; }
    void setPosY(int y) { posY = y; }

    // Méthode override
    void print() const override;

    // Méthode override
    std::vector<Pixel> toPixels() const override;
    

    // Opérateurs
    Point& operator=(const Point& other);
    bool operator==(const Point& other) const;
};

# endif // POINT_H