cmake_minimum_required(VERSION 3.10)
project(Projet_pixel_tracer_CPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(pixel_tracer
        src/main.cpp
        src/Point.cpp
        src/Shape.cpp
        include/Line.h
        include/Line.h
        src/Line.cpp
        src/Line.cpp
        include/Pixel.h
        src/Pixel.cpp
        src/Pixel.cpp
        src/Circle.cpp
        include/Circle.h
        include/Square.h
        include/Square.h
)