// Lab_5.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int sumElems(int* mas, int n) { //Сумма элементов массива
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mas[i];
    }
    return sum;
}

double meanValue(int* mas, int n) { //Среднее значение
    int s = sumElems(mas, n);
    return  (double)s / n;
}

int sumNegElems(int* mas, int n) {//a. расчет суммы отрицательных элементов 
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
            sum += mas[i];
    }
    return sum;
}

int sumPosElems(int* mas, int n) {//b.расчет суммы положительных элементов
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] > 0)
            sum += mas[i];
    }
    return sum;
}

int sumElemsOddIndex(int* mas, int n) {//c.расчет суммы элементов с нечетными индексами
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += mas[i];
    }
    return sum;
}

int sumElemsEvenIndex(int* mas, int n) {//d.расчет суммы элементов с четными индексами
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += mas[i];
    }
    return sum;
}

int indexMinElems(int* mas, int n) {//поиск минимального элемента и его индекса 
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

int indexMaxElems(int* mas, int n) {//поиск максимального элемента и его индекса 
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
//произведение элементов массива, расположенных между максимальным и минимальным элементами
void multElems(int* mas, int n) {
    int mult = 1;
    int indexMin = indexMinElems(mas, n);
    int indexMax = indexMaxElems(mas, n);
    if (indexMin < indexMax) {
        for (int i = indexMin; i <= indexMax; i++)
        {
            mult *= mas[i];
        }
        std::cout << "Произведение элементов между минимальным и максимальным элементами: " << mult << std::endl;
    }
    else if (indexMin > indexMax) {
        for (int i = indexMax; i <= indexMin; i++)
        {
            mult *= mas[i];
        }
        std::cout << "Произведение элементов между минимальным и максимальным элементами: " << mult << std::endl;
    }
    else
        std::cout << "Максимальный и минимальный элементы совпадают." << std::endl;
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

    //Практика5, задание 1
    // Операции с элементами массива
    const int n = 10;
    int mas[n];

    for (int i = 0; i < n; i++)
    {
        std::cout << "mas[" << i << "]=";
        std::cin >> mas[i];
    }

    std::cout << "Сумма элементов массива: " << sumElems(mas, n) << std::endl;
    std::cout << "Среднее значение элементов массива: " << meanValue(mas, n) << std::endl;
    std::cout << "Сумма отрицательных элементов массива: " << sumNegElems(mas, n) << std::endl;
    std::cout << "Сумма положиетльных элементов массива: " << sumPosElems(mas, n) << std::endl;
    std::cout << "Сумма элементов массива с нечетными индексами: " << sumElemsOddIndex(mas, n) << std::endl;
    std::cout << "Сумма элементов массива с четными индексами: " << sumElemsEvenIndex(mas, n) << std::endl;
    std::cout << "Индекс минимального элемента: " << indexMinElems(mas, n) << std::endl;
    std::cout << "Индекс максимального элемента: " << indexMaxElems(mas, n) << std::endl;
    multElems(mas, n);

    //Сортировка массива (сортировка выбором)
    const int N = 10;
    int d[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    std::cout << "Сортировка массива по возрастанию:" << std::endl;
    sortArray(d, N);
}