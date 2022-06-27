// Lab_4.final.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool input(int& a, int& b) {
	int ina, inb;
	std::cout << "¬ведите два целых положительных числа:" << std::endl;
	if (!(std::cin >> ina) or !(std::cin >> inb) or (ina <= 0) or (inb <= 0))
		return false;
	a = ina;
	b = inb;
	return true;
}

int main()
{
	system("chcp 1251");
	int a1, b1;
	if (input(a1, b1) == false) // if(!Input(a,b))
	{
		std::cerr << "error";
		return 1;
	}
	int s = a1 + b1;
	return 0;
}