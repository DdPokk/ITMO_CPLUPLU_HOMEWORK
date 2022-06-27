// Lab_3.final.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void convert10to2(int num)
{
	if (num >= 2) 
	convert10to2(num / 2);
	std::cout << num % 2;
}
int main()
{
	system("chcp 1251");
	std::cout << "Введите положительное число.\n";
	int num;
	std::cin >> num;
	std::cout << "Двоичная запись числа: " << std::ends;
	convert10to2(num);
}
