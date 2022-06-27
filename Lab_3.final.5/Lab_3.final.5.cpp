// Lab_3.final.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void convert(int num)
{
	if (num >= 2) 
	convert(num / 2);
	std::cout << num % 2;
}
int main()
{
	system("chcp 1251");
	std::cout << "¬ведите число.\n";
	int num;
	std::cin >> num;
	std::cout << "ƒвоична€ запись числа: " << std::ends;
	convert(num);
}
