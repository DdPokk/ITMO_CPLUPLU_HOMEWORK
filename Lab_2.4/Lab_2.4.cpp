// Lab_2.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <ctime>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int k{}, m{}, s{};
	std::cout << "¬ведите значение k: "; std::cin >> k;
	std::cout << "¬ведите значение m: "; std::cin >> m;
	
	
	for (int i = 1; i <= 100; i++) 
	{
		if ((i > k) && (i < m))
			continue;
		s += 1;
	}
		std::cout << "s = " << s << std::endl;
	return 0;
}