
#include "Company.h"

Company::Company(int budget, Boss *boss, Employee **array) {
    this->budget = budget;
    this->boss = new Boss(*boss);
    employeeArray = new Employee *[boss->getNumberOfEmployees()];
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        employeeArray[i] = new Employee(*array[i]);
    }

}

Company::Company(const Company &c) {
    budget = c.budget;
    boss = new Boss;
    employeeArray = new Employee *[boss->getNumberOfEmployees()];
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        employeeArray[i] = new Employee(*(c.employeeArray[i]));
    }

}

Company::~Company() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i)
        delete employeeArray[i];
    delete employeeArray;
}

ostream &operator<<(ostream &os, Company &c1) {
    Company c = c1;
    for (int i = 0; i < c.boss->getNumberOfEmployees() - 1; ++i) {
        for (int j = c.boss->getNumberOfEmployees() - 1; i < j; ++j) {
            if (c.employeeArray[j]->getId().substr(0, 2) < c.employeeArray[j - 1]->getId().substr(0, 2)) {
                swap(c.employeeArray[j], c.employeeArray[j - 1]);
            }
            if (c.employeeArray[j]->getId().substr(0, 2) == c.employeeArray[j - 1]->getId().substr(0, 2)) {
                for (int k = 0; k < c.boss->getNumberOfEmployees() - 1; ++k) {
                    for (int l = c.boss->getNumberOfEmployees() - 1; k < l; ++l) {
                        if (c.employeeArray[l]->getName() < c.employeeArray[l - 1]->getName())
                            swap(c.employeeArray[j], c.employeeArray[j - 1]);
                    }
                }


            }
        }

    }


    return os;
}

int Company::getBudget() const {
    return budget;
}

void Company::setBudget(int budget) {
    Company::budget = budget;
}

Boss *Company::getBoss() const {
    return boss;
}

void Company::setBoss(Boss *boss) {
    Company::boss = boss;
}

Employee **Company::getEmployeeArray() const {
    return employeeArray;
}

void Company::setEmployeeArray(Employee **employeeArray) {
    Company::employeeArray = employeeArray;
}

istream &operator>>(istream & in, Company &c) {
    in >> c.budget;
    in >> *c.boss;
    for (int i = 0; i < c.boss->getNumberOfEmployees(); ++i) {
        in >> *c.employeeArray[i];
    }
    return in;
}


