// Lab_2.1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char op;
	std::cout << "Сделай свой выбор, собери авто своей мечты: ";
	std::cin >> op;

	switch (op)
	{
	case 'S':
		std::cout << "Радио играть должно\n";
	case 'V':
		std::cout << "Кондиционер хочу\n";

	default:
		std::cout << "Колеса круглые\n";
		std::cout << "Мощный двигатель\n";
	}
}

