//
// Created by user on 16.01.2022.
//

#include "functions.h"

std::point lineIntersection(std::point A, std::point B, std::point C, std::point D)
{
    //line AC represented as a1x + b1y = c1
    double a1 = C.second - A.second;
    double b1 = A.first - C.first;
    double c1 = a1 * (A.first) + b1 * (A.second);

    //line BD represented as a2x + b2y = c2
    double a2 = D.second - B.second;
    double b2 = B.first - D.first;
    double c2 = a2 * (B.first) + b2 * (B.second);

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0)
    {
        //the lines are parallel. return a pair of FLT_MAX
        return std::make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a2 * c2 - b2 * c1) / determinant;
        return std::make_pair(x, y);
    }
}

void displayPoint(std::point P)
{
    std::cout<<"("<<P.first<<","<<P.second<<")"<<std::endl;
}

bool areLinesParallel(std::point A, std::point B, std::point C, std::point D)
{
    //line BC represented as a1x + b1y = c1
    double a1 = C.second - B.second;
    double b1 = B.first - C.first;
    //double c1 = a1 * (B.first) + b1 * (B.second);

    //line AD represented as a2x + b2y = c2
    double a2 = D.second - A.second;
    double b2 = A.first - D.first;
    //double c2 = a2 * (A.first) + b2 * (A.second);

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0)
    {
        //the lines are parallel
        return true;
    }
    else
        return false;
}

double len( std::point K, std::point H)
{
    double length = sqrt(pow((H.first-K.first),2)+pow((H.second-K.second),2));
    return length;
}