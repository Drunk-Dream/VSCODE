//T20_14
//计算两种账户的存款，并且返回余额
#include <iostream>
#include <vector>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

//打印存储账户二级菜单
void PrintAccount(Account &, double);
//打印一级菜单
void PrintMenu();
//操作存储账户
void OperatingAccount(Account &, double);

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

    vector<Account *> account(2);

    account[0] = &savingsaccount;
    account[1] = &checkingaccount;

    int choice;
    while (true)
    {
        PrintMenu();
        cin >> choice;
        if (choice == 1)
        {
            OperatingAccount(*account[0], interest_rate);
        }
        else if (choice == 2)
        {
            OperatingAccount(*account[1], service_fee);
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

void PrintAccount(Account &saving, double rate)
{
    cout
        << "Balance: " << saving.getBalance() << endl
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

void OperatingAccount(Account &account, double rate)
{
    int choice;
    while (true)
    {
        PrintAccount(account, rate); //将账户和菜单打印出来
        cin >> choice;
        if (choice == 1)
        {
            double to_deposit_money;
            cout << "Please enter your deposit:";
            cin >> to_deposit_money;
            account.credit(to_deposit_money);
        }
        else if (choice == 2)
        {
            double to_draw_money;
            cout << "Please enter your draw:";
            cin >> to_draw_money;
            account.debit(to_draw_money);
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