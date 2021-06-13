
#ifndef HW6_BOSS_H
#define HW6_BOSS_H

#include "Employee.h"
#include <iostream>

using namespace std;

class Boss : public Employee {
private:
    int numberOfEmployees;
public:
    int getNumberOfEmployees() const;

    void setNumberOfEmployees(int numberOfEmployees);

    Boss(int, int, int, int, int, string, string, Address);

    Boss();

    Boss(const Boss &);

    friend ostream &operator<<(ostream &os, const Boss &boss);

    friend istream &operator>>(istream &, Boss &);

    Boss &operator=(const Boss &);

    double calculateSalary() const;


};


#endif //HW6_BOSS_H
