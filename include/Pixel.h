//Déclaration du fichier Pixel.h
#ifndef PROJET_PIXEL_TRACER_CPLUS_PIXEL_H
#define PROJET_PIXEL_TRACER_CPLUS_PIXEL_H
class Pixel {
private:
    int x;
    int y;
public:
    // Constructeurs
    Pixel();
    Pixel(int px, int py);
    Pixel(const Pixel& other);

    // Destructeur
    ~Pixel();

    // Getters
    int getX() const { return x; }
    int getY() const { return y; }

    // Setters
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }

    // Operateurs
    Pixel& operator=(const Pixel& other);
    bool operator==(const Pixel& other) const;
};
#endif //PROJET_PIXEL_TRACER_CPLUS_PIXEL_H
