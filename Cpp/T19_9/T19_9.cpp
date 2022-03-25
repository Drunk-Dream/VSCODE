//T19_9
//测试TwoDayPackage和OvernightPackage两个之类
#include <iostream>
#include <string>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
using namespace std;

int main()
{
    //创建子类所需要的所有变量
    string sender_name, sender_address, sender_city, sender_state, sender_postcode,
        recipient_name, recipient_address, recipient_city, recipient_state, recipient_postcode;
    double package_quality, package_cost, fixed_cost, overnight_cost;

    //输入寄件人和收件人的信息
    cout << "Sender name:";
    cin >> sender_name;
    cout << "Sender address:";
    cin >> sender_address;
    cout << "Sender city:";
    cin >> sender_city;
    cout << "Sender state:";
    cin >> sender_state;
    cout << "Sender postcode:";
    cin >> sender_postcode;
    cout << "Recipient name:";
    cin >> recipient_name;
    cout << "Recipient address:";
    cin >> recipient_address;
    cout << "Recipient city:";
    cin >> recipient_city;
    cout << "Recipient state:";
    cin >> recipient_state;
    cout << "Recipient postcode:";
    cin >> recipient_postcode;

    //输入包裹信息
    cout << "Package quality:";
    cin >> package_quality;
    cout << "Package cost:";
    cin >> package_cost;
    cout << "Fixed cost:";
    cin >> fixed_cost;
    cout << "Overnight cost:";
    cin >> overnight_cost;
    cout << endl;

    TwoDayPackage package1(
        sender_name, sender_address, sender_city, sender_state, sender_postcode,
        recipient_name, recipient_address, recipient_city, recipient_state, recipient_postcode,
        package_quality, package_cost, fixed_cost);
    OvernightPackage package2(
        sender_name, sender_address, sender_city, sender_state, sender_postcode,
        recipient_name, recipient_address, recipient_city, recipient_state, recipient_postcode,
        package_quality, package_cost, overnight_cost);

    package1.print_waybill();
    cout << endl;
    package2.print_waybill();
    system("pause");
}