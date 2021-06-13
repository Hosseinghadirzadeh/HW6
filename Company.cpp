
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

ostream &operator<<(ostream &os, const Company &company) {
    Company temp = company;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < temp.boss->getNumberOfEmployees() - 1; ++i) {
            if (temp.getEmployeeArray()[i]->getName() > temp.employeeArray[i + 1]->getName()) {
                std::swap(temp.employeeArray[i], temp.employeeArray[i + 1]);
                flag = true;
            }
        }
    }
    flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < temp.boss->getNumberOfEmployees() - 1; ++i) {
            if (temp.employeeArray[i]->getId().substr(0, 2) < temp.employeeArray[i + 1]->getId().substr(0, 2)) {
                std::swap(temp.employeeArray[i], temp.employeeArray[i + 1]);
                flag = true;
            }
        }
    }
    os << *(temp.boss) << std::endl << std::endl;
    for (int i = 0; i < temp.boss->getNumberOfEmployees(); ++i) {
        os << *(temp.employeeArray[i]) << std::endl << temp.employeeArray[i]->efficiency() << std::endl << std::endl;

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

Employee Company::maxEfficiency() {
    Employee *temp = employeeArray[0];
    for (int i = 1; i < boss->getNumberOfEmployees(); ++i) {
        if (employeeArray[i]->efficiency() > temp->efficiency()) {
            temp = new Employee(*employeeArray[i]);
        }
    }
    return *temp;
}

double Company::averageEfficiency() {
double sum=0;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i)
        sum+=(employeeArray[i]->efficiency());
    return sum/boss->getNumberOfEmployees();
}


