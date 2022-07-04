// Lab_7.final.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <windows.h>
#include <consoleapi2.h>


struct Roots 
{
	double x1 = 25, x2 = 15;
};

Roots Myroot(double a, double b, double c)
{
	Roots myroots;
	double D = b * b - 4 * a * c;
	if (D > 0) {
		myroots.x1 = ((-b) + sqrt(D)) / (2 * a);
		myroots.x2 = ((-b) - sqrt(D)) / (2 * a);
	}
	if (D == 0) {
		myroots.x1 = (-b) / (2 * a);
		myroots.x2 = myroots.x1;
	}
	return myroots;
}

void TestMyrootStruct() 
{
	Roots r1 = Myroot(3, 7, 1);
	std::cout << "x1 = " << r1.x1 << " x2 = " << r1.x2 << std::endl;
	Roots r2 = Myroot(5, 1, 7);
	std::cout << "x1 = " << r2.x1 << " x2 = " << r2.x2 << std::endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	TestMyrootStruct();
	return 0;
}