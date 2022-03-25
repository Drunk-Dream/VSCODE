#ifndef _RATIONALNUMBER_H
#define _RATIONALNUMBER_H
#include <iostream>
class RationalNumber
{
private:
    //定义分子分母
    int molecular_, denominator_;

public:
    //构造函数
    explicit RationalNumber(int = 0, int = 1);

    //创建一个用来化简的函数
    void Simply();

    //重载+，进行分数加法运算
    RationalNumber operator+(const RationalNumber &) const;
    //重载-（减号）,进行分数减法运算
    RationalNumber operator-(const RationalNumber &) const;
    //重载-（符号），使分数变为相反数
    RationalNumber operator-() const;
    //重载*,进行分数乘法运算
    RationalNumber operator*(const RationalNumber &) const;
    //重载/,进行分数除法运算
    RationalNumber operator/(const RationalNumber &) const;
    //重载=，进行赋值
    RationalNumber operator=(const RationalNumber &);

    //重载关系运算符
    bool operator>(const RationalNumber &) const;
    bool operator>=(const RationalNumber &) const;
    bool operator<(const RationalNumber &) const;
    bool operator<=(const RationalNumber &) const;

    //重载相等运算符
    bool operator==(const RationalNumber &) const;
    bool operator!=(const RationalNumber &right) const
    {
        return !(*this == right);
    }

    friend std::ostream &operator<<(std::ostream &, RationalNumber &);
};

#endif