// Lab_6.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int main()
{
    system("chcp 1251");
    const int MAX = 1000;
    char str[MAX];
    std::cout << "������� �����, ��� ��������� ����� �������� 'Y'.\n" << std::endl;
    std::cin.get(str, MAX, 'Y');
    std::ofstream text("text");
    if (!text) 
    {
        std::cout << "���� �� �����������\n";
        return 1;
    }
    text << str;
    std::cout << "������������� � ����� text.txt." << std::endl;
}