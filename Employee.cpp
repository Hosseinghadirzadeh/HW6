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
                                                                                                workDone(wd) {}

Employee::Employee(const Employee &employee) : Person(employee) {
    hourWork = employee.hourWork;
    salaryPerHour = employee.salaryPerHour;
    workToDo = employee.workToDo;
    workDone = employee.workDone;
    if(!validate())
    {cout<<"invalid id";
        exit(1);
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
    if (id[2] != '*')
        return false;
    return Person::validate();

}

double Employee::calculateSalary() const {
    double percent=(((double)workDone/workToDo));
    double salary=salaryPerHour*hourWork;
    salary=salary-(salary*percent);
    return salary;

}

double Employee::efficiency() const {
    return (((double)workDone / workToDo) * 100) / hourWork;
}






