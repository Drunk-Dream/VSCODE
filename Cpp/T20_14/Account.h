#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <iostream>
using namespace std;

class Account
{
protected:
    double balance_; //账户余额
public:
    //构造函数
    Account(double = 0.0);
    //向当前余额增加存款
    virtual void credit(double);
    //从Account中取款
    virtual bool debit(double);
    //计算储蓄账户中的利息
    virtual double calculateInterest() const = 0;
    //返回当前余额
    double getBalance() const;
};

//构造函数
Account::Account(double balance)
{
    if (balance >= 0.0)
    {
        balance_ = balance;
    }
    else
    {
        balance_ = 0.0;
        cerr << "Invalid balance，Has been set to 0." << endl;
    }
}

//向当前余额增加存款
void Account::credit(double to_deposit_money)
{
    if (to_deposit_money >= 0.0)
    {
        balance_ += to_deposit_money;
    }
    else
    {
        cerr << "Invalid deposit." << endl;
    }
}

//从Account中取款
bool Account::debit(double to_draw_money)
{
    if (to_draw_money >= 0.0 && to_draw_money <= balance_)
    {
        balance_ -= to_draw_money;
        return true;
    }
    else if (to_draw_money > balance_)
    {
        cerr << "Debit amount exceeded account balance." << endl;
        return false;
    }
    else
    {
        cerr << "Withdrawal should be greater than 0." << endl;
        return false;
    }
}

//返回当前余额
double Account::getBalance() const
{
    return balance_;
}

#endif