#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

//constructor
Employee::Employee(const string &first, const string &last,
                   const string &ssn, const Date &birthDate)
    : firstName_(first), lastName_(last), SocialSecurityNumber_(ssn), birthDate_(birthDate)
{
}

//set first name
void Employee::setFirstName(const string &first)
{
    firstName_ = first;
}

//return first name
string Employee::getFirstName() const
{
    return firstName_;
}

//set last name
void Employee::setLastname(const string &last)
{
    lastName_ = last;
}

//get last name
string Employee::getLastName() const
{
    return lastName_;
}

//set social security number
void Employee::setSocialSecurityNumber(const string &ssn)
{
    SocialSecurityNumber_ = ssn;
}

//return social security number
string Employee::getSocialSecurityNumber() const
{
    return SocialSecurityNumber_;
}

//print Employee's information
void Employee::print() const
{
    cout << getFirstName() << ' ' << getLastName() << "\nsocial security number: " << getSocialSecurityNumber();
}

//返回生日
Date Employee::getBirthDate() const
{
    return birthDate_;
}