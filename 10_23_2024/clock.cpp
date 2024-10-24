#include "clock.h"

/* clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
} */
clockType::clockType(int h, int m, int s)
{
    setTime(h, m, s);
    count++;
}
void clockType::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}
int clockType::getHour() const
{
    return hr;
}
void clockType::setHour(int h)
{
    hr = h % 23;
}
void clockType::incrementHours()
{
    hr++;
    hr = hr % 23;
}
int clockType::count = 0;
/* clockType::clockType(int h, int m)
{
    setTime(h, m, 0);
} */
void clockType::setTime(int h, int m, int s)
{
    hr = h % 24;
    min = m % 60;
    sec = s % 60;
}

std::string clockType::tostring() const
{
    std::string myOutputStr;
    myOutputStr = myOutputStr + std::to_string(hr);
    std::ostringstream outStr;
    outStr << std::setfill('0') << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    return outStr.str();
}
