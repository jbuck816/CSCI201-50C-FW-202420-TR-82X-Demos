#include "clock.h"

/* clockType::clockType()
{
    hr = 0;
    min = 0;
    sec = 0;
} */
clockType::clockType(int h, int m, int s, std::string am, clockFormatType f)
{
    setTime(h, m, s);
    timeOfDay = am;
    format = f;
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
    if (format == TWENTYFOUR)
    {
        hr = hr % 24;
    }
    else
    {
        if (hr == 12)
        {
            if (timeOfDay == "PM")
                timeOfDay = "AM";
            else
                timeOfDay = "PM";
        }
    }
}
int clockType::count = 0;
/* clockType::clockType(int h, int m)
{
    setTime(h, m, 0);
} */
void clockType::setTime(int h, int m, int s, std::string a)
{
    timeOfDay = a;
    if (format == TWENTYFOUR)
        hr = h % 24;
    else
    {
        if (h > 12 || h < 1)
            hr = h % 12 + 1;
        else
            hr = h;
    }
    min = m % 60;
    sec = s % 60;
}

std::string clockType::tostring() const
{
    std::string myOutputStr;
    myOutputStr = myOutputStr + std::to_string(hr);
    std::ostringstream outStr;
    outStr << std::setfill('0') << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec << " " << timeOfDay;
    return outStr.str();
}
