cmake_minimum_required(VERSION 3.10)
project(Projet_pixel_tracer_CPlus)

# Standard C++17 requis pour les smart pointers
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Indiquer à CMake où chercher les fichiers .h
include_directories(include)

# Lister uniquement les fichiers .cpp nécessaires à la compilation
add_executable(pixel_tracer
    src/main.cpp
    src/Point.cpp
    src/Shape.cpp
    src/Line.cpp
    src/Circle.cpp
    src/Pixel.cpp
    src/Area.cpp
    src/Polygon.cpp
)