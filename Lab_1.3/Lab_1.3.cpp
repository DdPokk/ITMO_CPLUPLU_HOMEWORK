// Lab_1.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout.precision(3);

    double a, b, c, p;
    double perimeter;
    double square_size;

    cout << "Введите значение сторон: \n";
    cout << "a = ";
    cin >> a;
    cout << "\nb = ";
    cin >> b;
    cout << "\nc = ";
    cin >> c;
    perimeter = a + b + c;
    p = perimeter / 2;
    cout << "Периметр треугольника равен = " << perimeter << endl;
    square_size = sqrt(p * (p - a) * (p - b) * (p - c));

    cout << "Площадь треугольника равна " << square_size;
 }