// Déclaration du fichier Shape.h
# ifndef SHAPE_H
# define SHAPE_H

# include <iostream>
# include <vector>


// Déclaration anticipée
class Pixel;

class Shape {
protected:
    int id;
    static int nextId;

public:
    // Constructeur
    Shape();

    // Destructeur virtuel
    virtual ~Shape() = default;

    // Méthode virtuelle pour afficher les informations de la forme
    virtual void print() const = 0;

    // Méthode virtuelles pour appliquer l'algorithme de chaque forme
    virtual std::vector<Pixel> toPixels() const = 0;
    
    // Getter
    int getId() const { return id; }
};

# endif // SHAPE_H