// Lab_3.1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;

double CalcTriangleArea(double side1, double side2, double side3)
{
    double p = (side1 + side2 + side3) / 2;
    double area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    return area;
}

double CalcLineLength(double xStart, double yStart, double xEnd, double yEnd) {
    double distX = xStart - xEnd;
    double distY = yStart - yEnd;
    double distance = sqrt(distX * distX + distY * distY);
    return distance;
}

double pentagonArea() {
    system("chcp 1251");
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    cout << "\n¬ведите координаты по-пор€дку, начина€ с любой вершины:\n";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;



    double AB = CalcLineLength(x1, y1, x2, y2);
    double AC = CalcLineLength(x1, y1, x3, y3);
    double AD = CalcLineLength(x1, y1, x4, y4);
    double AE = CalcLineLength(x1, y1, x5, y5);
    double BC = CalcLineLength(x2, y2, x3, y3);
    double CD = CalcLineLength(x3, y3, x4, y4);
    double DE = CalcLineLength(x4, y4, x5, y5);


    double ABC = CalcTriangleArea(AB, BC, AC);
    double ACD = CalcTriangleArea(AC, CD, AD);
    double ADE = CalcTriangleArea(AD, DE, AE);

    double totalArea = ABC + ACD + ADE;
    return totalArea;
}
