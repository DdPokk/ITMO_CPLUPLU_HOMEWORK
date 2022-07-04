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
        std::cout << "Файл открыть невозможно\n";
        return;
    }
    outArray << "Исходный массив:\n";
    for (int i = 0; i < n; i++) {
        outArray << mas[i] << " ";
    }
    outArray.close();

    for (int i = 0; i < n; i++)//Сортировка массива
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

    std::ofstream outSortArray("sortArray", std::ios::app);//Запись в файл отсортированного массива
    if (!outSortArray) {
        std::cout << "Файл открыть невозможно\n";
        return;
    }
    outSortArray << "\nОтсортированный массив:\n";
    for (int i = 0; i < n; i++) {
        outSortArray << mas[i] << " ";
    }
    outSortArray.close();
    std::cout << "Данные записаны в файл sortArray.txt." << std::endl;
}

int main()
{
    system("chcp 1251");
    const int N = 10;
    int d[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    std::cout << "Сортировка массива по возрастанию." << std::endl;
    sortArrayToFile(d, N);
}