//
// Created by Hossein on 6/13/2021.
//

#include "Employee.h"

Employee::Employee() : Person() {}

Employee::Employee(int hw, int sph, int wtd, int wd, string name, string id, Address address) : Person(name, id,
                                                                                                       address),
                                                                                                hourWork(hw),
                                                                                                salaryPerHour(sph),
                                                                                                workToDo(wtd),
                                                                                                workDone(wd) {
}

Employee::Employee(const Employee &employee) : Person(employee) {
    hourWork = employee.hourWork;
    salaryPerHour = employee.salaryPerHour;
    workToDo = employee.workToDo;
    workDone = employee.workDone;
    if(!validate())
    {cout<<"invalid id";
        return;
    }

}

int Employee::getHourWork() const {
    return hourWork;
}

void Employee::setHourWork(int hourWork) {
    Employee::hourWork = hourWork;
}

int Employee::getSalaryPerHour() const {
    return salaryPerHour;
}

void Employee::setSalaryPerHour(int salaryPerHour) {
    Employee::salaryPerHour = salaryPerHour;
}

int Employee::getWorkToDo() const {
    return workToDo;
}

void Employee::setWorkToDo(int workToDo) {
    Employee::workToDo = workToDo;
}

int Employee::getWorkDone() const {
    return workDone;
}

void Employee::setWorkDone(int workDone) {
    Employee::workDone = workDone;
}

ostream &operator<<(ostream &out, Employee &e) {
    out << "Name: " << e.getName() << endl << "ID: " << e.getId() << endl << "Address:" << e.getAddress() << endl;
    out << "hour Work: " << e.hourWork << endl << "salary perHour: " << e.salaryPerHour << endl << "work to Do: "
        << e.workToDo << endl << "work done" << e.workDone;
    return out;
}

istream &operator>>(istream &in, Employee &e) {
    cout << "hourWork-salaryPerHour-workToDo-workDone: " << endl;
    in >> e.hourWork >> e.salaryPerHour >> e.workToDo >> e.workDone >> static_cast<Person &>(e);

    return in;
}

Employee &Employee::operator=(const Employee &e) {

    Person::operator=(e);
    hourWork = e.hourWork;
    salaryPerHour = e.salaryPerHour;
    workToDo = e.workToDo;
    workDone = e.workDone;

    return *this;
}

bool Employee::validate() {

    if (getId().length() < 8 || getId().length() > 10)
        return false;
    string sal = getId().substr(0, 2);

    if (stoi(sal) < 84 || stoi(sal) > 99)
        return false;

    if (getId().length() == 8) {

        if (getId()[2] != '*')
            return false;
    }
    for (int i = 3; i < 8; ++i) {
        if (getId()[i] - 48 == 4 || getId()[i] - 48 == 5 || getId()[i] - 48 == 6)
            return false;
    }

    if (getId().length() == 9) {
        if (getId()[2] != '*')
            return false;
        for (int i = 0; i <= 9; ++i) {
            if (getId()[3] - 48 == i)
                return false;
        }
        for (int i = 4; i < 8; ++i) {
            if (getId()[i] - 48 == 4 || getId()[i] - 48 == 5 || getId()[i] - 48 == 6)
                return false;
        }
    }
    if (getId().length() == 10) {
        if (getId()[2]!= '*')
            return false;
        for (int j = 3; j <= 4; ++j) {
            for (int i = 0; i <= 9; ++i) {
                if (getId()[j] - 48 == i)
                    return false;
            }
        }
        for (int i = 5; i < 8; ++i) {
            if (getId()[i] - 48 == 4 || getId()[i] - 48 == 5 || getId()[i] - 48 == 6)
                return false;
        }
    }
    return true;


}

double Employee::calculateSalary() const {
    double percent=((double)(workDone-workToDo)/workDone);
    double salary=salaryPerHour*hourWork;
    salary=salary-(salary*percent);
    return salary;

}

double Employee::efficiency() const {

    double percent=((double)(workDone-workToDo)/workDone);

    double efficient=(100*percent)/hourWork;

    return efficient;
}
