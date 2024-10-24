#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "clock.h"

clockType createClock();
void morningOrAfternoon(const clockType &, bool &);
void resetStream();
bool codeGradeLoopFix(std::string errLocation);
// add getters and setters min, sec, timeofday

int main()
{
    clockType myClock;
    clockType secondClock(6, 24, 3);
    clockType thirdClock(11, 5);
    clockType fourthClock(14);
    /* myClock.hr = 8;
    myClock.min = 48;
    myClock.sec = 28;
 */
    clockType fifthClock = createClock();
    myClock.setTime(8, 48, 28);
    std::cout << myClock.tostring() << std::endl;
    std::cout << secondClock.tostring() << std::endl;
    std::cout << thirdClock.tostring() << std::endl;
    std::cout << fourthClock.tostring() << std::endl;
    std::cout << fifthClock.tostring() << std::endl;
    bool am;
    morningOrAfternoon(fifthClock, am);
    if (am)
    {
        std::cout << "Fifth clock is in the morning" << std::endl;
    }
    else
    {
        std::cout << "fifth clock is in the afternoon" << std::endl;
    }
    std::cout << clockType::count << std::endl;
    myClock.incrementHours();
    return 0;
}

clockType createClock()
{
    int hr, min, sec;
    int tod;
    int format;
    std::cout << "What kind of clock do you have?" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << i + 1 << ": " << clockFormatToStr[i] << std::endl;
    }
    std::cin >> format;
    while (!std::cin || format < 1 || format > 2)
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
        std::cout << "Is it AM (1) or PM (2)?" << std::endl;
        std::cin >> tod;
        while (!std::cin || tod < 1 || tod > 2)
        {
            if (codeGradeLoopFix("AM PM loop"))
            {
                return clockType(0, 0, 0);
            }
            if (!std::cin)
            {
                resetStream();
            }

            std::cout << "Please choose 1 for AM or 2 for PM." << std::endl;

            std::cin >> tod;
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
        clockType newClock(hr, min, sec, times[tod - 1], formats[format - 1]);
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
