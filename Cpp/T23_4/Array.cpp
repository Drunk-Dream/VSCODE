#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Array.h"
using namespace std;

//构造函数
template <typename T>
Array<T>::Array(int arraySize)
    : size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be greater than 0")),
      ptr(new T[size])
{
    for (size_t i = 0; i < size; i++)
        ptr[i] = 0;
}

//拷贝构造函数
template <typename T>
Array<T>::Array(const Array<T> &arrayToCopy)
    : size(arrayToCopy.size),
      ptr(new T[size])
{
    for (size_t i = 0; i < size; i++)
        ptr[i] = arrayToCopy.ptr[i];
}

//析构函数
template <typename T>
Array<T>::~Array()
{
    delete[] ptr;
}

//返回数组大小
template <typename T>
size_t Array<T>::getSize() const
{
    return size;
}

//重载赋值运算符
template <typename T>
const Array<T> &Array<T>::operator=(const Array<T> &right)
{
    if (&right != this) //avoid self-assignment
    {
        delete[] ptr;
        size = right.size;
        ptr = new T[size];
    }
    for (size_t i = 0; i < size; i++)
    {
        ptr[i] = right.ptr[i];
    }
    return *this;
}

//重载==
template <typename T>
bool Array<T>::operator==(const Array<T> &right) const
{
    if (size != right.size)
        return false;

    for (size_t i = 0; i < size; i++)
    {
        if (ptr[i] != right.ptr[i])
            return false;
    }

    return true;
}

//重载下标访问非常量数组
template <typename T>
T &Array<T>::operator[](int subscript)
{
    if (subscript < 0 || subscript > size)
        throw out_of_range("Subscript out of range");

    return ptr[subscript];
}

//重载下标访问常量数组
template <typename T>
T Array<T>::operator[](int subscript) const
{
    if (subscript < 0 || subscript > size)
        throw out_of_range("Subscript out of range");

    return ptr[subscript];
}

//重载输入流操作符
template <typename T>
istream &operator>>(istream &input, Array<T> &a)
{
    for (size_t i = 0; i < a.getSize(); i++)
    {
        input >> a[i];
    }

    return input;
}

//  重载输出流操作符
template <typename T>
ostream &operator<<(ostream &output, const Array<T> &a)
{
    for (size_t i = 0; i < a.getSize(); i++)
    {
        output << setw(12) << a[i];

        if ((i + 1) % 4 == 0)
            output << endl;
    }

    if (a.getSize() % 4 != 0)
        output << endl;

    return output;
}
