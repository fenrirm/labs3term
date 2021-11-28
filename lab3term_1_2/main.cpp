#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#define point pair<double, double>

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

static double len(double x, double y, double a, double b)
{
    double length = sqrt(pow((a-x),2)+pow((b-y),2));
    return length;
}


class triangular

{

private:
   /* double x1, y1, x2, y2, x3, y3;*/
   std::point A;
   std::point B;
   std::point C;
public:

    triangular(double a1, double b1, double a2, double b2, double a3, double b3)
    {
        A.first=a1;
        A.second=b1;
        B.first=a2;
        B.second=b2;
        C.first=a3;
        C.second=b3;
    }

    double area() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        double p = (AB+BC+AC)/2;
        double S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
        return S;
    }

    double perimeter() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        double P = AB+BC+AC;
        return P;
    }

    bool isRight() const
    {
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

    bool isIsosceles() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        if((AB == BC) || (BC == AC) || (AB == AC))
        {
            return true;
        }
        else
            return false;

    }

    bool isEquilateral() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        if(AB == BC == AC)
        {
            return true;
        }
        else
            return false;

    }

    std::point median() const
    {
        double a0 = (A.first + B.first + C.first) / 3;
        double b0 = (A.second + B.second + C.second) / 3;
        std::point M = std::make_pair(a0, b0);
        return M;
    }

    std::point bisector() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        double a0 = (AB * A.first + BC * B.first + AC * C.first) / ( AB + BC + AC);
        double b0 = (AB * A.second + BC * B.second + AC * C.second) / (AB + BC + AC);
        std::point L = std::make_pair(a0, b0);
        return L;
    }

    std::point centerOfCircle() const
    {
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


    void checkTriangular() const
    {
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
        std::cout<<"perimeter = "<<perimeter()<<"\n"
        <<"area = "<<area()<<"\n";
        std::cout<<"The coordinate of the point of intersection of medians - ";
        displayPoint(median());
        std::cout<<"\nThe coordinate of the point of intersection of bisectors - ";
        displayPoint(bisector());
        std::cout<<"\nThe coordinate of the point of the center of the circle - ";
        displayPoint(centerOfCircle());
    }



};
//*************************************************************************************

class quadrangle
{
private:
    std::point A;
    std::point B;
    std::point C;
    std::point D;
public:
    quadrangle(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4)
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

    double perimeter() const
    {
        double AB = (A.first, A.second, B.first, B.second);
        double BC = (B.first, B.second, C.first, C.second);
        double CD = (C.first, C.second, D.first, D.second);
        double DA = (D.first, D.second, A.first, A.second);
        double perimeter = AB + BC + CD + DA;
        return perimeter;
    }

    std::point M = lineIntersection(A, B, C, D);

    double area() const
    {
        std::point O = lineIntersection(A, B, C, D);
        double DO = len(D.first, D.second, O.first, O.second);
        double OC = len(O.first, O.second, C.first, C.second);
        double CD = len(C.first, C.second, D.first, D.second);
        double AC = len(A.first, A.second, C.first, C.second);
        double BD = len(B.first, B.second, D.first, D.second);
        double cosY = (pow(DO,2) + pow(OC,2) - pow(CD,2)) / (2 * DO * OC);
        double sinY = sqrt(1 - pow(cosY,2));
        double area = 0.5 * AC * BD * sinY;
        return area;
    }

    double areaTrapeze() const
    {
        double BC = len(B.first, B.second, C.first, C.second);
        double AD = len(A.first, A.second, D.first, D.second);
        double AB = len(A.first, A.second, B.first, B.second);
        double CD = len(C.first, C.second, D.first, D.second);
        double MN = (BC + AD)/2;
        double AF = AD - BC;
        double BF = CD;
        double p = (AB + BF + AF) / 2;
        double BH = (2 * sqrt(p * (p - AB) * (p - BF) * (p - AF))) / AF;
        double area  = MN * BH;
        return area;
    }

    double areaForRectangular() const
    {
        double BC = len(B.first, B.second, C.first, C.second);
        double AB = len(A.first, A.second, B.first, B.second);
        double area = AB * BC;
        return area;
    }

    double areaForRhombus() const
    {
        double AC = len(A.first, A.second, C.first, C.second);
        double BD = len(B.first, B.second, D.first, D.second);
        double area = 0.5 * AC * BD;
        return area;
    }

    double areaForSquare() const
    {
        double AB = (A.first, A.second, B.first, B.second);
        double area = pow(AB, 2);
        return area;
    }

    bool isParallelogram() const
    {
        double BC = len(B.first, B.second, C.first, C.second);
        double AD = len(A.first, A.second, D.first, D.second);
        double AB = len(A.first, A.second, B.first, B.second);
        double CD = len(C.first, C.second, D.first, D.second);
        if((AB == CD) && (BC == AD))
        {
            return true;
        }
        else
            return false;
    }

    bool isRhombus() const
    {
        double BC = len(B.first, B.second, C.first, C.second);
        double AB = len(A.first, A.second, B.first, B.second);
        if (isParallelogram() && AB == BC)
        {
            return true;
        }
        else
            return false;
    }

    bool isRectangular() const
    {
        double AC = len(A.first, A.second, C.first, C.second);
        double BD = len(B.first, B.second, D.first, D.second);
        if(isParallelogram() && AC == BD)
        {
            return true;
        }
        else
            return false;
    }

    bool isSquare() const
    {
        double BC = len(B.first, B.second, C.first, C.second);
        double AB = len(A.first, A.second, B.first, B.second);
        if(isRectangular() && AB == BC)
        {
            return true;
        }
        else
            return false;
    }

    bool isTrapeze() const
    {
        if(areLinesParallel(A, B, C, D)
        && !areLinesParallel(D, A, B, C))
        {
            return true;
        }
        else
            return false;
    }

    bool isEqualTrapeze() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double CD = len(C.first, C.second, D.first, D.second);
        if(isTrapeze() && AB==CD)
        {
            return true;
        }
        else
            return false;
    }




    //*********

    void checkFigure() const
    {
        if(isParallelogram())
        {
            std::cout<<"This quadrangle is a parallelogram ";
            std::cout<<"\nperimeter = "<<perimeter();
            std::cout<<"\narea = "<<area();
            std::cout<<"coordinate of intersection of diagonals - ";
            displayPoint(M);
        }
        else if(isRhombus())
        {
            std::cout<<"This quadrangle is a rhombus ";
            std::cout<<"\nperimeter = "<<perimeter();
            std::cout<<"\narea = "<<areaForRhombus();
            std::cout<<"coordinate of intersection of diagonals - ";
            displayPoint(M);
        }
        else if(isRectangular())
        {
            std::cout<<"This quadrangle is a rectangular ";
            std::cout<<"\nperimeter = "<<perimeter();
            std::cout<<"\narea = "<<areaForRectangular();
            std::cout<<"coordinate of intersection of diagonals and the center of circumcircle  - ";
            displayPoint(M);
        }
        else if(isSquare())
        {
            std::cout<<"This quadrangle is a square ";
            std::cout<<"\nperimeter = "<<perimeter();
            std::cout<<"\narea = "<<areaForSquare();
            std::cout<<"coordinate of intersection of diagonals and the center of circumcircle - ";
            displayPoint(M);
        }
        else if(isTrapeze())
        {
            if(isEqualTrapeze())
            {
                std::cout<<"This quadrangle is an equal trapeze ";
            }
            else
                std::cout<<"This quadrangle is a trapeze ";

            std::cout<<"\nperimeter = "<<perimeter();
            std::cout<<"\narea = "<<areaTrapeze();
            std::cout<<"coordinate of intersection of diagonals - ";
            displayPoint(M);
        }
        else
            {
            std::cout << "This is a simple quadrangle";
            std::cout << "\nperimeter = " << perimeter();
            std::cout << "\narea = " << area();
            std::cout<<"coordinate of intersection of diagonals - ";
            displayPoint(M);
        }
    }
};


//**********************************************************************


int main() {
    quadrangle a(3, 4, 1, 5, 7, 8, 9, 6);
    a.checkFigure();

    //triangular b(1, 4, -6, 3, 7, 9);
    //b.checkTriangular();




    return 0;
}
