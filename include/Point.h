// Déclaration du fichier Point.h
# ifndef POINT_H
# define POINT_H
# include <iostream>
#include <vector>
#include "Shape.h"
#include "Pixel.h"

class Point : public Shape{
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

    // Opérateurs
    Point& operator=(const Point& other);
    bool operator==(const Point& other) const;

    // Méthodes override
    void print() const override;
    std::vector<Pixel> toPixels() const override;
};

# endif // POINT_H