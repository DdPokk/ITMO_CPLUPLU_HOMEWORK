// Lab_2.final.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int X, Y, Z;
	std::cout << "����� X: "; std::cin >> X;
	std::cout << "����� Y: "; std::cin >> Y;
	std::cout << "����� Z: "; std::cin >> Z;

	if (X > Y && X > Z) {
		std::cout << X << " ����� ������� �����";
	}
	else if (Y > X && Y > Z)
	{
		std::cout << Y << " ����� ������� �����";
	}
	else if (Z > X && Z > Y)
	{
		std::cout << Z << " ����� ������� �����";
	}

	else std::cout << "����������� ����� �� ��������";
}
