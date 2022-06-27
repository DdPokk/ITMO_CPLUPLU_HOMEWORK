// Lab_3.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    system("chcp 1251");
    std::cout << "Square:" << area() << std::endl;
}

double CalcTriangle(double side1, double side2, double side3)
{
    double p = (side1 + side2 + side3) / 2;
    double area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    return area;
}

double CalcLine(double xStart, double yStart, double xEnd, double yEnd) {
    double distX = xStart - xEnd;
    double distY = yStart - yEnd;
    double distance = sqrt(distX * distX + distY * distY);
    return distance;
}

double area() {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    cout << "\nКоординаты:\n";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;

    double AB = CalcLine(x1, y1, x2, y2);
    double AC = CalcLine(x1, y1, x3, y3);
    double AD = CalcLine(x1, y1, x4, y4);
    double AE = CalcLine(x1, y1, x5, y5);
    double BC = CalcLine(x2, y2, x3, y3);
    double CD = CalcLine(x3, y3, x4, y4);
    double DE = CalcLine(x4, y4, x5, y5);
    double ABC = CalcTriangle(AB, BC, AC);
    double ACD = CalcTriangle(AC, CD, AD);
    double ADE = CalcTriangle(AD, DE, AE);
    double totalArea = ABC + ACD + ADE;
    return totalArea;
}
