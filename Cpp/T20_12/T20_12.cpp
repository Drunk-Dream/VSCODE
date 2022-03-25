#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "Date.cpp"
#include "Employee.cpp"
#include "SalariedEmployee.cpp"
#include "CommissionEmployee.cpp"
#include "BasePlusCommissionEmployee.cpp"
using namespace std;

void virtualViaPointer(const Employee *const, Date &);
void virtualViaReference(const Employee &, Date &);

int main()
{
    cout << fixed << setprecision(2);

    Date birthDate[3] = {Date(2, 1, 2021),
                         Date(4, 1, 2021),
                         Date(6, 1, 2021)};
    Date currentDate(4, 1, 2021);

    SalariedEmployee salariedEmployee(
        "A", "a", "001", birthDate[0], 800);
    CommissionEmployee commissionEmployee(
        "B", "b", "002", birthDate[1], 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "C", "c", "003", birthDate[2], 5000, .04, 300);

    salariedEmployee.print();
    if (salariedEmployee.getBirthDate().getMonth() == currentDate.getMonth())
        cout << "\nearned $" << salariedEmployee.earnings() + 100 << "\n\n";
    else
        cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    if (basePlusCommissionEmployee.getBirthDate().getMonth() == currentDate.getMonth())
        cout << "\nearned $" << basePlusCommissionEmployee.earnings() + 100 << "\n\n";
    else
        cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

    //create vector of three base_class pointers
    vector<Employee *> employees(3);

    //initialize vector with pointers to Employees
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;

    cout << "Employees processed polymorphically via dynamic binding:\n\n";

    cout << "Virtual function calls made off base-class pointers:\n\n";

    for (int i = 0; i < 3; i++)
        virtualViaPointer(employees[i], currentDate);

    cout << "Virtual function calls made off base-class references:\n\n";

    for (int i = 0; i < 3; i++)
        virtualViaReference(*employees[i], currentDate);

    system("pause");
}

void virtualViaPointer(const Employee *const baseClassPtr, Date &currentDate)
{
    baseClassPtr->print();
    if (baseClassPtr->getBirthDate().getMonth() == currentDate.getMonth())
        cout << "\nearned $" << baseClassPtr->earnings() + 100 << "\n\n";
    else
        cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

void virtualViaReference(const Employee &baseClassRef, Date &currentDate)
{
    baseClassRef.print();
    if (baseClassRef.getBirthDate().getMonth() == currentDate.getMonth())
        cout << "\nearned $" << baseClassRef.earnings() + 100 << "\n\n";
    else
        cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
}