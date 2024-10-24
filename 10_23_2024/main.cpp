#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "clock.h"

clockType createClock();
void morningOrAfternoon(const clockType &, bool &);
void resetStream();

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
    std::cout << "Enter the hour: ";
    std::cin >> hr;
    std::cout << std::endl;
    while (!std::cin || hr < 0 || hr > 23)
    {
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
    clockType newClock(hr, min, sec);
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