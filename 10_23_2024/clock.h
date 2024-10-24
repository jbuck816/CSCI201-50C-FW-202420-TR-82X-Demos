#ifndef CLOCK_H
#define CLOCK_H
// #pragma once
#include <string>
#include <sstream>
#include <iomanip>

enum amPmType
{
    AM,
    PM
};
enum clockFormatType
{
    TWELVE = 12,
    TWENTYFOUR = 24
};
const amPmType times[] = {AM, PM};
const clockFormatType formats[] = {TWELVE, TWENTYFOUR};
const std::string amPmToStr[] = {"AM", "PM"};
const std::string clockFormatToStr[] = {"12 hour clock", "24 hour clock"};

class clockType
{
public:
    // clockType();
    clockType(int h = 0, int m = 0, int s = 0, std::string = "PM", clockFormatType = TWENTYFOUR);
    // clockType(int h, int m);
    void setTime(int h, int m, int s, std::string = "PM");

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
    std::string timeOfDay;
    clockFormatType format;
};
#endif