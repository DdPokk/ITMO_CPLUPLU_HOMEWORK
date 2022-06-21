// Lab_2.final.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int X, Y, Z;
	std::cout << "Число X: "; std::cin >> X;
	std::cout << "Число Y: "; std::cin >> Y;
	std::cout << "Число Z: "; std::cin >> Z;

	if (X > Y && X > Z) {
		std::cout << X << " самое большое число";
	}
	else if (Y > X && Y > Z)
	{
		std::cout << Y << " самое большое число";
	}
	else if (Z > X && Z > Y)
	{
		std::cout << Z << " самое большое число";
	}

	else std::cout << "Наибольшего числа не выявлено";
}
