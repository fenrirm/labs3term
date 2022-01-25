#include "Triangular.h"

Triangular::Triangular(double a1, double b1, double a2, double b2, double a3, double b3)
{
    A.first=a1;
    A.second=b1;
    B.first=a2;
    B.second=b2;
    C.first=a3;
    C.second=b3;
}

double Triangular::getSquare() {
    double AB = len(A, B);
    double BC = len(B, C);
    double AC = len(C, A);
    double p = (AB+BC+AC)/2;
    double S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
    return S;
}

double Triangular::getPerimeter() {
    double AB = len(A, B);
    double BC = len(B, C);
    double AC = len(C, A);
    double P = AB+BC+AC;
    return P;
}

bool Triangular::isRight() const {
    if ((((B.first - A.first) * (C.first - B.first)
          + (B.second - A.second) * (C.second - B.second)) == 0)||
        (((C.first - B.first) * (A.first - C.first)
          + (C.second - B.second) * (A.second - C.second)) == 0)
        || (((C.first - A.first) * (B.first - A.first)
             + (C.second - A.second) * (B.second - A.second)) == 0))
    {
        return true;
    }
    else
        return false;
}

bool Triangular::isIsosceles() const {
    double AB = len(A, B);
    double BC = len(B, C);
    double AC = len(C, A);
    if((AB == BC) || (BC == AC) || (AB == AC))
    {
        return true;
    }
    else
        return false;
}

bool Triangular::isEquilateral() const {
    double AB = len(A, B);
    double BC = len(B, C);
    double AC = len(C, A);
    if(AB == BC == AC)
    {
        return true;
    }
    else
        return false;
}

std::point Triangular::median() const {
    double a0 = (A.first + B.first + C.first) / 3;
    double b0 = (A.second + B.second + C.second) / 3;
    std::point M = std::make_pair(a0, b0);
    return M;
}

std::point Triangular::bisector() const {
    double AB = len(A, B);
    double BC = len(B, C);
    double AC = len(C, A);
    double a0 = (AB * A.first + BC * B.first + AC * C.first) / ( AB + BC + AC);
    double b0 = (AB * A.second + BC * B.second + AC * C.second) / (AB + BC + AC);
    std::point L = std::make_pair(a0, b0);
    return L;
}

std::point Triangular::centerOfCircle() const {
    double x12 = A.first - B.first;
    double x23 = B.first - C.first;
    double x31 = C.first - A.first;
    double y12 = A.second - B.second;
    double y23 = B.second - C.second;
    double y31 = C.second - A.second;
    double z1 = pow(A.first, 2) + pow(A.second, 2);
    double z2 = pow(B.first, 2) + pow(B.second, 2);
    double z3 = pow(C.first, 2) + pow(C.second, 2);
    double zx = y12 * z3 + y23 * z1 + y31 * z2;
    double zy = x12 * z3 + x23 * z1 + x31 * z2;
    double z = x12 * y31 - y12 * x31;
    double a0 = -zx / 2 * z;
    double b0 = zy / 2 * z;
    std::point O = std::make_pair(a0, b0);
    return O;
}

void Triangular::showFigureType() {
    if(isIsosceles())
    {
        std::cout<<"This triangular is isosceles ";
    }
    else if(isEquilateral())
    {
        std::cout<<"This triangular is equilateral ";
    }
    else if(isRight())
    {
        std::cout<<"This triangular is right ";
    }
    else
    {
        std::cout<<"This is a simple triangular";
    }
    /*std::cout<<"perimeter = "<<getPerimeter()<<"\n"
             <<"area = "<<getSquare()<<"\n";*/
   /* std::cout<<"The coordinate of the point of intersection of medians - ";
    displayPoint(median());
    std::cout<<"\nThe coordinate of the point of intersection of bisectors - ";
    displayPoint(bisector());
    std::cout<<"\nThe coordinate of the point of the center of the circle - ";
    displayPoint(centerOfCircle());*/
}