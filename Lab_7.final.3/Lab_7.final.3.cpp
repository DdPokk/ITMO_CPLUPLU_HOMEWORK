// Lab_7.final.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <cmath>
#include <tuple>


using Tuple = std::tuple <double, double, int>;
Tuple Myroot(double a, double b, double c)
{
	double x1 = 0, x2 = 0;
	int flag = -1;
	double D = b * b - 4 * a * c;
	if (D > 0) 
	{
		x1 = ((-b) + sqrt(D)) / (2 * a);
		x2 = ((-b) - sqrt(D)) / (2 * a);
		flag = 1;
	}
	if (D == 0) 
	{
		x1 = (-b) / (2 * a);
		x2 = x1;
		flag = 0;
	}
	return std::make_tuple(x1, x2, flag);
}

void TestMyrootTuple()
{
	Tuple r1 = Myroot(3, 7, 1);
	std::cout << "x1 = " << std::get<0>(r1) << " x2 = " << std::get<1>(r1) << " Наличие корней: " << std::get<2>(r1) << std::endl;
	Tuple r2 = Myroot(5, 1, 7);
	std::cout << "x1 = " << std::get<0>(r2) << " x2 = " << std::get<1>(r2) << " Наличие корней: " << std::get<2>(r2) << std::endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	TestMyrootTuple();
	return 0;
}

