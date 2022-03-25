//T23_4
#include <iostream>
#include "Array.h"
#include "Array.cpp"
using namespace std;

#include <iomanip>
#include <stdexcept>

int main()
{
     Array<int> array_int(8);
     Array<double> array_double(8);
     Array<char> array_char(8);

     cout << "Enter the array_int: " << endl;
     cin >> array_int;

     cout << "Enter the array_double: " << endl;
     cin >> array_double;

     cout << "Enter the array_char: " << endl;
     cin >> array_char;

     cout << array_int << endl
          << endl;
     cout << array_double << endl
          << endl;
     cout << array_char << endl
          << endl;

     system("pause");
}