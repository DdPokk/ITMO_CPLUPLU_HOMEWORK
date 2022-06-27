// Lab_3.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

//1.
int addNumders(int n)
{
    if (n == 1) return 1; 
    else return (n + addNumders(n - 1));
}

//2.
int gcd(int m, int n)
{
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main()
{
    system("chcp 1251");

    double k;
    cout << "\nInput number: \n" << endl;
    cin >> k;
    cout << " Сумма чисел - " << addNumders(k);

    int a;
    cout << "\nInput number one: \n" << endl;
    cin >> a;

    int b;
    cout << "\nInput number two: \n" << endl;
    cin >> b;

    cout << "Результат - " << gcd(a, b);

}
