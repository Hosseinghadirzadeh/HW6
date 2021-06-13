
#ifndef HW6_COMPANY_H
#define HW6_COMPANY_H

#include "Boss.h"
#include "Employee.h"
#include <iostream>

using namespace std;

class Company {
private:
    int budget;
    Boss *boss{};
    Employee **employeeArray;
public:
    Company(int, Boss *, Employee **);

    Company(const Company &);

    virtual ~Company();

    friend ostream &operator<<(ostream &, const Company &);

    friend istream &operator>>(istream &, Company &);

    int getBudget() const;

    void setBudget(int budget);

    Boss *getBoss() const;

    void setBoss(Boss *boss);

    Employee **getEmployeeArray() const;

    void setEmployeeArray(Employee **employeeArray);

    Employee* maxEfficiency();

    double averageEfficiency();

    void ChangeBoss();

    void gift();

};


#endif //HW6_COMPANY_H
