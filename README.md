# Pixel Tracer — Projet C++

## Auteurs
Maëlle BITSINDOU
Lucy GROS 

## 1. Présentation générale
Pixel Tracer est une application console développée en langage C++ permettant de représenter et de tracer
des formes géométriques élémentaires sur une grille de pixels. L’affichage est réalisé sous forme de rendu ASCII.

## 2. Fonctionnalités principales

### 2.1 Gestion des calques
- Créer des calques indépendants
- Sélectioner un calque 
- Supprimer un calque
- Afficher ou masquer un calque
- Ajouter des formes sur le calque sélectionné 

### 2.2 Formes géométriques supportées
- Point
- Ligne
- Cercle
- Carré
- Rectangle
- Polygone (nombre de points libre)

### 2.3 Interface utilisateur
- Menu général intéractif en ligne de commande
- Sous-menu intéractif en ligne de commande lorsqu'on entre dans un calque

## 3. Architecture logicielle
- `Shape` : classe abstraite représentant une forme géométrique
- `Point`, `Line`, `Circle`, `Square`, `Rectangle`, `Polygon` : implémentations des formes
- `Pixel` : structure représentant un pixel de coordonnées (x, y)
- `Layer` : calque contenant un ensemble de formes
- `LayerUtils` : fonctions de gestion des calques (création, sélection, visibilité)
- `Area` : zone de dessin responsable du rendu final
- `main.cpp` : interface utilisateur et gestion du menu

## 4. Compilation et exécution

### 4.1 Prérequis
- Compilateur C++ compatible avec le standard **C++17**
- Outil de génération de projet **CMake**

### 4.2 Exécution
Après compilation :
./pixel_tracer

## 5. Utilisation du menu et saisie clavier

### 5.1 Règles générales de saisie
- Les choix du menu doivent être des **entiers**
- Les coordonnées et paramètres sont saisis sous forme d'entiers séparés par des espaces
- Certaines actions nécessitent qu'un calque soit sélectionné au préalable

### 5.2 Protocole
Après chaque modifications sur calque il faut sélectionner DESSINER puis AFFICHER. 
