// Lab_5.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int sumElems(int* mas, int n)
{ 
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mas[i];
    }
    return sum;
}

double meanValue(int* mas, int n)
{
    int s = sumElems(mas, n);
    return  (double)s / n;
}

int sumNegElems(int* mas, int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
            sum += mas[i];
    }
    return sum;
}

int sumPosElems(int* mas, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] > 0)
            sum += mas[i];
    }
    return sum;
}

int sumElemsOddIndex(int* mas, int n) 
{
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += mas[i];
    }
    return sum;
}

int sumElemsEvenIndex(int* mas, int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += mas[i];
    }
    return sum;
}

int indexMinElems(int* mas, int n) 
{
    int min = mas[0], index = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < min) {
            min = mas[i];
            index = i;
        }
    }
    return index;
}

int indexMaxElems(int* mas, int n) 
{
    int max = mas[0], index = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > max) {
            max = mas[i];
            index = i;
        }
    }
    return index;
}

void multElems(int* mas, int n) {
    int mult = 1;
    int indexMin = indexMinElems(mas, n);
    int indexMax = indexMaxElems(mas, n);
    if (indexMin < indexMax) {
        for (int i = indexMin; i <= indexMax; i++)
        {
            mult *= mas[i];
        }
        std::cout << "������������ ��������� ����� ����������� � ������������ ����������: " << mult << std::endl;
    }
    else if (indexMin > indexMax) {
        for (int i = indexMax; i <= indexMin; i++)
        {
            mult *= mas[i];
        }
        std::cout << "������������ ��������� ����� ����������� � ������������ ����������: " << mult << std::endl;
    }
    else
        std::cout << "������������ � ����������� �������� ���������." << std::endl;
}

void sortArray(int* mas, int n) {
    int min = 0;
    int buf = 0;
    for (int i = 0; i < n; i++)
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

    for (int i = 0; i < n; i++)
    {
        std::cout << mas[i] << '\t';
    }
}


int main()
{
    system("chcp 1251");
    const int n = 10;
    int mas[n];

    for (int i = 0; i < n; i++)
    {
        std::cout << "mas[" << i << "]=";
        std::cin >> mas[i];
    }

    std::cout << "����� ��������� �������: " << sumElems(mas, n) << std::endl;
    std::cout << "������� �������� ��������� �������: " << meanValue(mas, n) << std::endl;
    std::cout << "����� ������������� ��������� �������: " << sumNegElems(mas, n) << std::endl;
    std::cout << "����� ������������� ��������� �������: " << sumPosElems(mas, n) << std::endl;
    std::cout << "����� ��������� ������� � ��������� ���������: " << sumElemsOddIndex(mas, n) << std::endl;
    std::cout << "����� ��������� ������� � ������� ���������: " << sumElemsEvenIndex(mas, n) << std::endl;
    std::cout << "������ ������������ ��������: " << indexMinElems(mas, n) << std::endl;
    std::cout << "������ ������������� ��������: " << indexMaxElems(mas, n) << std::endl;
    multElems(mas, n);
}