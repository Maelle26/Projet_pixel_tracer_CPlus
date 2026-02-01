#include "Layer.h"

#include <iostream>
#include <algorithm>

// Initialisation du membre statique
int Layer::nextId = 1;

// Constructeurs
Layer::Layer()
        : id(nextId++),
          name("Layer_" + std::to_string(id)),
          visible(true) {}

Layer::Layer(const std::string& layerName)
        : id(nextId++),
          name(layerName),
          visible(true) {}

// Ajouter une forme
void Layer::addShape(std::shared_ptr<Shape> shape) {
    shapes.push_back(shape);
}

// Supprimer une forme par ID
void Layer::removeShape(int shapeId) {
    shapes.erase(
            std::remove_if(
                    shapes.begin(),
                    shapes.end(),
                    [shapeId](const std::shared_ptr<Shape>& s) {
                        return s->getId() == shapeId;
                    }
            ),
            shapes.end()
    );
}

// Supprimer toutes les formes
void Layer::clear() {
    shapes.clear();
}

// Affichage
void Layer::print() const {
    std::cout << "Layer " << id
              << " (" << name << ") - "
              << (visible ? "Visible" : "Hidden")
              << " - "
              << shapes.size()
              << " forme(s)"
              << std::endl;
}

//Permet de lister les calques existants
void listLayers(const std::vector<Layer>& layers, int currLayerIndex){
    if(layers.empty()){
        std::cout<<"Il n'y a aucun calque pour le moment\n"<<std::endl;
        return;
    }
    for (size_t i = 0; i < layers.size(); ++i) {
        if (static_cast<int>(i) == currLayerIndex)
            std::cout << "> ";
        else
            std::cout << "  ";

        layers[i].print();
    }
}

//Ajouter un calque
void newLayer(std::vector<Layer>& layers, int& currLayerIndex,const std::string& name){
    layers.emplace_back(name);
    currLayerIndex = static_cast<int>(layers.size())-1;

    std::cout<<"Nouveau calque crée : "<<name<<std::endl;
}

//Sélectionner un calque
bool selectLayer(std::vector<Layer>& layers, int& curLayerIndex, int id){
    for(size_t i =0;i<layers.size();i++){
        if(layers[i].getId()==id){
            curLayerIndex = static_cast<int>(i);
            std::cout<<"Calque séléctionné: "<<layers[i].getName()<<std::endl;
            return true;
        }
    }
    std::cerr << "ERREUR: Calque introuvable" << std::endl;
    return false;
}

void deleteLayer(std::vector<Layer>& layers, int& currLayerIndex, int id){
    for(size_t i =0;i<layers.size();i++){
        if(layers[i].getId()==id){
            layers.erase(layers.begin()+i);

            if(currLayerIndex == static_cast<int>(i)){
                currLayerIndex = -1;
            }

            else if (currLayerIndex>static_cast<int>(i)){
                currLayerIndex --;
            }
            std::cout<<"Calque supprimé"<<std::endl;
            return;
        }
    }
    std::cerr<<"ERREUR: Calque introuvable"<<std::endl;
}

//Rendre un calque visible
void setLayerVisible(std::vector<Layer>& layers, int id){
    for(auto& layer: layers){
        if(layer.getId()==id){
            layer.setVisible(true);
            std::cout<<"Calque "<<layer.getName()<<std::endl;
            return;
        }
    }
    std::cerr<<"ERREUR: Calque introuvable"<<std::endl;
}

void setLayerHidden(std::vector<Layer>& layers, int id){
    for(auto& layer: layers){
        if(layer.getId()==id){
            layer.setVisible(false);
            std::cout<<"Calque "<<layer.getName()<<" masqué"<<std::endl;
            return;
        }
    }
    std::cerr<<"ERREUR: Calque introuvable"<<std::endl;
}

