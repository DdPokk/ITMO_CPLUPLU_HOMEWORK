#include <string>
#include <sstream>
#pragma once 
class human 
{
public:
	human() {};
	human(std::string last_name, std::string name, std::string second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	virtual std::string get_info() const
	{
		std::ostringstream full_name;
		full_name << this->last_name << " "
			<< this->name << " "
			<< this->second_name;
		return full_name.str();
	}
private:
	std::string name; 
	std::string last_name; 
	std::string second_name; 
};