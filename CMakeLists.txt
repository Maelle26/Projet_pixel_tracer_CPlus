cmake_minimum_required(VERSION 3.10)
project(Projet_pixel_tracer_CPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(pixel_tracer
        src/main.cpp
        src/Point.cpp
        src/Shape.cpp
        src/Line.cpp
        src/Pixel.cpp
        src/Circle.cpp
        src/Square.cpp
        src/Rectangle.cpp
        src/Polygon.cpp
        src/Area.cpp
        include/Command.h
        src/Command.cpp
        include/Layer.h
        src/Layer.cpp
        include/LayerUtils.h
)