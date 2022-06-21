// Lab_2.final.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int A(10), B(5), C(2), D(1);
	int i = 0;
	int sum = 0;
	int ostatok = 0;
	int result = 0;
	std::cout << "¬ведите сумму: "; std::cin >> sum;

	if ((sum % A) != 0) 												
	{
		i = sum / A;
		std::cout << i << " x " << A << " рублей \n";
		ostatok = sum - i * A;
		i = ostatok / B;
		std::cout << i << " x " << B << " рублей \n";
		if (ostatok % B != 0)
		{
			ostatok = ostatok - i * B;
			i = ostatok / C;
			std::cout << i << " x " << C << " рублей \n";
			if (ostatok % C != 0)
			{
				ostatok = ostatok - i * C;
				i = ostatok / D;
				std::cout << i << " x " << D << " рублей \n";
			}
		}
	}
	else if (sum % 10 == 0 && sum != 0)
	{
		i = sum / 10;
		std::cout << i << " x " << A << " рублей \n";
	}
}
