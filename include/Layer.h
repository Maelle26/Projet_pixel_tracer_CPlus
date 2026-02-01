#ifndef PROJET_PIXEL_TRACER_CPLUS_LAYER_H
#define PROJET_PIXEL_TRACER_CPLUS_LAYER_H
#include <string>
#include <vector>
#include <memory>

#include "Shape.h"

class Layer {
private:
    int id;
    static int nextId;

    std::string name;
    bool visible;
    std::vector<std::shared_ptr<Shape>> shapes;

public:
    // Constructeurs
    Layer();
    Layer(const std::string& layerName);

    // Destructeur
    ~Layer() = default;

    // Getters
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    bool isVisible() const { return visible; }
    const std::vector<std::shared_ptr<Shape>>& getShapes() const {
        return shapes;
    }

    // Setters
    void setName(const std::string& n) { name = n; }
    void setVisible(bool v) { visible = v; }

    // Méthodes
    void addShape(std::shared_ptr<Shape> shape);
    void removeShape(int shapeId);
    void clear();
    void print() const;
};
#endif //PROJET_PIXEL_TRACER_CPLUS_LAYER_H
