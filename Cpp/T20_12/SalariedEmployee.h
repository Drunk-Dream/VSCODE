#ifndef _SALARIEDEMPLOYEE_H
#define _SALARIEDEMPLOYEE_H

#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const std::string &, const std::string &, const std::string &, const Date &, double = 0.0);
    //virtual destructor
    virtual ~SalariedEmployee() {}

    //set weekly salary
    void setWeeklySalary(double);
    //return weekly salary
    double getWeeklySalary() const;

    //calculate earnings
    virtual double earnings() const;
    //print boject
    virtual void print() const;

private:
    double weeklySalary_;
};

#endif