#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>
#include "Date.h"

class Employee
{
public:
    //构造函数，接收四个字符串的引用
    Employee(const std::string &, const std::string &, const std::string &, const Date &);
    virtual ~Employee() {}

    //set first name
    void setFirstName(const std::string &);
    //return first name
    std::string getFirstName() const;

    //set last name
    void setLastname(const std::string &);
    //return last name
    std::string getLastName() const;

    //set SSN
    void setSocialSecurityNumber(const std::string &);
    //return SSN
    std::string getSocialSecurityNumber() const;
    //返回生日
    Date getBirthDate() const;
    //pure virtual function makes Employee an abstract base class

    //pure virtual
    virtual double earnings() const = 0;
    //virtual
    virtual void print() const;

private:
    std::string firstName_;
    std::string lastName_;
    std::string SocialSecurityNumber_;
    Date birthDate_;
};

#endif