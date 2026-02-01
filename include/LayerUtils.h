#ifndef PROJET_PIXEL_TRACER_CPLUS_LAYERUTILS_H
#define PROJET_PIXEL_TRACER_CPLUS_LAYERUTILS_H

#include <vector>
#include <string>
#include "Layer.h"

//Permet de lister tous les calques existants
void listLayers(const std::vector<Layer>& layers, int currLayerIndex);

//Créer un nouveau calque à partir du nom
void newLayer(std::vector<Layer>& layers, int& currLayerIndex,const std::string& name);

//Sélectionner un calque pa
bool selectLayer(std::vector<Layer>& layers, int& currLayerIndex, int id);

//Supprimer un calque par ID
void deleteLayer(std::vector<Layer>& layers, int& currLayerIndex, int id);

//Rendre un calque visible
void setLayerVisible(std::vector<Layer>& layers, int id);

//Cacher un calque
void setLayerHidden(std::vector<Layer>& layers, int id);
#endif //PROJET_PIXEL_TRACER_CPLUS_LAYERUTILS_H
