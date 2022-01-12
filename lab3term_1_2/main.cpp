#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#define point pair<double, double>
#include <vector>

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

static double len( std::point K, std::point H)
{
    double length = sqrt(pow((H.first-K.first),2)+pow((H.second-K.second),2));
    return length;
}

class Figure // abstract class
{
public:
    virtual double getSquare() = 0;
    virtual double getPerimeter() = 0;
    virtual double showFigureType() = 0;
};

class triangular: Figure
{
private:
   std::point A;
   std::point B;
   std::point C;
public:
    triangular(double a1, double b1, double a2, double b2, double a3, double b3)// constructor
    {
        A.first=a1;
        A.second=b1;
        B.first=a2;
        B.second=b2;
        C.first=a3;
        C.second=b3;
    }

    double getSquare() const
    {
        double AB = len(A, B);
        double BC = len(B, C);
        double AC = len(C, A);
        double p = (AB+BC+AC)/2;
        double S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
        return S;
    }

    double getPerimeter() const
    {
        double AB = len(A, B);
        double BC = len(B, C);
        double AC = len(C, A);
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

    bool isEquilateral() const
    {
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

    std::point median() const
    {
        double a0 = (A.first + B.first + C.first) / 3;
        double b0 = (A.second + B.second + C.second) / 3;
        std::point M = std::make_pair(a0, b0);
        return M;
    }

    std::point bisector() const
    {
        double AB = len(A, B);
        double BC = len(B, C);
        double AC = len(C, A);
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


    void showFigureType() const
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
        std::cout<<"perimeter = "<<getPerimeter()<<"\n"
        <<"area = "<<getSquare()<<"\n";
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
    double AB = len(A, B);
    double BC = len(B, C);
    double CD = len(C, D);
    double DA = len(D, A);
    double AC = len(A, C);
    double BD = len(B, D);
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
        double perimeter = AB + BC + CD + DA;
        return perimeter;
    }

    std::point M = lineIntersection(A, B, C, D);

    double area() const
    {
        std::point O = lineIntersection(A, B, C, D);
        double DO = len(D, O);
        double OC = len(O, C);
        double cosY = (pow(DO,2) + pow(OC,2) - pow(CD,2)) / (2 * DO * OC);
        double sinY = sqrt(1 - pow(cosY,2));
        double area = 0.5 * AC * BD * sinY;
        return area;
    }

    double areaTrapeze() const
    {
        double MN = (BC + DA)/2;
        double AF = DA - BC;
        double BF = CD;
        double p = (AB + BF + AF) / 2;
        double BH = (2 * sqrt(p * (p - AB) * (p - BF) * (p - AF))) / AF;
        double area  = MN * BH;
        return area;
    }

    double areaForRectangular() const
    {
        double area = AB * BC;
        return area;
    }

    double areaForRhombus() const
    {
        double area = 0.5 * AC * BD;
        return area;
    }

    double areaForSquare() const
    {
        double area = pow(AB, 2);
        return area;
    }

    bool isParallelogram() const
    {
        if((AB == CD) && (BC == DA))
        {
            return true;
        }
        else
            return false;
    }

    bool isRhombus() const
    {
        if (isParallelogram() && AB == BC)
        {
            return true;
        }
        else
            return false;
    }

    bool isRectangular() const
    {
        if(isParallelogram() && AC == BD)
        {
            return true;
        }
        else
            return false;
    }

    bool isSquare() const
    {
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
        if(isTrapeze() && AB==CD)
        {
            return true;
        }
        else
            return false;
    }

    void checkFigure() const
    {
        if(isParallelogram())
        {
            std::cout<<"This quadrangle is a parallelogram ";
            std::cout<<"\narea = "<<area();
            std::cout<<"coordinate of intersection of diagonals - ";
            displayPoint(M);
        }
        else if(isRhombus())
        {
            std::cout<<"This quadrangle is a rhombus ";
            std::cout<<"\narea = "<<areaForRhombus();
            std::cout<<"coordinate of intersection of diagonals - ";
            displayPoint(M);
        }
        else if(isRectangular())
        {
            std::cout<<"This quadrangle is a rectangular ";
            std::cout<<"\narea = "<<areaForRectangular();
            std::cout<<"coordinate of intersection of diagonals and the center of circumcircle  - ";
            displayPoint(M);
        }
        else if(isSquare())
        {
            std::cout<<"This quadrangle is a square ";
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

            std::cout<<"\narea = "<<areaTrapeze();
            std::cout<<"coordinate of intersection of diagonals - ";
            displayPoint(M);
        }
        else
            {
            std::cout << "This is a simple quadrangle";
            std::cout << "\narea = " << area();
            std::cout<<"coordinate of intersection of diagonals - ";
            displayPoint(M);
        }
        std::cout << "\nperimeter = " << perimeter();

    }
};

class polygon
{
public:
    std::vector<std::point> Vector;
};

std::vector<std::point> createPolygon(int n)
{
    polygon a;
    a.Vector.resize(n);
    std::cout<<a.Vector.size();
    for (int i=0; i<n; i++)
    {
        double x, y;
        std::cin>>x>>y;
        std::point A;
        A.first=x;
        A.second=y;
        a.Vector[i]=A;
    }

    /*for(int i=0; i<n; i++)
    {
        displayPoint(a.Vector[i]);
    }*/
    return a.Vector;
}




double perimeter (std::vector<std::point> &v, int n)
{
    double P = 0;
    int i = 0;
    while(n!=0)
    {
        P += len(v[i], v[i+1]);
        i++;
        n--;
    }
    return P;
}



/*double areaForRightPolygon(std::vector<std::point> &v, int n)
{
    std::point M;
    M.first = (v[0].first + v[0].first) / 2;
    M.second = (v[1].second + v[1].second) / 2;
    std::point O;
    O = lineIntersection(v[0], v[4], v[2], v[4]);

}*/

double area (std::vector<std::point> &v, int n)
{
    double S = 0.0;
    int j = n - 1;
    for(int i = 0; i < n; i++)
    {
        S += (v[j].first + v[i].first) * (v[j].second - v[i].second);
        j = i;
    }
    return abs(S / 2.0);
}


bool isRightPolygon(std::vector<std::point> &v, int n)
{
    double a,b;
    int x = 0;
    int i = 0;
    double P = perimeter(v, n);
    double Len = P/n;
    while(n!=0)
    {
        a = len(v[i], v[i+1]);
        i++;
        n--;
        if (a==Len)
        {
            x++;
        }
    }
    if (x==n)
        return true;
    else
        return false;

}

bool isConvex(std::vector<std::point> &v, int n)
{
    double zcrossproduct = 0;
    for (int i = 1; i<n+1; i++)
    {
        double dx1 = v[i].first - v[i-1].first;
        double dy1 = v[i].second - v[i-1].second;
        double dx2 = v[i+1].first - v[i].first;
        double dy2 = v[i+1].second - v[i].second;
        zcrossproduct += (dx1 * dy2 - dy1 * dx2);
        std::cout<<zcrossproduct<<"\n";
    }
    std::cout<<zcrossproduct<<"\n";

    if ((zcrossproduct > 0) || (zcrossproduct < 0))
    {
        return true;
    }
    else
        return false;
}

void polygon(int n)
{
    std::vector<std::point> VECTOR;
    VECTOR=createPolygon(n);
    if(isConvex(VECTOR, n))
    {
        std::cout<<"This polygon is convex \n";
    }
    else
    {
        std::cout<<"This polygon isn't non convex \n";
    }
    std::cout<<"perimeter - "<<perimeter(VECTOR, n);
    std::cout<<"\narea - "<<area(VECTOR, n);
}

//*************************************************************************************

int main() {
    //quadrangle a(3, 4, 1, 5, 7, 8, 9, 6);
    //a.checkFigure();

    /*int n;
    std::cin>>n;
    polygon a;
    a.Vector.resize(n);
    std::cout<<a.Vector.size();
    for (int i=0; i<n; i++)
    {
        double x, y;
        std::cin>>x>>y;
        std::point A;
        A.first=x;
        A.second=y;
        a.Vector[i]=A;
    }

    for(int i=0; i<n; i++)
    {
        displayPoint(a.Vector[i]);
    }*/
    int  n;
    std::cin>>n;
    /*std::vector<std::point> VECTOR;
    VECTOR=createPolygon(n);*/
    //std::cout<<perimeter(VECTOR, n)<<"\n"<<area(VECTOR, n);
    polygon(n);



    //triangular b(1, 4, -6, 3, 7, 9);
    //b.checkTriangular();




    return 0;
}