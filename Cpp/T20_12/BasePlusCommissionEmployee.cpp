#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployee.h"
using namespace std;

//constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    const Date &birthDate, double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, birthDate, sales, rate)
{
    setBaseSalary(salary);
}

//set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    if (salary >= 0.0)
        baseSalary_ = salary;
    else
        throw invalid_argument("Salary must be >= 0.0");
}

//return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary_;
}

//calculate earnings
double BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings();
}

//print BasePlusCommissionEmployee's information
void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "; base salary: " << getBaseSalary();
}