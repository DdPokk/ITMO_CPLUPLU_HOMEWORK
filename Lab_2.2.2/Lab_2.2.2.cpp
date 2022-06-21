// Lab_2.2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <math.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int a, b, temp;

	std::cout << "a = "; std::cin >> a;
	std::cout << "b = "; std::cin >> b;

	while (a != b)
	{
		if (a > b)
			a = a - b; // аналогоично a = a - b
		else
			b = b - a;
	}

	std::cout << "НОД = " << a << std::endl;

}