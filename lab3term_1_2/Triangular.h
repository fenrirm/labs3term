#pragma once
#include <iostream>
#ifndef LAB3TERM_1_2_TRIANGULAR_H
#define LAB3TERM_1_2_TRIANGULAR_H
#include "functions.h"
#include "Figure.h"

class Triangular: public Figure{
private:
    std::point A{};
    std::point B{};
    std::point C{};
public:
    Triangular(double a1, double b1, double a2, double b2, double a3, double b3);
    double getSquare() override;
    double getPerimeter() override;
    bool isRight() const;
    bool isIsosceles() const;
    bool isEquilateral() const;
    std::point median() const;
    std::point bisector() const;
    std::point centerOfCircle() const;
    void showFigureType() override;

};




#endif //LAB3TERM_1_2_TRIANGULAR_H
