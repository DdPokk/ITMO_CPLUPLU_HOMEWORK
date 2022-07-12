#pragma once
#include "human.h"
#include <string>
class teacher : public human {
public:
	teacher(
		std::string last_name, std::string name, std::string second_name,
		unsigned int work_time) : human(last_name, name, second_name) {
		this->work_time = work_time;
	}

	std::string get_info() const
	{
		std::ostringstream full_name;
		full_name << human::get_info() << "\nКоличество часов: " << get_work_time();
		return full_name.str();
	}
	unsigned int get_work_time() const
	{
		return this->work_time;
	}
private:
	unsigned int work_time;
};