// Lab_2.2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <math.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	double x, x1, x2, y;
	std::cout << "x1 = "; std::cin >> x1;
	std::cout << "x2 = "; std::cin >> x2;
	std::cout << "\tx\tsin(x)\n";

	x = x1;

	do {
		y = sin(x);
		std::cout << "\t" << x << "\t" << y << std::endl;
		x = x + 0.01;
	} while (x <= x2);
	return 0;
}
