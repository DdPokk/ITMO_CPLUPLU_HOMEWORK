// Lab_3.final.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
using namespace std;


double korenPow(double a) {
    a = pow(a, 1.0 / 3);
    return a;
}

int korenIter(int a) {
    int x = a;
    int x2;

    for (int i = 1; i < 10; i++)
    {
        while (x = a)
        {
            x = ((a / (i * i) + (2 * i)) / 3);
        }
        return i;
    }
}

int main()
{
    system("chcp 1251");
    cout << "\n¬ведите число" << endl;
    int a1;
    cin >> a1;
    cout << "\n убический корень: " << korenPow(a1)<< endl;
}
