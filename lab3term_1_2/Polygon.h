#include <iostream>
#include "functions.h"
#include "Figure.h"

#ifndef LAB3TERM_1_2_POLYGON_H
#define LAB3TERM_1_2_POLYGON_H


class Polygon: public Figure {
private:
    std::vector<std::point> Vector;
public:
    double getSquare(std::vector<std::point> &v, int n);
    double getPerimeter(std::vector<std::point> &v, int n);
    bool isRight(std::vector<std::point> &v, int n);
    bool isConvex(std::vector<std::point> &v, int n);
    void showFigureType(int n);
    std::vector<std::point> createPolygon(int n, std::vector<std::point> VECTOR);

};


#endif //LAB3TERM_1_2_POLYGON_H
