// Lab_2.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <ctime>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int a;
	std::cout << "Год: "; std::cin >> a;

	if ((a % 4 == 0) && (a % 100 != 0)) 
	{
		std::cout << a << " YES";
	}
	else if ((a % 400 == 0) && (a % 100 != 0))
	{
		std::cout << a << " YES ";
	}
	else std::cout << a << " NO ";
}