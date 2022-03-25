#include <iostream>
#include <iomanip>
#include "Complex.h"
using namespace std;

Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart), imaginary(imaginaryPart)
{
}

Complex Complex::operator+(const Complex &operand2) const
{
    return Complex(real + operand2.real,
                   imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2) const
{
    return Complex(real - operand2.real,
                   imaginary - operand2.imaginary);
}

void Complex::print() const
{
    cout << '(' << real << "," << imaginary << ')';
}

//重载<<
ostream &operator<<(ostream &output, Complex &a)
{
    output << setw(3) << left << a.real << "+" << setw(3) << right << a.imaginary << "*i";

    return output;
}

//重载>>
istream &operator>>(istream &input, Complex &a)
{
    char non1, non2, non3;
    input >> a.real >> non1 >> a.imaginary >> non2 >> non3;

    return input;
}

//重载*，进行复数乘法运算
Complex Complex::operator*(const Complex &operand2) const
{
    Complex middle;
    middle.real = real * operand2.real - imaginary * operand2.imaginary;
    middle.imaginary = real * operand2.imaginary + imaginary * operand2.real;

    return middle;
}

//重载==,判断两个复数是否相等
bool Complex::operator==(const Complex &right) const
{
    if (real == right.real && imaginary == right.imaginary)
        return true;
    else
        return false;
}