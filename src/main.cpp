#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "Area.h"
#include "Layer.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "LayerUtils.h"

// SOUS-MENU QUAND ON SELECTIONNE UN CALQUE
void displayShapeMenu(const std::string& layerName) {
    std::cout << "\n==============================================" << std::endl;
    std::cout << "   EDITION DU CALQUE : " << layerName << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << "1) Ajouter un Point" << std::endl;
    std::cout << "2) Ajouter une Ligne" << std::endl;
    std::cout << "3) Ajouter un Cercle" << std::endl;
    std::cout << "4) Ajouter un Carre" << std::endl;
    std::cout << "5) Ajouter un Rectangle" << std::endl;
    std::cout << "6) Ajouter un Polygone" << std::endl;
    std::cout << "7) Vider ce calque (supprimer toutes ses formes)" << std::endl;
    std::cout << "0) Retour au menu principal" << std::endl;
    std::cout << "Choix : ";
}

// Gestion du sous-menu d'édition des formes
void handleShapeEdition(Layer& currentLayer) {
    int choice;
    do {
        displayShapeMenu(currentLayer.getName());
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int x, y;
                std::cout << "x y : "; std::cin >> x >> y;
                currentLayer.addShape(std::make_shared<Point>(x, y));
                break;
            }
            case 2: {
                int x1, y1, x2, y2;
                std::cout << "x1 y1 x2 y2 : "; std::cin >> x1 >> y1 >> x2 >> y2;
                currentLayer.addShape(std::make_shared<Line>(x1, y1, x2, y2));
                break;
            }
            case 3: {
                int x, y, r;
                std::cout << "Centre (x y) et rayon : "; std::cin >> x >> y >> r;
                currentLayer.addShape(std::make_shared<Circle>(x, y, r));
                break;
            }
            case 4: {
                int x, y, l;
                std::cout << "Coin (x y) et longueur : "; std::cin >> x >> y >> l;
                currentLayer.addShape(std::make_shared<Square>(x, y, l));
                break;
            }
            case 5: {
                int x, y, w, h;
                std::cout << "Coin (x y), largeur, hauteur : "; std::cin >> x >> y >> w >> h;
                currentLayer.addShape(std::make_shared<Rectangle>(x, y, w, h));
                break;
            }
            case 6: {
                int nb;
                std::cout << "Nombre de points : "; std::cin >> nb;
                std::vector<int> coords;
                for (int i = 0; i < nb; ++i) {
                    int px, py;
                    std::cout << "Point " << i+1 << " (x y) : "; std::cin >> px >> py;
                    coords.push_back(px); coords.push_back(py);
                }
                currentLayer.addShape(std::make_shared<Polygon>(coords));
                break;
            }
            case 7:
                currentLayer.clear();
                std::cout << "Calque vide." << std::endl;
                break;
            case 0:
                std::cout << "Retour au menu principal..." << std::endl;
                break;
            default:
                std::cout << "Choix invalide." << std::endl;
        }
    } while (choice != 0);
}

// MENU PRINCIPAL   
void displayMainMenu() {
    std::cout << "\n----------------------------------------------\n"
              << "              PIXEL TRACER\n"
              << "----------------------------------------------\n"
              << "1) Lister les calques\n"
              << "2) Creer un calque\n"
              << "3) SELECTIONNER UN CALQUE (et ajouter des formes)\n"
              << "4) Supprimer un calque\n"
              << "5) Rendre un calque visible\n"
              << "6) Cacher un calque\n"
              << "13) DESSINER (Compile tous les calques)\n"
              << "14) AFFICHER le rendu\n"
              << "0) Quitter\n"
              << "----------------------------------------------\n"
              << "Choix : ";
}

// PROGRAMME PRINCIPAL
int main() {
    Area area(40, 40);
    std::vector<Layer> layers;
    int currLayerIndex = -1;
    int choice;

    do {
        displayMainMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                listLayers(layers, currLayerIndex);
                break;

            case 2: {
                std::string name;
                std::cout << "Nom du nouveau calque : ";
                std::cin >> name;
                newLayer(layers, currLayerIndex, name);
                break;
            }

            case 3: {
                int id;
                std::cout << "ID du calque a selectionner : ";
                std::cin >> id;
                // On utilise votre fonction utilitaire pour changer currLayerIndex
                if (selectLayer(layers, currLayerIndex, id)) {
                    handleShapeEdition(layers[currLayerIndex]);
                }
                break;
            }

            case 4: {
                int id;
                std::cout << "ID du calque a supprimer : "; std::cin >> id;
                deleteLayer(layers, currLayerIndex, id);
                break;
            }

            case 5: {
                int id;
                std::cout << "ID du calque a rendre visible : "; std::cin >> id;
                setLayerVisible(layers, id);
                break;
            }

            case 6: {
                int id;
                std::cout << "ID du calque a masquer : "; std::cin >> id;
                setLayerHidden(layers, id);
                break;
            }

            case 13: {
                area.erase();
                bool hasVisible = false;
                for (const auto& layer : layers) {
                    if (layer.isVisible()) {
                        hasVisible = true;
                        for (const auto& shape : layer.getShapes()) {
                            area.addShape(shape);
                        }
                    }
                }
                area.draw();
                std::cout << (hasVisible ? "Zone dessinee avec succes.\n" : "Aucun calque visible a dessiner.\n");
                break;
            }

            case 14:
                area.print();
                break;

            case 0:
                std::cout << "Fermeture du programme..." << std::endl;
                break;

            default:
                std::cout << "Choix invalide." << std::endl;
        }
    } while (choice != 0);

    return 0;
}