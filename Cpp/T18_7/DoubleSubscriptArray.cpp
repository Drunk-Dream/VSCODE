#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "DoubleSubscriptArray.h"
using namespace std;

//初始化构造函数，缺省值为1,1
DoubleSubscriptArray::DoubleSubscriptArray(int i, int j)
    : i_(i > 0 ? i : throw invalid_argument("Array size must be greater than 0")),
      j_(j > 0 ? j : throw invalid_argument("Array size must be greater than 0"))
{
    array = new int *[i_];
    for (int i = 0; i < i_; i++)
    {
        array[i] = new int[j_];
    }
}

//拷贝构造函数
DoubleSubscriptArray::DoubleSubscriptArray(const DoubleSubscriptArray &another)
    : i_(another.i_),
      j_(another.j_)
{
    array = new int *[i_];
    for (int i = 0; i < i_; i++)
    {
        array[i] = new int[j_];
    }

    for (size_t i = 0; i < i_; i++)
    {
        for (size_t j = 0; j < j_; j++)
        {
            array[i][j] = another.array[i][j];
        }
    }
}

//析构函数
DoubleSubscriptArray::~DoubleSubscriptArray()
{
    for (size_t i = 0; i < i_; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

//获取数组的大小
int DoubleSubscriptArray::getFirst_Dimension_Size() const
{
    return i_;
}

int DoubleSubscriptArray::getSecond_Dimension_Size() const
{
    return j_;
}

//重载圆括号，作为左值使用
int &DoubleSubscriptArray::operator()(int i, int j)
{
    //检查下标是否满足条件
    if (i < 0 || i > i_ || j < 0 || j > j_)
        throw out_of_range("Subscript out of range");
    return array[i][j];
}

//重载圆括号，作为右值使用
const int &DoubleSubscriptArray::operator()(int i, int j) const
{
    //检查下标
    if (i < 0 || i > i_ || j < 0 || j > j_)
        throw out_of_range("Subscript out of range");

    return array[i][j];
}

//重载==，判断两个数组是否相等
bool DoubleSubscriptArray::operator==(const DoubleSubscriptArray &right) const
{
    if (i_ != right.i_ || j_ != right.j_)
        return false;

    for (size_t i = 0; i < i_; i++)
    {
        for (size_t j = 0; j < j_; j++)
        {
            if (array[i][j] != right.array[i][j])
                return false;
        }
    }

    return true;
}

//重载!=,判断两个二维数组是否不等
bool DoubleSubscriptArray::operator!=(const DoubleSubscriptArray &right) const
{
    return !(*this == right);
}

//重构=，给二维数组赋值
//const return avoid:(a1 = a2)=a3
const DoubleSubscriptArray &DoubleSubscriptArray::operator=(const DoubleSubscriptArray &right)
{
    if (&right != this) //avoid self-assignment
    {
        //如果数组的大小不相等，则重新给左侧数组分配空间
        if (i_ != right.i_ || j_ != right.j_)
        {
            //释放空间
            for (size_t i = 0; i < i_; i++)
            {
                delete[] array[i];
            }
            delete[] array;

            i_ = right.i_;
            j_ = right.j_;

            //重新分配空间
            array = new int *[i_];
            for (size_t i = 0; i < i_; i++)
            {
                array[i] = new int[j_];
            }
        }

        for (size_t i = 0; i < i_; i++)
        {
            for (size_t j = 0; j < j_; j++)
                array[i][j] = right.array[i][j];
        }
    }

    return *this;
}

ostream &operator<<(ostream &output, const DoubleSubscriptArray &a)
{
    for (size_t i = 0; i < a.i_; i++)
    {
        for (size_t j = 0; j < a.j_; j++)
        {
            output << setw(4) << left << a.array[i][j];
        }
        output << endl;
    }
    return output;
}

istream &operator>>(istream &input, DoubleSubscriptArray &a)
{
    for (size_t i = 0; i < a.i_; i++)
    {
        for (size_t j = 0; j < a.j_; j++)
        {
            input >> a.array[i][j];
        }
    }

    return input;
}