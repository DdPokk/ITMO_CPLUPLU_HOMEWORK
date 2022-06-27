// Lab_3.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

long double firBinSearch(double a, int n)
{
    double L = 0;
    double R = a;
    while (R - L > 1e-10)
    {
        double M = (L + R) / 2;
        if (pow(M, n) < a)
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    cout << "корень из степени " << n << " из числа " << a << " будет равен - " << R << endl;
    return R;
}

int main()
{
    system("chcp 1251");
    double k;
    cout << "Input number one:" << endl;
    cin >> k;

    int g;
    cout << "Input number two:" << endl;
    cin >> g;

    firBinSearch(k, g);
    }
