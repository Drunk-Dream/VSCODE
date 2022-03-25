//T18_8
#include <iostream>
#include "Complex.h"
#include"Complex.cpp"
using namespace std;

int main(void)
{
    Complex x;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    cout << "x:" << x << endl
         << "y:" << y << endl
         << "z:" << z << endl;

    x = y + z;
    cout << "\n\nx = y + z:" << x << "=(" << y << ") + (" << z << ")" << endl;

    x = y - z;
    cout << "\n\nx = y - z:" << x << "=(" << y << ") - (" << z << ")" << endl;

    x = y * z;
    cout << "\n\nx = y * z:" << x << "=(" << y << ") * (" << z << ")" << endl;

    cout << endl;
    cin >> x;
    cout << "cin>>x" << endl
         << "x = " << x << endl
         << endl;

    if (y == z)
        cout << "y=z" << endl;
    else if (y != z)
        cout << "y!=z" << endl;

    system("pause");
}