//T23_3
#include <iostream>
using namespace std;
//定义一个函数模板，判断两个同类型的输入是否相等
template <typename T>
bool isEqualTo(T &a, T &b)
{
    return a == b;
}

int main()
{
    int a_int = 1, b_int = 2;
    double a_double = 0.1, b_double = 0.1;
    unsigned int a_unint = 10, b_unint = 10;

    cout << boolalpha;
    cout
        << a_int << " = " << b_int << " is " << isEqualTo(a_int, b_int) << endl
        << a_double << " = " << b_double << " is " << isEqualTo(a_double, b_double) << endl
        << a_unint << " = " << b_unint << " is " << isEqualTo(a_unint, b_unint) << endl;
    system("pause");
}