#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include "clock.h"

clockType createClock();
void morningOrAfternoon(const clockType &, bool &);
void resetStream();
bool codeGradeLoopFix(std::string errLocation);
// add getters and setters min, sec, timeofday

int main()
{
    clockType c1(12, 12, 12, "PM", TWELVE);
    clockType c2;
    int x = 7;
    int y = 9;
    int z = x + y;
    c1 = 4 + c1;
    c1 = c1 + 4;
    if (c1 == c2) // c1.operator==(c2)
    {
        std::cout << "They are the same." << std::endl;
    }
    std::cout << c1 << std::endl;
    return 0;
}

clockType createClock()
{
    int hr, min, sec;
    std::string tod;
    int format;
    std::cout << "What kind of clock do you have?" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << i + 1 << ": " << clockFormatToStr[i] << std::endl;
    }
    std::cin >> format;
    while (!std::cin || format < 1 || format > 2)
    {
        if (codeGradeLoopFix("line 58"))
        {
            return clockType(0, 0, 0);
        }
        if (!std::cin)
        {
            resetStream();
        }
        else
        {
            std::cout << "Please choose a clock type from the list." << std::endl;
        }
        std::cout << "What kind of clock do you have?" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::cout << i + 1 << ": " << clockFormatToStr[i] << std::endl;
        }
        std::cin >> format;
    }
    if (format == 1)
    {
        std::cout << "Is it AM or PM?" << std::endl;
        std::cin >> std::ws;
        std::getline(std::cin, tod);

        std::transform(tod.begin(), tod.end(), tod.begin(), ::toupper);
        std::cout << tod << std::endl;
        while (tod != "AM" && tod != "PM")
        {
            if (codeGradeLoopFix("line 52"))
            {
                return clockType(0, 0, 0);
            }
            std::cout << "Is it AM or PM?" << std::endl;
            std::cin >> std::ws;
            std::getline(std::cin, tod);

            std::transform(tod.begin(), tod.end(), tod.begin(), ::toupper);
            std::cout << tod << std::endl;
        }
    }
    std::cout << "Enter the hour: ";
    std::cin >> hr;
    std::cout << std::endl;
    while (!std::cin || hr < 0 || hr > 23)
    {
        if (codeGradeLoopFix("line 52"))
        {
            return clockType(0, 0, 0);
        }
        if (!std::cin)
        {
            resetStream();
        }
        else
        {
            std::cout << "The hour needs to be between 0 and 23. Try again!" << std::endl;
        }
        std::cout << "Enter the hour: ";
        std::cin >> hr;
        std::cout << std::endl;
    }
    std::cout << "Enter the min: ";
    std::cin >> min;
    std::cout << std::endl;
    while (!std::cin || min < 0 || min > 59)
    {
        if (codeGradeLoopFix("Line 73"))
        {
            return clockType(0, 0, 0);
        }
        if (!std::cin)
        {
            resetStream();
        }
        else
        {
            std::cout << "The min needs to be between 0 and 59. Try again!" << std::endl;
        }
        std::cout << "Enter the min: ";
        std::cin >> min;
        std::cout << std::endl;
    }
    std::cout << "Enter the second: ";
    std::cin >> sec;
    std::cout << std::endl;
    while (!std::cin || sec < 0 || sec > 59)
    {
        if (codeGradeLoopFix("Line 94"))
        {
            return clockType(0, 0, 0);
        }
        if (!std::cin)
        {
            resetStream();
        }
        else
        {
            std::cout << "The second needs to be between 0 and 59. Try again!" << std::endl;
        }
        std::cout << "Enter the second: ";
        std::cin >> sec;
        std::cout << std::endl;
    }
    if (format == 1)
    {
        clockType newClock(hr, min, sec, tod, formats[format - 1]);
        return newClock;
    }
    else
    {
        clockType newClock(hr, min, sec);
        return newClock;
    }
}

void morningOrAfternoon(const clockType &c, bool &am)
{
    int h, m, s;
    c.getTime(h, m, s);
    if (h >= 0 && h <= 11)
    {
        am = true;
        return;
    }
    else
    {
        am = false;
        return;
    }
}

void resetStream()
{
    std::cout << "You entered something that is not a number." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        return true;
    }
    return false;
}
