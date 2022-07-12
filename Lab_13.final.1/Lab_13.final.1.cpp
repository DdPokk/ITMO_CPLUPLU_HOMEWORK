// Lab_13.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <windows.h>
#include "human.h"
#include "student.h"
#include "teacher.h"

void ShowInfo(const human* hum) 
{
	std::cout << hum->get_info() << "\n----------------- " << std::endl;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::vector<int> scores;
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	human* hum1 = new human("Иванов", "Иван", "Иванович");
	std::cout << hum1->get_info() << "\n----------------- " << std::endl;
	student* stud = new student("Петров", "Петр", "Петрович", scores);
	hum1 = stud;
	std::cout << hum1->get_info() << "\n----------------- " << std::endl;
	unsigned int teacher_work_time = 40;
	teacher* tch = new teacher("Сергеев", "Сергей", "Сергеевич", teacher_work_time);
	hum1 = tch;
	std::cout << hum1->get_info() << "\n----------------- " << std::endl;
	delete hum1;
	delete stud;
	delete tch;
	return 0;
}
