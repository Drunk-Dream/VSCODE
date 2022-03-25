#ifndef _SAVINGSACCOUNT_H
#define _SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"
using namespace std;

class SavingsAccount : public Account
{
private:
    double interest_rate_; //表示Account的利率
public:
    //构造函数，初始化账户余额和利率
    SavingsAccount(double = 0.0, double = 0.0);
    //返回账户获得的利息数目
    double calculateInterest() const;
};

SavingsAccount::SavingsAccount(double balance, double interest_rate)
    : Account(balance)
{
    if (interest_rate >= 0)
    {
        interest_rate_ = interest_rate;
    }
    else
    {
        cerr << "Interest rate should be greater than 0." << endl;
    }
}

double SavingsAccount::calculateInterest() const
{
    return SavingsAccount::getBalance() * interest_rate_;
}

#endif