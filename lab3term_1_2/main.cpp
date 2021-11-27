#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#define point pair<double, double>

void displayPoint(std::point P)
{
    std::cout<<"("<<P.first<<","<<P.second<<")"<<std::endl;
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

/*void main_elem( int k, double mas[] [N + 1], int n, int otv[] )
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
}*/

/*
void resh()
{
    double mas[N][N + 1];
    double x[N]; //Корни системы
    int otv[N]; //Отвечает за порядок корней
    int i, j, k, n;
    //Ввод данных
    system("cls");
    do
    {
        std::cout<<"Enter the number of systems: ";
        std::cin>>n;
        if ( N < n )
            std::cout<<"Too big number. Repeat enter\n";
    }
    while ( N < n );
    std::cout<<"Enter a system:\n";
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n+1; j++ )
            std::cin>>mas[i][j];
    //Вывод введенной системы
    system("cls");
    std::cout<<( "System:\n" );
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < n+1; j++ )
            std::cout<<mas[i][j];
        std::cout<<( "\n" );
    }
    //Сначала все корни по порядку
    for ( i = 0; i < n+1; i++ )
        otv[i] = i;
    //Прямой ход метода Гаусса
    for ( k = 0; k < n; k++ )
    { //На какой позиции должен стоять главный элемент
        main_elem( k, mas, n, otv ); //Установка главного элемента
        if ( fabs( mas[k] [k] ) < 0.0001 )
        {
            std::cout<<"System doesn't have one solution";
            //return ( 0 );
        }
        for ( j = n; j >= k; j-- )
            mas[k] [j] /= mas[k] [k];
        for ( i = k + 1; i < n; i++ )
            for ( j = n; j >= k; j-- )
                mas[i] [j] -= mas[k] [j] * mas[i] [k];
    }
    //Обратный ход
    for ( i = 0; i < n; i++ )
        x[i] = mas[i] [n];
    for ( i = n - 2; i >= 0; i-- )
        for ( j = i + 1; j < n; j++ )
            x[i] -= x[j] * mas[i] [j];
    //Вывод результата
    std::cout<<( "Answer:\n" );
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ )
            if ( i == otv[j] )
            { //Расставляем корни по порядку
                std::cout<<x[j]<<std::endl;
                break;
            }
}
*/



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

     void area() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        double p = (AB+BC+AC)/2;
        double S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
        std::cout<<"S = "<<S;
    }

    void perimeter() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        double P = AB+BC+AC;
        std::cout<<"P = "<<P;
    }

    void isRightTriangle() const
    {
        if ((((B.first - A.first) * (C.first - B.first)
        + (B.second - A.second) * (C.second - B.second)) == 0)||
        (((C.first - B.first) * (A.first - C.first)
        + (C.second - B.second) * (A.second - C.second)) == 0)
        || (((C.first - A.first) * (B.first - A.first)
        + (C.second - A.second) * (B.second - A.second)) == 0))
        {
            std::cout<<"isRightTriangle";
        }
        else
            std::cout<<"isNotRightTriangle";
    }

    void isIsosceles() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        if((AB == BC) || (BC == AC) || (AB == AC))
        {
            std::cout<<"isIsosceles";
        }
        else
            std::cout<<"isNotIsosceles";

    }

    void isEquilateral() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        if(AB == BC == AC)
        {
            std::cout<<"isEquilateral";
        }
        else
            std::cout<<"isNotEquilateral";

    }

    void median() const
    {
        double a0 = (A.first + B.first + C.first) / 3;
        double b0 = (A.second + B.second + C.second) / 3;
        std::cout<<"median - "<<"x = "<<a0<<"y = "<<b0;
    }

    void bisector() const
    {
        double AB = len(A.first, A.second, B.first, B.second);
        double BC = len(B.first, B.second, C.first, C.second);
        double AC = len(C.first, C.second, A.first, A.second);
        double a0 = (AB * A.first + BC * B.first + AC * C.first) / ( AB + BC + AC);
        double b0 = (AB * A.second + BC * B.second + AC * C.second) / (AB + BC + AC);
        std::cout<<"bisector - "<<"x = "<<a0<<"y = "<<b0;
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
        /*double a = len(x1, y1, x2, y2);
        double b = len(x2, y2, x3, y3);
        double c = len(x3, y3, x4, y4);
        double d = len(x4, y4, x1, y1);*/
        double AB = (A.first, A.second, B.first, B.second);
        double BC = (B.first, B.second, C.first, C.second);
        double CD = (C.first, C.second, D.first, D.second);
        double DA = (D.first, D.second, A.first, A.second);
        double perimeter = AB + BC + CD + DA;
        return perimeter;
    }

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
};

int main() {
    //triangular(-2, 4, 6, 7, -1, 3);
    quadrangle a(3, 4, 1, 5, 7, 8, 9, 6);
    std::cout<<"perimeter - "<<a.perimeter()<<"\narea - "<<a.area();






    //******************************************

    /*std::point A;
    std::cin>>A.first>>A.second;
    std::point B;
    std::cin>>B.first>>B.second;
    std::point C;
    std::cin>>C.first>>C.second;
    std::point D;
    std::cin>>D.first>>D.second;*/

    //std::point intersection = lineIntersection(A, B, C, D);
    /*if (intersection.first == FLT_MAX && intersection.second == FLT_MAX)
    {
        std::cout << "The given lines AB and CD are parallel";
    }
    else
    {
        std::cout << "The intersection of given lines AC and BD is: ";
        displayPoint(intersection);
    }*/





    return 0;
}
