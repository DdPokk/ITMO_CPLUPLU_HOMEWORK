// Lab_2.1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int x, y;
	std::cout << "������� �: ";
	std::cin >> x;

	std::cout << "������� Y: ";
	std::cin >> y;

	if (x * x + y * y < 9 && y > 0) std::cout << "����� ������\n";
	else if (x * x + y * y > 9 || y < 0) std::cout << "����� �������\n";
	else std::cout << "����� �� �������\n\n\n";
}