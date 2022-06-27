// Lab_3.1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string privet(string name)
{
	string str = name + ", " + "hello!\n";
	return str;
}


int main()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	string nameOut = privet(name);
	cout << nameOut;
	return 0;
}
