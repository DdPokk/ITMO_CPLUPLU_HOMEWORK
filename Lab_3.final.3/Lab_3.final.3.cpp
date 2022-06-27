// Lab_3.final.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

double triangleArea(double side1, double side2, double side3)
{
    double p = (side1 + side2 + side3) / 2;
    double area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    return area;
}

double triangleArea(double side)
{
    double area = (side * side * sqrt(3)) / 4;;
    return area;
}
void triangleTypeSelection() {
    system("chcp 1251");
    string selection;
    cout << "явл€етс€ ли треугольник равносторонним (да/нет)?\n";
    cin >> selection;

    if (selection == "да")
    {
        double side;
        cout << "¬ведите длину стороны треугольника\n";
        cin >> side;
        cout << "ѕлощадь треугольника равна " << triangleArea(side) << endl;
    }
    else if (selection == "нет")
    {
        double side1, side2, side3;
        cout << "¬ведите длины трЄх сторон треугольника через пробел\n";
        cin >> side1 >> side2 >> side3;
        cout << "ѕлощадь треугольника равна " << triangleArea(side1, side2, side3) << endl;
    }
    else
        cout << "Ќекорректный ввод.\n";
 }

int main()
{
    triangleTypeSelection();
}