#include <iostream>
#include <cmath>
#define N 50

static double len(double x, double y, double a, double b)
{
    double length = sqrt(pow((a-x),2)+pow((b-y),2));
    return length;
}

void main_elem( int k, double mas[] [N + 1], int n, int otv[] )
{
    int i, j, i_max = k, j_max = k;
    double temp;
    //Ищем максимальный по модулю элемент
    for ( i = k; i < n; i++ )
        for ( j = k; j < n; j++ )
            if ( fabs( mas[i_max] [j_max] ) < fabs( mas[i] [j] ) )
            {
                i_max = i;
                j_max = j;
            }
    //Переставляем строки
    for ( j = k; j < n + 1; j++ )
    {
        temp = mas[k] [j];
        mas[k] [j] = mas[i_max] [j];
        mas[i_max] [j] = temp;
    }
    //Переставляем столбцы
    for ( i = 0; i < n; i++ )
    {
        temp = mas[i] [k];
        mas[i] [k] = mas[i] [j_max];
        mas[i] [j_max] = temp;
    }
    //Учитываем изменение порядка корней
    i = otv[k];
    otv[k] = otv[j_max];
    otv[j_max] = i;

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


class quadrangle
{
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
public:
    quadrangle(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4)
    {
        x1 = a1;
        y1 = b1;
        x2 = a2;
        y2 = b2;
        x3 = a3;
        y3 = b3;
        x4 = a4;
        y4 = b4;
    }

    void P() const
    {
        double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x4, y4);
        double d = len(x4, y4, x1, y1);
    }

    void S() const
    {

    }
};

int main() {
    triangular(-2, 4, 6, 7, -1, 3);

    return 0;
}
