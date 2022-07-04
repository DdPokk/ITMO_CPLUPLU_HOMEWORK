// Lab_9.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>


using namespace std;

class Triangle 
{
public:
    Triangle(double a1, double b1, double c1) : a{ a1 }, b{ b1 }, c{ c1 }
    {
        if (c >= a + b or a >= b + c or b >= a + c)
            throw Triangle::ExNotTriangle("объекта Triangle.");
    }

    double TriangleArea() 
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    class ExNotTriangle
    {
    public:
        string nameObject;
        ExNotTriangle(string nameObj) :nameObject(nameObj) {}
    };

private:
    double a;
    double b;
    double c;
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Введите через пробел стороны треугольника\n";
    double a, b, c;
    cin >> a >> b >> c;
    try 
    {
        Triangle triangle(a, b, c);
        cout << "Площадь треугольника " << triangle.TriangleArea() << endl;
    }
    catch (Triangle::ExNotTriangle& ex)
    {
        cout << "\nОшибка инициализации " << ex.nameObject;
    }
}