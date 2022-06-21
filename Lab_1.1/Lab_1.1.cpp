// Lab_1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	cout << "What is your name? ";
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}