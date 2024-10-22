#include "clock.h"

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
