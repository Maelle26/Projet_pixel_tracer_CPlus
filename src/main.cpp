#include <iostream>
#include <memory>
#include <vector>

#include "Area.h"
#include "Layer.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "LayerUtils.h"

void displayMenu(){
    std::cout<<
             "\n----------------------------------------------\n"
             "                   PIXEL TRACER\n"
             "----------------------------------------------\n"
             "\n*** Calques ***\n"
             "1) Lister les calques\n"
             "2) Créer un calque\n"
             "3) Sélectionner un calque\n"
             "4) Supprimer un calque\n"
             "5) Rendre un calque visible\n"
             "6) Cacher un calque\n"
             "\n*** Formes ***\n"
             "7) Ajouter un point\n"
             "8) Ajouter une ligne\n"
             "9) Ajouter un cercle\n"
             "10) Ajouter un carré\n"
             "11) Ajouter un rectangle\n"
             "12) Ajouter un polygone\n"
             "\n*** Visualisation ***\n"
             "13) Dessiner\n"
             "14) Afficher\n"
             "15) Supprimer toutes les formes"
             "\n*** Autre ***\n"
             "0) Quitter\n"
             "----------------------------------------------\n"
             "Choix : "<<std::endl;

}
int main() {
    Area area(40,40);
    std::vector<Layer>layers;
    int currLayerIndex = -1;

    int choice;
    do{
        displayMenu();
        std::cin>>choice;

        switch(choice){
            case 1:
                listLayers(layers,currLayerIndex);
                break;

            case 2:{
                std::string name;
                std::cout<<"Nom du nouveau calque"<<std::endl;
                std::cin>>name;
                newLayer(layers,currLayerIndex,name);
                break;
            }

            case 3:{
                int id;
                std::cout << "ID du calque à sélectionner: ";
                std::cin >> id;
                selectLayer(layers, currLayerIndex, id);
                break;
            }

            case 4 :{
                int id;
                std::cout << "ID du calque à supprimer : "<<std::endl;
                std::cin >> id;
                deleteLayer(layers, currLayerIndex, id);
                break;
            }

            case 5 :{
                int id;
                std::cout << "ID du calque à rendre visible : "<<std::endl;
                std::cin >> id;
                setLayerVisible(layers, id);
                break;
            }

            case 6 :{
                int id;
                std::cout << "ID du calque à masquer : "<<std::endl;
                std::cin >> id;
                setLayerHidden(layers, id);
                break;
            }

            case 7: {
                if (currLayerIndex < 0) {
                    std::cerr << "ERREUR: Aucun calque sélectionné\n"<<std::endl;
                    break;
                }
                int x, y;
                std::cout << "x y : "<<std::endl;
                std::cin >> x >> y;
                layers[currLayerIndex].addShape(
                        std::make_shared<Point>(x, y)
                );
                break;
            }

            case 8: {
                if (currLayerIndex < 0) {
                    std::cerr << "ERREUR: Aucun calque sélectionné\n"<<std::endl;
                    break;
                }
                int x1, y1, x2, y2;
                std::cout << "x1 y1 x2 y2 : ";
                std::cin >> x1 >> y1 >> x2 >> y2;
                layers[currLayerIndex].addShape(
                        std::make_shared<Line>(x1, y1, x2, y2)
                );
                break;
            }

            case 9:{
                if (currLayerIndex < 0) {
                    std::cerr << "ERREUR: Aucun calque sélectionné\n"<<std::endl;
                    break;
                }
                int x, y, r;
                std::cout << "Centre (x y) et rayon : ";
                std::cin >> x >> y >> r;

                layers[currLayerIndex].addShape(
                        std::make_shared<Circle>(x, y, r)
                );
                break;
            }

            case 10:{
                if (currLayerIndex < 0) {
                    std::cerr << "ERREUR: Aucun calque sélectionné\n"<<std::endl;
                    break;
                }
                int x, y, l;
                std::cout << "Coin haut-gauche (x y) et longueur : ";
                std::cin >> x >> y >> l;

                layers[currLayerIndex].addShape(
                        std::make_shared<Square>(x, y, l)
                );
                break;
            }

            case 11: {
                if (currLayerIndex < 0) {
                    std::cerr << "ERREUR: Aucun calque sélectionné\n"<<std::endl;
                    break;
                }
                int x, y, w, h;
                std::cout << "Coin haut-gauche (x y), largeur, hauteur : ";
                std::cin >> x >> y >> w >> h;

                layers[currLayerIndex].addShape(
                        std::make_shared<Rectangle>(x, y, w, h)
                );
                break;
            }

            case 12:{
                if (currLayerIndex < 0) {
                    std::cerr << "ERREUR: Aucun calque sélectionné\n"<<std::endl;
                    break;
                }

                int nbPoints;
                std::cout << "Nombre de points : "<<std::endl;
                std::cin >> nbPoints;

                std::vector<int> coords;
                for (int i = 0; i < nbPoints; ++i) {
                    int x, y;
                    std::cout << "Point " << i + 1 << " (x y) : ";
                    std::cin >> x >> y;
                    coords.push_back(x);
                    coords.push_back(y);
                }

                layers[currLayerIndex].addShape(
                        std::make_shared<Polygon>(coords)
                );
                break;
            }

            case 13:{
                area.erase();

                for (const auto& layer : layers) {
                    if (!layer.isVisible())
                        continue;

                    for (const auto& shape : layer.getShapes()) {
                        area.addShape(shape);
                    }
                }

                area.draw();
                std::cout << "Zone dessinée.\n";
                break;
            }

            case 14:
                area.print();
                break;

            case 15:
                if(currLayerIndex<0){
                    std::cerr<<"ERREUR : Aucun calcque sélectionné\n";
                    break;
                }
                layers[currLayerIndex].clear();
                std::cout<<"Suppresions des formes du calques...\n"<<std::endl;
                break;

            case 0:
                std::cout<<"Fermeture du programme...\n"<<std::endl;
                break;

            default:
                std::cerr<<"ERREUR: Choix invalide\n";
        }
    }while(choice!=0);
    return 0;
}