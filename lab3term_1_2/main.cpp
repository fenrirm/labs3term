#include <iostream>
#include <cmath>

static double len(double x, double y, double a, double b)
{
    double length = sqrt(pow((a-x),2)+pow((b-y),2));
    return length;
}

class triangular
{
private:
    double x1, y1, x2, y2, x3, y3;
public:
    triangular(double a1, double b1, double a2, double b2, double a3, double b3)
    {
        x1=a1;
        y1=b1;
        x2=a2;
        y2=b2;
        x3=a3;
        y3=b3;
    }

   /*static double len(double x, double y, double a, double b)
    {
        double length = sqrt(pow((a-x),2)+pow((b-y),2));
        return length;
    }*/

    void S() const
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x1, y1);
        double p = (a+b+c)/2;
        double S = sqrt(p*(p-a)*(p-b)*(p-c));
        std::cout<<"S = "<<S;
    }

    void P() const
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x1, y1);
        double P = a+b+c;
        std::cout<<"P = "<<P;
    }


    void isRightTriangle() const
    {
        if ((((x2-x1)*(x3-x2)+(y2-y1)*(y3-y2))==0)||(((x3-x2)*(x1-x3)+(y3-y2)*(y1-y3))==0)||(((x3-x1)*(x2-x1)+(y3-y1)*(y2-y1))==0))
        {
            std::cout<<"isRightTriangle";
        }
        else
            std::cout<<"isNotRightTriangle";


    }

    void isIsosceles() const
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x1, y1);
        if((a==b)||(a==c)||(b==c))
        {
            std::cout<<"isIsosceles";
        }
        else
            std::cout<<"isNotIsosceles";

    }

    void isEquilateral() const
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x1, y1);
        if(a==b==c)
        {
            std::cout<<"isEquilateral";
        }
        else
            std::cout<<"isNotEquilateral";

    }

    void median() const
    {
        double a0 = (x1+x2+x3)/3;
        double b0 = (y1+y2+y3)/3;
        std::cout<<"median - "<<"x = "<<a0<<"y = "<<b0;
    }

    void bisector() const
    {
        double a = len(x2, y2, x3, y3);
        double b = len(x1, y1, x3, y3);
        double c = len(x1, y1, x2, y2);
        double a0 = (a*x1+b*x2+c*x3)/(a+b+c);
        double b0 = (a*y1+b*y2+c*y3)/(a+b+c);
        std::cout<<"bisector - "<<"x = "<<a0<<"y = "<<b0;
    }

};


int main() {
    triangular(-2, 4, 6, 7, -1, 3);

    return 0;
}