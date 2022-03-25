#ifndef _DATE_H
#define _DATE_H

#include <iostream>

class Date
{
    friend std::ostream &operator<<(std::ostream &, const Date &);

public:
    //构造函数
    Date(int = 1, int = 1, int = 1900);
    //set month,day,year
    void setDate(int, int, int);
    //重载前操作++
    Date &operator++();
    //重载后操作++
    Date operator++(int);
    //重载+= 1
    Date &operator+=(int);
    //是否闰年
    static bool leapYear(int);
    //是否一个月的最后一天
    bool endOfMonth(int) const;
    //返回当前月份
    int getMonth() const;

private:
    int month_;
    int day_;
    int year_;

    static const int days[13];
    void helpIncrement();
};

#endif