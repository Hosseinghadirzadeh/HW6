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
Employee::Employee(const Employee& employee):Person(employee) {
    hourWork=employee.hourWork;
    salaryPerHour=employee.salaryPerHour;
    workToDo=employee.workToDo;
    workDone=employee.workDone;

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

ostream &operator<<(ostream & out, Employee & e) {
out<<"Name: "<<e.getName()<<endl<<"ID: "<<e.getId()<<endl<<"Address:"<<e.getAddress()<<endl;
out<<"hour Work: "<<e.hourWork<<endl<<"salary perHour: "<<e.salaryPerHour<<endl<<"work to Do: "<<e.workToDo<<endl;

    return out;
}
