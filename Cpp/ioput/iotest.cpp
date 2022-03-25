#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << 180.2 << endl;
    cout << showpoint << 180.2 << endl;
    cout.fill('*');
    cout << setw(10) << 180 << endl;
    cout.fill(' ');
    cout << setw(10) << 180 << endl;
    cout << setprecision(3) << 213.1 << endl;
    cout << noshowpoint;
    cout << true << false << endl;
    cout << boolalpha << false << true << endl;
    cout << hex << 18 << ":" << dec << 18 << endl;
    cout << oct << 18 << ":" << dec << 18 << endl;
    system("pause");
}