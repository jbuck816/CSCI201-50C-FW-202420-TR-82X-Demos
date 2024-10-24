#ifndef CLOCK_H
#define CLOCK_H
// #pragma once
#include <string>
#include <sstream>
#include <iomanip>

class clockType
{
public:
    // clockType();
    clockType(int h = 0, int m = 0, int s = 0);
    // clockType(int h, int m);
    void setTime(int h, int m, int s);

    void getTime(int &, int &, int &) const;
    int getHour() const;
    void setHour(int h);
    std::string tostring() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &) const;
    static int count;

private:
    int hr;
    int min;
    int sec;
};
#endif