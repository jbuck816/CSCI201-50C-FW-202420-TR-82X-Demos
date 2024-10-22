#include <iostream>
#include <string>
#include <iomanip>
#include "clock.h"

int main()
{
    clockType myClock;
    /* myClock.hr = 8;
    myClock.min = 48;
    myClock.sec = 28;
 */
    myClock.setTime(8, 48, 28);
    std::cout << myClock.tostring() << std::endl;
    return 0;
}