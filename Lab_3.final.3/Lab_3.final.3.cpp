// Lab_3.final.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

double area1(double side1, double side2, double side3)
{
    double p = (side1 + side2 + side3) / 2;
    double area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    return area;
}

double area2(double side)
{
    double area = (side * side * sqrt(3)) / 4;;
    return area;
}
void triangleTypeSelection() {
    system("chcp 1251");
    string selection;
    cout << "����������� ��������������? (y/n)?\n";
    cin >> selection;

    if (selection == "y")
    {
        double side;
        cout << "������� ����� ������ ������������\n";
        cin >> side;
        cout << "������� ������������ ����� " << area2(side) << endl;
    }
    else if (selection == "n")
    {
        double side1, side2, side3;
        cout << "������� ����� ��� ������ ������������ ����� ������\n";
        cin >> side1 >> side2 >> side3;
        cout << "������� ������������ ����� " <<area1(side1, side2, side3) << endl;
    }
    else
        cout << "������������ ����.\n";
 }

int main()
{
    triangleTypeSelection();
}