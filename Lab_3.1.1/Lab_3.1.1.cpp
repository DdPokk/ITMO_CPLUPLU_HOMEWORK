// Lab_3.1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


void privet(string name)
{
	cout << name << ", " << "hello!" << endl;
}

int main()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	privet(name);
	return 0;
}
