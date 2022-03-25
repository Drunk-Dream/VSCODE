#include <iostream>
#include <cmath>
#include <cstdlib>
#include "RationalNumber.h"
using namespace std;

//构造函数，输入分子分母初始化
RationalNumber::RationalNumber(int molecular, int denominator)
{
    //如果分母为零退出程序然后返回错误信息
    if (denominator == 0)
    {
        cerr << "denominator must not 0!";
        exit(1);
    }
    molecular_ = molecular;
    denominator_ = denominator;

    RationalNumber::Simply(); //调用化简函数
}

//化简函数，用来将分数化简并且将负号放到分子上（如果为负数）
void RationalNumber::Simply()
{
    int molecular = abs(molecular_), denominator = abs(denominator_);

    //找出分子分母的最小值，作为循环的终止条件
    int min;
    if (molecular <= denominator)
        min = molecular;
    else
        min = denominator;

    //找出最大公因数
    int max_simplest = 1;
    for (int i = 1; i <= min; i++)
    {
        if (molecular % i == 0 && denominator % i == 0)
        {
            max_simplest = i;
        }
        else
            continue;
    }

    //判断分数是否为负数，为负数则将负号放到分母上
    if (molecular_ * denominator_ >= 0)
    {
        molecular_ = molecular / max_simplest;
        denominator_ = denominator / max_simplest;
    }
    else
    {
        molecular_ = -molecular / max_simplest;
        denominator_ = denominator / max_simplest;
    }
}

//重载+号，进行分数加法计算
RationalNumber RationalNumber::operator+(const RationalNumber &right) const
{
    RationalNumber temp;
    temp.molecular_ = molecular_ * right.denominator_ + right.molecular_ * denominator_;
    temp.denominator_ = denominator_ * right.denominator_;
    temp.Simply();
    return temp;
}

// 重载-号，进行分数减法计算
RationalNumber RationalNumber::operator-(const RationalNumber &right) const
{
    RationalNumber temp;
    temp.molecular_ = molecular_ * right.denominator_ - right.molecular_ * denominator_;
    temp.denominator_ = denominator_ * right.denominator_;
    temp.Simply();
    return temp;
}

// 重载-号，使分数变为相反数
RationalNumber RationalNumber::operator-() const
{
    return RationalNumber(-molecular_, denominator_);
}

// 重载*号，进行分数乘法计算
RationalNumber RationalNumber::operator*(const RationalNumber &right) const
{
    RationalNumber temp;
    temp.molecular_ = molecular_ * right.molecular_;
    temp.denominator_ = denominator_ * right.denominator_;
    temp.Simply();
    return temp;
}

// 重载/号，进行分数除法计算
RationalNumber RationalNumber::operator/(const RationalNumber &right) const
{
    RationalNumber temp;
    temp.molecular_ = molecular_ * right.denominator_;
    temp.denominator_ = denominator_ * right.molecular_;
    temp.Simply();
    return temp;
}

// 重载=,赋值运算
RationalNumber RationalNumber::operator=(const RationalNumber &right)
{
    molecular_ = right.molecular_;
    denominator_ = right.denominator_;
    return *this;
}

//重载>号，比较分数的大小
bool RationalNumber::operator>(const RationalNumber &right) const
{
    RationalNumber temp;
    temp = *this - right;
    if (temp.molecular_ > 0)
        return true;
    else
        return false;
}

//重载>=号，比较分数大小
bool RationalNumber::operator>=(const RationalNumber &right) const
{
    RationalNumber temp;
    temp = *this - right;
    if (temp.molecular_ >= 0)
        return true;
    else
        return false;
}

// 重载<号，比较分数大小
bool RationalNumber::operator<(const RationalNumber &right) const
{
    RationalNumber temp;
    temp = *this - right;
    if (temp.molecular_ < 0)
        return true;
    else
        return false;
}

// 重载<=号，比较分数大小
bool RationalNumber::operator<=(const RationalNumber &right) const
{
    RationalNumber temp;
    temp = *this - right;
    if (temp.molecular_ <= 0)
        return true;
    else
        return false;
}

bool RationalNumber::operator==(const RationalNumber &right) const
{
    RationalNumber temp;
    temp = *this - right;
    if (temp.molecular_ == 0)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &output, RationalNumber &ra)
{
    if (ra.denominator_ == 1 || ra.molecular_ == 0)
        output << ra.molecular_;
    else
        output << ra.molecular_ << "/" << ra.denominator_;
    return output;
}