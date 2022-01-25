#include "Polygon.h"

double Polygon::getSquare(std::vector<std::pair<double, double>> &v, int n)
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

double Polygon::getPerimeter(std::vector<std::pair<double, double>> &v, int n)
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

bool Polygon::isRight(std::vector<std::pair<double, double>> &v, int n)
{
    double a,b;
    int x = 0;
    int i = 0;
    double P = getPerimeter(v, n);
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

bool Polygon::isConvex(std::vector<std::point> &v, int n)
{
    double zCrossProduct = 0;
    for (int i = 1; i<n+1; i++)
    {
        double dx1 = v[i].first - v[i-1].first;
        double dy1 = v[i].second - v[i-1].second;
        double dx2 = v[i+1].first - v[i].first;
        double dy2 = v[i+1].second - v[i].second;
        zCrossProduct += (dx1 * dy2 - dy1 * dx2);
        std::cout<<zCrossProduct<<"\n";
    }
    std::cout<<zCrossProduct<<"\n";

    if ((zCrossProduct > 0) || (zCrossProduct < 0))
    {
        return true;
    }
    else
        return false;
}

void Polygon::showFigureType(int n)
{
    std::vector<std::point> VECTOR;
    //VECTOR=createPolygon(n);

    if(isConvex(VECTOR, n))
    {
        std::cout<<"This polygon is convex \n";
    }
    else
    {
        std::cout<<"This polygon isn't non convex \n";
    }
    std::cout<<"perimeter - "<<getPerimeter(VECTOR, n);
    std::cout<<"\narea - "<<getSquare(VECTOR, n);
}

std::vector<std::point>  Polygon::createPolygon(int n, std::vector<std::point> VECTOR)
{
    /*Polygon a;
    a.Vector.resize(n);
    std::cout<<a.Vector.size();*/
    VECTOR.resize(n);
    std::cout<<VECTOR.size();
    for (int i=0; i<n; i++)
    {
        double x, y;
        std::cin>>x>>y;
        std::point A;
        A.first=x;
        A.second=y;
        //a.Vector[i]=A;
        VECTOR[i]=A;
    }

    /*for(int i=0; i<n; i++)
    {
        displayPoint(a.Vector[i]);
    }*/
    //return a.Vector;
    return VECTOR;
}

