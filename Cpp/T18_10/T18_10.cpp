#include <iostream>
#include "RationalNumber.h"
#include"RationalNumber.cpp"
using namespace std;

int main(void)
{
     RationalNumber rat_num1(-3, 6);
     RationalNumber rat_num2(-3, 6);
     cout << "rat_num1=" << rat_num1 << endl
          << "rat_num2=" << rat_num2 << endl;

     RationalNumber rat_num[5];
     rat_num[0] = rat_num1 + rat_num2;
     rat_num[1] = rat_num1 - rat_num2;
     rat_num[2] = rat_num1 * rat_num2;
     rat_num[3] = rat_num1 / rat_num2;
     rat_num[4] = -rat_num1;

     cout << endl
          << "rat_num1 + rat_num2 = " << rat_num[0] << endl
          << "rat_num1 - rat_num2 = " << rat_num[1] << endl
          << "rat_num1 * rat_num2 = " << rat_num[2] << endl
          << "rat_num1 / rat_num2 = " << rat_num[3] << endl
          << "-tat_num1 = " << rat_num[4] << endl;

     cout << endl
          << "rat_num1 < rat_num2 is " << (rat_num1 < rat_num2 ? "true" : "false") << endl
          << "rat_num1 <= rat_num2 is " << (rat_num1 <= rat_num2 ? "true" : "false") << endl
          << "rat_num1 > rat_num2 is " << (rat_num1 > rat_num2 ? "true" : "false") << endl
          << "rat_num1 >= rat_num2 is " << (rat_num1 >= rat_num2 ? "true" : "false") << endl
          << "rat_num1 == rat_num2 is " << (rat_num1 == rat_num2 ? "true" : "false") << endl
          << "rat_num1 != rat_num2 is " << (rat_num1 != rat_num2 ? "true" : "false") << endl;
     system("pause");
}