#include "Figure.h"
#include <iostream>
#include "functions.h"

#ifndef LAB3TERM_1_2_QUADRANGLE_H
#define LAB3TERM_1_2_QUADRANGLE_H


class Quadrangle: public Figure {
private:
    std::point A;
    std::point B;
    std::point C;
    std::point D;
    double AB = len(A, B);
    double BC = len(B, C);
    double CD = len(C, D);
    double DA = len(D, A);
    double AC = len(A, C);
    double BD = len(B, D);
public:
    Quadrangle(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4);
    double getPerimeter();
    std::point M = lineIntersection(A, B, C, D);
    double getSquare();
    double trapezeSquare() const;
    double rectangularSquare() const;
    double rhombusSquare() const;
    double squareSquare() const;
    bool isParallelogram() const;
    bool isRhombus() const;
    bool isRectangular() const;
    bool isSquare() const;
    bool isTrapeze();
    bool isEqualTrapeze();
    void showFigureType();


};


#endif //LAB3TERM_1_2_QUADRANGLE_H
