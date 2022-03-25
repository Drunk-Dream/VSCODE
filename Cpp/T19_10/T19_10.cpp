//T19_10
#include <iostream>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

//打印存储账户二级菜单
void PrintAccount(SavingsAccount &, double);
//打印支票账户二级菜单
void PrintAccount(CheckingAccount &, double);
//打印一级菜单
void PrintMenu();
//操作存储账户
void OperatingAccount(SavingsAccount &, double);
//操作支票账户
void OperatingAccount(CheckingAccount &, double);

int main()
{
    //声明账户余额，利率和支票服务费用
    double balance, interest_rate, service_fee;
    cout << "Balance:";
    cin >> balance;
    cout << "Interest Rate:";
    cin >> interest_rate;
    cout << "Service Fee:";
    cin >> service_fee;

    //分别创建两个类来测试
    SavingsAccount savingsaccount(balance, interest_rate);
    CheckingAccount checkingaccount(balance, service_fee);

    int choice;
    while (true)
    {
        PrintMenu();
        cin >> choice;
        if (choice == 1)
        {
            OperatingAccount(savingsaccount,interest_rate);
        }
        else if(choice==2)
        {
            OperatingAccount(checkingaccount,service_fee);
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            cerr << "Invalid input" << endl;
        }
    }
}

void PrintAccount(SavingsAccount &saving, double rate)
{
    cout
        << "Balance: " << saving.getBalance() << endl
        << "Rate:" << rate << endl
        << "Interest:" << saving.calculateInterest() << endl
        << endl
        << "1.credit" << endl
        << "2.debit" << endl
        << "3.exit" << endl;
}

void PrintAccount(CheckingAccount &check, double fee)
{
    cout
        << "Balance:" << check.getBalance() << endl
        << "Service fee:" << fee << endl
        << endl
        << "1.credit" << endl
        << "2.debit" << endl
        << "3.exit" << endl;
}

void PrintMenu()
{
    cout
        << "1.SavingsAccount" << endl
        << "2.CheckingAccount" << endl
        << "3.exit" << endl;
}

void OperatingAccount(SavingsAccount &saving, double rate)
{
    int choice;
    while (true)
    {
        PrintAccount(saving, rate); //将账户和菜单打印出来
        cin >> choice;
        if (choice == 1)
        {
            double to_deposit_money;
            cout << "Please enter your deposit:";
            cin >> to_deposit_money;
            saving.credit(to_deposit_money);
        }
        else if (choice == 2)
        {
            double to_draw_money;
            cout << "Please enter your draw:";
            cin >> to_draw_money;
            saving.debit(to_draw_money);
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cerr << "Invalid input" << endl;
        }
    }
}

void OperatingAccount(CheckingAccount &saving, double rate)
{
    int choice;
    while (true)
    {
        PrintAccount(saving, rate); //将账户和菜单打印出来
        cin >> choice;
        if (choice == 1)
        {
            double to_deposit_money;
            cout << "Please enter your deposit:";
            cin >> to_deposit_money;
            saving.credit(to_deposit_money);
        }
        else if (choice == 2)
        {
            double to_draw_money;
            cout << "Please enter your draw:";
            cin >> to_draw_money;
            saving.debit(to_draw_money);
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cerr << "Invalid input" << endl;
        }
    }
}