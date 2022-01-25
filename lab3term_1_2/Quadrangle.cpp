#include "Quadrangle.h"

Quadrangle::Quadrangle(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4)
{
    A.first=a1;
    A.second=b1;
    B.first=a2;
    B.second=b2;
    C.first=a3;
    C.second=b3;
    D.first=a4;
    D.second=b4;
}

double Quadrangle::getPerimeter()
{
    double perimeter = AB + BC + CD + DA;
    return perimeter;
}

double Quadrangle::getSquare()
{
    std::point O = lineIntersection(A, B, C, D);
    double DO = len(D, O);
    std::cout<<DO<<std::endl;
    double OC = len(O, C);
    std::cout<<OC<<std::endl;
    double cosY = (pow(DO,2) + pow(OC,2) - pow(CD,2)) / (2 * DO * OC);
    std::cout<<cosY<<std::endl;
    double sinY = sqrt(1 - pow(cosY,2));
    std::cout<<sinY;
    double square = 0.5 * AC * BD * sinY;
    return square;
}

double Quadrangle::trapezeSquare() const
{
    double MN = (BC + DA)/2;
    double AF = DA - BC;
    double BF = CD;
    double p = (AB + BF + AF) / 2;
    double BH = (2 * sqrt(p * (p - AB) * (p - BF) * (p - AF))) / AF;
    double area  = MN * BH;
    return area;
}

double Quadrangle::rectangularSquare() const
{
    double square = AB * BC;
    return square;
}

double Quadrangle::rhombusSquare() const
{
    double square = 0.5 * AC * BD;
    return square;
}

double Quadrangle::squareSquare() const
{
    double area = pow(AB, 2);
    return area;
}

bool Quadrangle::isParallelogram() const
{
    if((AB == CD) && (BC == DA))
    {
        return true;
    }
    else
        return false;
}

bool Quadrangle::isRhombus() const
{
    if (isParallelogram() && AB == BC)
    {
        return true;
    }
    else
        return false;
}

bool Quadrangle::isRectangular() const
{
    if(isParallelogram() && AC == BD)
    {
        return true;
    }
    else
        return false;
}

bool Quadrangle::isSquare() const
{
    if(isRectangular() && AB == BC)
    {
        return true;
    }
    else
        return false;
}

bool Quadrangle::isTrapeze()
{
    if(areLinesParallel(A, B, C, D)
       && !areLinesParallel(D, A, B, C))
    {
        return true;
    }
    else
        return false;
}


bool Quadrangle::isEqualTrapeze()
{
    if(isTrapeze() && AB==CD)
    {
        return true;
    }
    else
        return false;
}
void Quadrangle::showFigureType()
{
    if(isParallelogram())
    {
        std::cout<<"This quadrangle is a parallelogram ";
       /* std::cout<<"\narea = "<<getSquare();
        std::cout<<"coordinate of intersection of diagonals - ";
        displayPoint(M);*/
    }
    else if(isRhombus())
    {
        std::cout<<"This quadrangle is a rhombus ";
       /* std::cout<<"\narea = "<<rhombusSquare();
        std::cout<<"coordinate of intersection of diagonals - ";
        displayPoint(M);*/
    }
    else if(isRectangular())
    {
        std::cout<<"This quadrangle is a rectangular ";
       /* std::cout<<"\narea = "<<rectangularSquare();
        std::cout<<"coordinate of intersection of diagonals and the center of circumcircle  - ";
        displayPoint(M);*/
    }
    else if(isSquare())
    {
        std::cout<<"This quadrangle is a square ";
        /*std::cout<<"\narea = "<<squareSquare();
        std::cout<<"coordinate of intersection of diagonals and the center of circumcircle - ";
        displayPoint(M);*/
    }
    else if(isTrapeze())
    {
        if(isEqualTrapeze())
        {
            std::cout<<"This quadrangle is an equal trapeze ";
        }
        else
            std::cout<<"This quadrangle is a trapeze ";

        /*std::cout<<"\narea = "<<trapezeSquare();
        std::cout<<"coordinate of intersection of diagonals - ";
        displayPoint(M);*/
    }
    else
    {
        std::cout << "This is a simple quadrangle";
        /*std::cout << "\narea = " << squareSquare();
        std::cout<<"coordinate of intersection of diagonals - ";
        displayPoint(M);*/
    }
    /*std::cout << "\nperimeter = " << getPerimeter();*/

}
