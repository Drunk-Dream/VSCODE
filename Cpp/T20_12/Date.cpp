#include <iostream>
#include <string>
#include "Date.h"
#include <stdexcept>
using namespace std;

const int Date::days[13] =
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Date constructor
Date::Date(int month, int day, int year)
{
    setDate(month, day, year);
}

//set month,day,year
void Date::setDate(int mm, int dd, int yy)
{
    if (mm >= 1 && mm <= 12)
        month_ = mm;
    else
        throw invalid_argument("Month must be1-12");

    if (yy >= 1900 && yy <= 2100)
        year_ = yy;
    else
        throw invalid_argument("Year must be >= 1900 and <= 2100");

    //test for a leap year
    if ((month_ == 2 && leapYear(year_) && dd >= 1 && dd <= 29) || (dd >= 1 && dd <= days[month_]))
        day_ = dd;
    else
        throw invalid_argument("Day is out of range for current month and year");
}

//overloaded prefix increment operator
Date &Date::operator++()
{
    helpIncrement(); //increment date
    return *this;
}

//重载后置操作符
Date Date::operator++(int)
{
    Date temp = *this;
    helpIncrement();

    return temp;
}

//重载+=
Date &Date::operator+=(
    int additionalDays)
{
    for (int i = 0; i < additionalDays; i++)
        helpIncrement();

    return *this;
}

//闰年返回true,否则返回false
bool Date::leapYear(int testYear)
{
    if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0))
        return true;
    else
        return false;
}

//判断是否为本月最后一天
bool Date::endOfMonth(int testDay) const
{
    if (month_ == 2 && leapYear(year_))
        return testDay == 29;
    else
        return testDay == days[month_];
}

//function to help increment the date
void Date::helpIncrement()
{
    if (!endOfMonth(day_)) //如果不是一个月的最后一天
        ++day_;
    else                 //不是最后一天
        if (month_ < 12) //不是最后一个月
    {
        ++month_;
        day_ = 1;
    }
    else //最后一个月
    {
        ++year_;
        month_ = 1;
        day_ = 1;
    }
}

//overload output operator
ostream &operator<<(ostream &output, const Date &d)
{
    static string monthName[13] = {"", "January", "February", "March",
                                   "April", "May", "June", "July", "August",
                                   "September", "October", "November", "December"};
    output << monthName[d.month_] << ' ' << d.day_ << "," << d.year_;
    return output;
}

//返回当前月份
int Date::getMonth() const
{
    return month_;
}