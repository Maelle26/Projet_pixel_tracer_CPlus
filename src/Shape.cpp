// Fichier Shape.cpp
# include "Shape.h"

// Initialisation du membre statique
int Shape::nextId = 1;

//Constructeur
Shape::Shape() : id(nextId++) {
    // L'ID est automatiquement incrémenté
}