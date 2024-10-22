#ifndef CLOCK_H
#define CLOCK_H
// #pragma once
#include <string>
#include <sstream>
#include <iomanip>

class clockType
{
public:
    void setTime(int h, int m, int s);
    void getTime() const;
    std::string tostring() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &) const;

private:
    int hr;
    int min;
    int sec;
};
#endif