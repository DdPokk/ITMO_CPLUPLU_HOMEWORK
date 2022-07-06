// Lab_10.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <string>
#include <windows.h>
#include "Dot.h"

using namespace std;

class Triangle 
{
public:
    Triangle(Dot* a, Dot* b) : a{ a }, b{ b } 
    {
        c00 = Dot();//����������
        //c = new Dot(0,0);
        ab = a->distanceTo(*b);
        bc = b->distanceTo(c00);
        ac = a->distanceTo(c00);
        if (IsNotTriangle(ab, bc, ac))
            throw Triangle::ExNotTriangle("������� Triangle.");
    }
    Triangle(Dot* a, Dot* b, Dot* c) : a{ a }, b{ b }, c{ c }
    {
        ab = a->distanceTo(*b);
        bc = b->distanceTo(*c);
        ac = a->distanceTo(*c);
        if (IsNotTriangle(ab, bc, ac))
            throw Triangle::ExNotTriangle("������� Triangle.");
    }

    double get_ab() 
    {
        return ab;
    }
    double get_bc() 
    {
        return bc;
    }
    double get_ac() 
    {
        return ac;
    }
    boolean IsNotTriangle(double ab, double bc, double ac)
    {
        if (ac >= ab + bc or ab >= bc + ac or bc >= ab + ac) return true;
        return false;
    }

    double TrianglePerimeter()
    {
        return ab + bc + ac;
    }

    double TriangleArea()
    {
        double p = TrianglePerimeter() / 2;
        return sqrt(p * (p - ab) * (p - bc) * (p - ac));
    }
    class ExNotTriangle 
    {
    public:
        string nameObject;
        ExNotTriangle(string nameObj) :nameObject(nameObj) {}
    };

private:
    Dot* a;
    Dot* b;
    Dot* c;
    Dot c00;
    double ab;
    double bc;
    double ac;
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "������� ���������� ������ ������������\n";
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    Dot a(ax, ay);
    Dot b(bx, by);
    Dot c(cx, cy);
    try {
        Triangle triangleOrigin(&a, &b);//����������� � �������� � ������ ���������.
        cout << "�� = " << triangleOrigin.get_ab() << " �C = " << triangleOrigin.get_bc() << " AC = " << triangleOrigin.get_ac() << endl;
        cout << "�������� ������������ " << triangleOrigin.TrianglePerimeter() << endl;
        cout << "������� ������������ " << triangleOrigin.TriangleArea() << endl;

        Triangle triangle(&a, &b, &c);
        cout << "�� = " << triangle.get_ab() << " �C = " << triangle.get_bc() << " AC = " << triangle.get_ac() << endl;
        cout << "�������� ������������ " << triangle.TrianglePerimeter() << endl;
        cout << "������� ������������ " << triangle.TriangleArea() << endl;
    }
    catch (Triangle::ExNotTriangle& ex)
    {
        cout << "\n������ " << ex.nameObject;
    }
}
