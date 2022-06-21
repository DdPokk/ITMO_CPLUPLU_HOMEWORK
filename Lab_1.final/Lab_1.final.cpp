// Lab_1.final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <cmath>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	double square;
	double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

	std::cout << "¬ведите координаты точки 1:\n";
	std::cout << "X: ";
	std::cin >> x1;
	std::cout << "Y: ";
	std::cin >> y1;

	std::cout << "¬ведите координаты точки 2:\n";
	std::cout << "X: ";
	std::cin >> x2;
	std::cout << "Y: ";
	std::cin >> y2;

	std::cout << "¬ведите координаты точки 3:\n";
	std::cout << "X: ";
	std::cin >> x3;
	std::cout << "Y: ";
	std::cin >> y3;

	std::cout << "¬ведите координаты точки 4:\n";
	std::cout << "X: ";
	std::cin >> x4;
	std::cout << "Y: ";
	std::cin >> y4;

	std::cout << "¬ведите координаты точки 5:\n";
	std::cout << "X: ";
	std::cin >> x5;
	std::cout << "Y: ";
	std::cin >> y5;

	square = (x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x1 * y5) / 2;
	std::cout << "\nѕлощадь многоугольника: " << abs(square);
}