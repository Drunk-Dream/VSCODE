#ifndef _BASEPLUSCOMMISSIONEMPLOYEE_H
#define _BASEPLUSCOMMISSIONEMPLOYEE_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &, const std::string &,
                               const Date &, double = 0.0, double = 0.0, double = 0.0);
    //virtual destructor
    virtual ~BasePlusCommissionEmployee() {}

    //set base salary
    void setBaseSalary(double);
    //return base salary
    double getBaseSalary() const;

    //calculate earnings
    virtual double earnings() const;
    //print object
    virtual void print() const;

private:
    //base salary per week
    double baseSalary_;
};

#endif