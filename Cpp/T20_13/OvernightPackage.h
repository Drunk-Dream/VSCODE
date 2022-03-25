#include <iostream>
#include <string>
#include "Package.h"
using namespace std;

//包含隔夜交货服务每盎司收取的费用
class OvernightPackage : public Package
{
private:
    double overnight_cost_; //隔夜交货服务每盎司收取饿额外费用

public:
    //构造函数，除了父类参数，还接收一个隔夜交货服务每盎司额外收取的费用
    OvernightPackage(string, string, string, string, string,
                     string, string, string, string, string,
                     double, double, double);
    //虚析构函数
    virtual ~OvernightPackage(){}
    //重载calculateCost函数，在计算运输费用前，将每盎司收取的额外费用加到每盎司的固定费用上
    // double calculateCost() const;

    //重载打单函数，除了父类信息外还输出每盎司收取的额外费用和总费用
    void print_waybill() const;
    //返回寄件人地址
    virtual string get_Sender_Address() const;
    //返回收件人地址
    virtual string get_Recipient_Address() const;
    //返回运输所需要的费用，在计算费用前，将每盎司收取的额外费用加到每盎司的固定费用前
    virtual double calculateCost() const;
};

OvernightPackage::OvernightPackage(
    string sender_name, string sender_address, string sender_city, string sender_state, string sender_postcode,
    string recipient_name, string recipient_address, string recipient_city, string recipient_state, string recipient_postcode,
    double package_quality, double package_cost, double overnight_cost)
    : Package(sender_name, sender_address, sender_city, sender_state, sender_postcode,
              recipient_name, recipient_address, recipient_city, recipient_state, recipient_postcode,
              package_quality, package_cost),
      overnight_cost_(overnight_cost)
{
}

// double OvernightPackage::calculateCost() const
// {
//     return (package_cost_ + overnight_cost_) * package_quality_;
// }

void OvernightPackage::print_waybill() const
{
    Package::print_waybill();
    cout
        << "Cost per ounce:" << overnight_cost_ << endl
        << "Total cost:" << OvernightPackage::calculateCost() << endl;
}

//返回寄件人地址
string OvernightPackage::get_Sender_Address() const
{
    return Package::get_Sender_Address();
}

//返回收件人地址
string OvernightPackage::get_Recipient_Address() const
{
    return Package::get_Recipient_Address();
}

//返回运输所需要的费用，在计算费用前，将每盎司收取的额外费用加到每盎司的固定费用前
double OvernightPackage::calculateCost() const
{
    return (package_cost_ + overnight_cost_) * package_quality_;
}