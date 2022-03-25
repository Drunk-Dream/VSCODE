#include <iostream>
#include <stdexcept>
#include "CommissionEmployee.h"
using namespace std;

//constructor
CommissionEmployee::CommissionEmployee(const std::string &first, const std::string &last,
                                       const std::string &snn, const Date &birthDate, double sales, double rate)
    : Employee(first, last, snn, birthDate)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}

//set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
    if (sales >= 0.0)
        grossSales_ = sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
}

//return gross sales amount
double CommissionEmployee::getGrossSales() const
{
    return grossSales_;
}

//set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
    if (rate > 0.0 && rate < 1.0)
        commissionRate_ = rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

//return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate_;
}

//calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
}

//print commissionEmployee's information
void CommissionEmployee::print() const
{
    cout << "commission employee: ";
    Employee::print(); //code reuse
    cout << "\ngross sales: " << getGrossSales()
         << "; commission rate: " << getCommissionRate();
}