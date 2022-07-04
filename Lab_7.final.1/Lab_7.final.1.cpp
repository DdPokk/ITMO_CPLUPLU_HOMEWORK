// Lab_7.final.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

struct Time 
{
    int hours, minutes, seconds;
    void InputTime()
    {
        std::cout << "\nВведите часы: ";
        std::cin >> hours;
        std::cout << "Введите минуты: ";
        std::cin >> minutes;
        std::cout << "Введите секунды: ";
        std::cin >> seconds;
    }

    void ShowTime() 
    {
        std::cout << "Часы: " << hours << " Минуты: " << minutes << " Секунды: " << seconds << std::endl;
    }
    int TimeToSeconds()
    {
        return hours * 3600 + minutes * 60 + seconds;
    }
    void PlusTime(Time time)
    {
        int addInSeconds = TimeToSeconds() + time.TimeToSeconds();
        hours = addInSeconds / 3600;
        minutes = (addInSeconds % 3600) / 60;
        seconds = addInSeconds % 60;
    }
    void MinusTime(Time time) 
    {
        int minusInSeconds = abs(TimeToSeconds() - time.TimeToSeconds());
        hours = minusInSeconds / 3600;
        minutes = (minusInSeconds % 3600) / 60;
        seconds = minusInSeconds % 60;
    }
};

void TestTime() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Time time1;
    Time time2 = { 1, 30, 5 };
    time1.InputTime();
    time1.ShowTime();
    time2.ShowTime();
    std::cout << time1.TimeToSeconds() << std::endl;
    time1.PlusTime(time2);
    time1.ShowTime();
    time1.MinusTime(time2);
    time1.MinusTime(time2);
    time1.ShowTime();
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    TestTime();
    return 0;
}
