// Lab_5.final.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int* max_vect(int len, int* array1, int* array2) {
	int* maxNums = new int[len];
	for (int i = 0; i < len; i++) {
		maxNums[i] = (array1[i] > array2[i]) ? array1[i] : array2[i];
	}
	return maxNums;
}

int main()
{
    system("chcp 1251");

    std::cout << "\nВыбор наибольшего элемента из пары:" << std::endl;
    int a[] = { 1,2,3,4,5,6,7,2 };
    int b[] = { 7,6,5,4,3,2,1,3 };
    int kc = sizeof(a) / sizeof(a[0]); //Количество элементов массива
    int* c; //Указатель на результирующий массив
    c = max_vect(kc, a, b);
    for (int i = 0; i < kc; i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
    delete[]c;
}
