#ifndef _DOUBLESUBSCRIPTARRAY_H
#define _DOUBLESUBSCRIPTARRAY_H
#include<iostream>

class DoubleSubscriptArray
{
private:
    int **array;
    int i_, j_;

public:
    //构造函数，为二维数组提供初始值
    explicit DoubleSubscriptArray(int = 3, int = 3);
    //构造函数，可以用来将另一个二维数组复制给新数组
    DoubleSubscriptArray(const DoubleSubscriptArray &);
    //析构函数
    ~DoubleSubscriptArray();
    //获取数组第一维度的大小
    int getFirst_Dimension_Size() const;
    //获取数组第二维度的大小
    int getSecond_Dimension_Size() const;

    //重构（）圆括号，作为左值使用
    int &operator()(int, int);
    //重构（）圆括号，作为右值使用
    const int &operator()(int, int) const;
    //重构==，判断两个二维数组是否相等
    bool operator==(const DoubleSubscriptArray &) const;
    //重构!=,判断两个二位数组是否不等
    bool operator!=(const DoubleSubscriptArray &) const;
    //重构=，给二维数组赋值
    const DoubleSubscriptArray &operator=(const DoubleSubscriptArray &);
    //重构<<输出操作符，用于以行和列的形式输出数组
    friend std::ostream &operator<<(std::ostream &out, const DoubleSubscriptArray &);
    //重构>>输入操作符，用于输入整个数组的内容
    friend std::istream &operator>>(std::istream &in, DoubleSubscriptArray &);
};

#endif