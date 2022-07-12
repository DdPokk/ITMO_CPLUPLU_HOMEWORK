// Lab_13.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <windows.h>
#include "human.h"
#include "student.h"
#include "teacher.h"

int main()
{
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
	student* stud = new student("Петров", "Петр", "Петрович", scores);
	std::cout << stud->get_full_name() << std::endl;
student: std::cout << "Средний балл : " << stud->get_average_score() << std::endl;
	unsigned int teacher_work_time = 40;
	teacher* tch = new teacher("Сергеев", "Сергей", "Сергеевич", teacher_work_time);
	std::cout << tch->get_full_name() << std::endl;
	std::cout << "Количество часов: " << tch->get_work_time() << std::endl;
	return 0;
}
