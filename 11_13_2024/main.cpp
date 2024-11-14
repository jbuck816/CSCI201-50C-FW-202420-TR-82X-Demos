#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include "clock.h"

clockType *createClock();
void morningOrAfternoon(const clockType &, bool &);
void resetStream();
bool codeGradeLoopFix(std::string errLocation);
// add body to < >= and <= in clock.cpp

int main()
{
    clockType c1(12, 12, 12, "PM", TWELVE);
    clockType c2;
    int x = 7;
    int y = 9;
    int z = x + y;
    z = x++ + ++y; // y = 10, z = 17, x = 8;
    c1 = 4 + c1;
    c1 = c1 + 4;
    clockType *c3 = createClock();
    ++c2;
    c2++;
    if (c1 == c2) // c1.operator==(c2)
    {
        std::cout << "They are the same." << std::endl;
    }
    std::cout << c1 << std::endl;
    std::cout << *c3 << std::endl;

    delete c3;
    return 0;
}

clockType *createClock()
{

    std::string tod;
    int format;
    clockType *newClock;
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
            return new clockType(0, 0, 0);
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
                return new clockType(0, 0, 0);
            }
            std::cout << "Is it AM or PM?" << std::endl;
            std::cin >> std::ws;
            std::getline(std::cin, tod);

            std::transform(tod.begin(), tod.end(), tod.begin(), ::toupper);
            std::cout << tod << std::endl;
        }
    }

    if (format == 1)
    {
        newClock = new clockType(12, 00, 00, tod, formats[format - 1]);
    }
    else
    {
        newClock = new clockType();
    }
    std::cout << "Enter the hours, minutes and seconds on the clock: ";
    std::cin >> *newClock;
    return newClock;
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
