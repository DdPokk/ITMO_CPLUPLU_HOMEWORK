// Lab_2.final.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int x, y, round(1), points(0);

	do
	{
		std::cout << "\n�������: " << round;
		std::cout << "\n������� �: ";
		std::cin >> x;

		std::cout << "������� Y: ";
		std::cin >> y;

		if (x * x + y * y <= 1) points += 10;
		else if (x * x + y * y > 1 && x * x + y * y <= 4) points += 5;
		else if (x * x + y * y > 4 && x * x + y * y <= 9) points += 1;
		else points += 0;

		round += 1;
	} while (points <= 50);

	if (points > 40) std::cout << "\n�� ������� " << points << " �����, ��� ������� �������.";
	else if (points <= 40 && points > 25) std::cout << "\n�� ������� " << points << " �����, ��� ������� �������.";
	else std::cout << "\n�� ������� " << points << " �����, ��� ������� ������.";
}
