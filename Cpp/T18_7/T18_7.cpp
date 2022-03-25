#include <iostream>
#include "DoubleSubscriptArray.h"
#include "DoubleSubscriptArray.cpp"
using namespace std;

int main(void)
{
    DoubleSubscriptArray double_array1, double_array2;

    //给double_array1赋值
    for (size_t i = 0; i < double_array1.getFirst_Dimension_Size(); i++)
    {
        for (size_t j = 0; j < double_array1.getSecond_Dimension_Size(); j++)
        {
            double_array1(i, j) = (i + 1) * (j + 1);
        }
    }

    //输入数组
    cin >> double_array2;
    //输出数组
    cout << "double_array1 is:" << endl
         << double_array1 << endl
         << endl
         << "double_array2 is:" << endl
         << double_array2 << endl
         << endl;

    //判断是否相等
    if (double_array1 == double_array2)
        cout << "double_array1 is equal to double_array2" << endl;
    else if (double_array1 != double_array2)
        cout << "double_array1 is not equal to double_array2" << endl;

    //拷贝构造函数与=赋值
    DoubleSubscriptArray double_array3(double_array1);
    DoubleSubscriptArray double_array4;
    double_array4 = double_array2;

    cout << "double_array3 is:" << endl
         << double_array3 << endl
         << endl
         << "double_array4 is:" << endl
         << double_array4 << endl
         << endl;

    // 下面测试演示作为右值使用
    for (size_t i = 0; i < double_array1.getFirst_Dimension_Size(); i++)
    {
        for (size_t j = 0; j < double_array1.getSecond_Dimension_Size(); j++)
        {
            double_array1(i, j) = double_array1(i, j) + double_array2(i, j);
        }
    }

    cout << "The new double_array1 is:" << endl
         << double_array1 << endl;
    //system("pause");
}
