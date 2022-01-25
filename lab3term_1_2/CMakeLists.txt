cmake_minimum_required(VERSION 3.17)
project(lab3term_1_2)

set(CMAKE_CXX_STANDARD 14)

set(Headers Polygon.h Triangular.h Quadrangle.h functions.h)


#[[
add_executable(lab3term_1_2 main.cpp cmake-build-debug/Triangular.cpp cmake-build-debug/Triangular.h cmake-build-debug/functions.cpp cmake-build-debug/functions.h cmake-build-debug/Figure.cpp cmake-build-debug/Figure.h Quadrangle.cpp cmake-build-debug/Quadrangle.cpp cmake-build-debug/Quadrangle.h cmake-build-debug/Polygon.cpp cmake-build-debug/Polygon.h)]]

add_executable(TextManipulation ${PROJECT_SOURCE_DIR}/ main.cpp Polygon.cpp Triangular.cpp Quadrangle.cpp functions.cpp)