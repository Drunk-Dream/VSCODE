//Package作为基类
#ifndef _PACKAGE_H
#define _PACKAGE_H
#include <string>
#include <iostream>
using namespace std;

class Package
{
private:
    string sender_name_;        //寄件人姓名
    string sender_address_;     //寄件人地址
    string sender_city_;        //寄件人城市
    string sender_state_;       //寄件人州
    string sender_postcode_;    //寄件人邮编
    string recipient_name_;     //收件人姓名
    string recipient_address_;  //收件人地址
    string recipient_city_;     //收件人城市
    string recipient_state_;    //收件人州
    string recipient_postcode_; //收件人邮编

protected:
    double package_quality_; //包裹的质量，单位为盎司
    double package_cost_;    //每盎司的费用

public:
    //构造函数
    Package(string, string, string, string, string,
            string, string, string, string, string,
            double, double);
    //返回传递这个包裹的费用
    double calculateCost() const;
    //将快递运单打印出来
    void print_waybill() const;
};

//构造函数
Package::Package(string sender_name, string sender_address, string sender_city, string sender_state, string sender_postcode,
                 string recipient_name, string recipient_address, string recipient_city, string recipient_state, string recipient_postcode,
                 double package_quality, double package_cost)
    : sender_name_(sender_name), sender_address_(sender_address), sender_city_(sender_city), sender_state_(sender_state), sender_postcode_(sender_postcode),
      recipient_name_(recipient_name), recipient_address_(recipient_address), recipient_city_(recipient_city), recipient_state_(recipient_state), recipient_postcode_(recipient_postcode),
      package_quality_(package_quality > 0 ? package_quality : throw("Quality should be a positive number.")), package_cost_(package_cost > 0 ? package_cost : throw("Cost should be a positive number"))
{
}

//返回传递该包裹需要的费用
double Package::calculateCost() const
{
    return package_quality_ * package_cost_;
}

//将快递运单打印出来
void Package::print_waybill() const
{
    cout
        << "Sender name:" << sender_name_ << endl
        << "Sender address:" << sender_address_ << endl
        << "Sender city:" << sender_city_ << endl
        << "Sender state" << sender_state_ << endl
        << "Sender postcode:" << sender_postcode_ << endl
        << "Recipient name:" << recipient_name_ << endl
        << "Recipient address:" << recipient_address_ << endl
        << "Recipient city:" << sender_city_ << endl
        << "Recipient state:" << sender_postcode_ << endl
        << "Recipient postcode:" << recipient_postcode_ << endl
        << "Quality:" << package_quality_ << " ounce" << endl
        << "Cost per ounce:" << package_cost_ << endl
        << "Transport cost:" << Package::calculateCost() << endl;
}

#endif