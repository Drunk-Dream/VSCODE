#include "Package.h"
#include <string>
#include <iostream>
using namespace std;

//包含两天交货收取固定费用的类
class TwoDayPackage : public Package //继承包裹类
{
private:
    double fixed_cost_; //对两天交货服务收取的固定费用

public:
    //构造函数，接收除了父类以外还有固定费用作为参数
    TwoDayPackage(string, string, string, string, string,
                  string, string, string, string, string,
                  double, double, double);
    //虚析构函数
    virtual ~TwoDayPackage() {}
    //重载打单函数，除前父类信息外还输出固定费用和总费用
    void print_waybill() const;

    //返回寄件人的地址
    virtual string get_Sender_Address() const;
    //返回收件人的地址
    virtual string get_Recipient_Address() const;
    //计算运输所需要的费用，包括运输费用及两天交货的固定费用
    virtual double calculateCost() const;
};

TwoDayPackage::TwoDayPackage(
    string sender_name, string sender_address, string sender_city, string sender_state, string sender_postcode,
    string recipient_name, string recipient_address, string recipient_city, string recipient_state, string recipient_postcode,
    double package_quality, double package_cost, double fixed_cost)
    : Package(sender_name, sender_address, sender_city, sender_state, sender_postcode,
              recipient_name, recipient_address, recipient_city, recipient_state, recipient_postcode,
              package_quality, package_cost),
      fixed_cost_(fixed_cost)
{
}

void TwoDayPackage::print_waybill() const
{
    Package::print_waybill();
    cout
        << "Fixed cost:" << fixed_cost_ << endl
        << "Total cost:" << calculateCost() << endl;
}

//返回寄件人的地址
string TwoDayPackage::get_Sender_Address() const
{
    return Package::get_Sender_Address();
}

//返回收件人的地址
string TwoDayPackage::get_Recipient_Address() const
{
    return Package::get_Recipient_Address();
}

//计算运输所需要的费用，包括运输费用及两天交货的固定费用
double TwoDayPackage::calculateCost() const
{
    return Package::calculateCost() + fixed_cost_;
}