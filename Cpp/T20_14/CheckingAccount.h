#ifndef _CHECKINGACCOUNT_H
#define _CHECKINGACCOUNT_H
#include <iostream>
#include "Account.h"
using namespace std;

class CheckingAccount : public Account
{
private:
    double each_transaction_fees_; //每次交易收取的费用
public:
    //构造函数,接收初始余额和表示费用的形参
    CheckingAccount(double = 0.0, double = 0.0);
    //重定义credit函数，当存款成功时，扣除相应的费用
    virtual void credit(double);
    //重定义debit函数，当取款成功时，扣除相应的费用
    virtual bool debit(double);

    virtual double calculateInterest() const;
};

//构造函数，接收余额与每次交易费用
CheckingAccount::CheckingAccount(double balance, double each_transaction_fees)
    : Account(balance)
{
    if (each_transaction_fees >= 0)
    {
        each_transaction_fees_ = each_transaction_fees;
    }
    else
    {
        cerr << "Charges should be positive." << endl;
    }
}

void CheckingAccount::credit(double to_deposit_money)
{
    Account::credit(to_deposit_money);  //存款进账户
    balance_ -= each_transaction_fees_; //然后扣除相应的费用
}

bool CheckingAccount::debit(double to_draw_money)
{
    bool withdrawals_success = Account::debit(to_draw_money); //从账户中取款
    if (withdrawals_success)                                  //如果取款成功
    {
        balance_ -= each_transaction_fees_;                             //扣除对应的费用
        cout << each_transaction_fees_ << " has been deducted" << endl; //显示已经扣除服务费用
    }
    else //否则不扣除余额并返回错误信息
    {
        cerr << "Failed to deduct expenses" << endl;
    }
    return withdrawals_success;
}

double CheckingAccount::calculateInterest() const
{
    return 0;
}
#endif