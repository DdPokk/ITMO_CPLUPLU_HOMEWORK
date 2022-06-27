// Lab_3.final.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int sum5(int n) {
	if (n == 1) return 5;
	else return(n * 5 + sum5(n - 1));
}
int main()
{
	system("chcp 1251");
	std::cout << "¬ведите число n.\n";
	int n;
	std::cin >> n;
	std::cout << "сумма р€да s = 5 + 10 + 15 + Е + 5Јn равна " << sum5(n) << std::endl;
}