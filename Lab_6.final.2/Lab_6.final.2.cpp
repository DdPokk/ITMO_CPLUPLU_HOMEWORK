// Lab_6.final.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

void sortArrayToFile(int* mas, int n)
{
    int min = 0;
    int buf = 0;

    std::ofstream outArray("sortArray");
    if (!outArray) {
        std::cout << "���� ������� ����������\n";
        return;
    }
    outArray << "�������� ������:\n";
    for (int i = 0; i < n; i++) {
        outArray << mas[i] << " ";
    }
    outArray.close();

    for (int i = 0; i < n; i++)//���������� �������
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            min = (mas[j] < mas[min]) ? j : min;
        if (i != min)
        {
            buf = mas[i];
            mas[i] = mas[min];
            mas[min] = buf;
        }
    }

    std::ofstream outSortArray("sortArray", std::ios::app);//������ � ���� ���������������� �������
    if (!outSortArray) {
        std::cout << "���� ������� ����������\n";
        return;
    }
    outSortArray << "\n��������������� ������:\n";
    for (int i = 0; i < n; i++) {
        outSortArray << mas[i] << " ";
    }
    outSortArray.close();
    std::cout << "������ �������� � ���� sortArray.txt." << std::endl;
}

int main()
{
    system("chcp 1251");
    const int N = 10;
    int d[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    std::cout << "���������� ������� �� �����������." << std::endl;
    sortArrayToFile(d, N);
}