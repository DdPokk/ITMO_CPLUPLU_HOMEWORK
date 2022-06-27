// Lab_4.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

int Myroot(double a, double b, double c, double& x1, double& x2) {
	double D = b * b - 4 * a * c;
	if (D > 0) {
		x1 = ((-b) + sqrt(D)) / (2 * a);
		x2 = ((-b) - sqrt(D)) / (2 * a);
		return 1;
	}
	if (D == 0) {
		x1 = (-b) / (2 * a);
		x2 = x1;
		return 0;
	}
	return -1;
}

int main()
{
	system("chcp 1251");
	double a, b, c, x1 = 0, x2 = 0;
	std::cout << "Введите коэффициенты квадратного уравнения (a, b, c) через пробел:\n";
	std::cin >> a >> b >> c;
	switch (Myroot(a, b, c, x1, x2))
	{
	case(1):
		std::cout << "Уравнение " << a << "*x*x + " << b << "*x + " << c << " = 0 имеет два корня:\n";
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x1 = " << x2 << std::endl;
		break;
	case(0):
		std::cout << "Уравнение " << a << "*x*x + " << b << "*x + " << c << " = 0 имеет один корень:\n";
		std::cout << "x1 = x2 =  " << x1 << std::endl;
		break;
	case(-1):
		std::cout << "Уравнение " << a << "*x*x + " << b << "*x + " << c << " = 0 не имеет корней.\n";
		break;
	default:
		std::cout << "Некорректная работа";
		break;
	}
}