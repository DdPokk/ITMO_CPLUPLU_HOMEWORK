// Lab_3.final.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int sumMult5(int n) {
	if (n == 1) return 5;
	else return(n * 5 + sumMult5(n - 1));
}
int main()
{
	system("chcp 1251");
	std::cout << "������� ������������� ����� n.\n";
	int n;
	std::cin >> n;
	std::cout << "����� ���� s = 5 + 10 + 15 + � + 5�n ����� " << sumMult5(n) << std::endl;
}