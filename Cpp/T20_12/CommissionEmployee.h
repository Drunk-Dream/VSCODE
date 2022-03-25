#ifndef _COMMISSIONEMPLOYEE_H
#define _COMMISSIONEMPLOYEE_H

#include <string>
#include "Employee.h"

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const std::string &, const std::string &, const std::string &, const Date &, double = 0.0, double = 0.0);
    //virtual destructor
    virtual ~CommissionEmployee(){};

    //set commission rate
    void setCommissionRate(double);
    //return commission rate
    double getCommissionRate() const;

    //set gross sales amount
    void setGrossSales(double = 0.0);
    //return gross sales amount
    double getGrossSales() const;

    //calculate earnings
    virtual double earnings() const;
    //print object
    virtual void print() const;

private:
    //gross weekly sales
    double grossSales_;
    //commission percentage
    double commissionRate_;
};

#endif