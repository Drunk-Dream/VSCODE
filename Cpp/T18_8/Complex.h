#ifndef _COMPLEX_H
#define _COMPLEX_H
#include <iostream>

class Complex
{
private:
    double real;      //real part
    double imaginary; //imaginary part
public:
    //构造函数
    explicit Complex(double = 0.0, double = 0.0);
    //重载+，进行复数运算
    Complex operator+(const Complex &) const;
    //重载-，进行复数运算
    Complex operator-(const Complex &) const;
    //输出复数
    void print() const;

    //重载<<,输出复数
    friend std::ostream &operator<<(std::ostream &, Complex &);
    //重载>>，输入复数
    friend std::istream &operator>>(std::istream &, Complex &);

    //重载*，进行复数乘法运算
    Complex operator*(const Complex &) const;
    //重载==，判断两个复数是否相等
    bool operator==(const Complex &) const;
    //重载!=，判断两个复数是否不相等
    bool operator!=(const Complex &right) const
    {
        return !(*this == right);
    }
};

#endif