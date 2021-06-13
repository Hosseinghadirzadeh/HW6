
#ifndef HW6_EMPLOYEE_H
#define HW6_EMPLOYEE_H

#include "Person.h"


class Employee : public Person {
private:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;


public:
    Employee();

    Employee(int,int,int,int,string,string,Address);

    Employee(const Employee&);

    int getHourWork() const;

    void setHourWork(int hourWork);

    int getSalaryPerHour() const;

    void setSalaryPerHour(int salaryPerHour);

    int getWorkToDo() const;

    void setWorkToDo(int workToDo);

    int getWorkDone() const;

    void setWorkDone(int workDone);

    friend ostream &operator<<(ostream &,  Employee &);

    friend istream &operator>>(istream &, Employee &);

    Employee &operator=(const Employee &);

    bool validate() override;//difference between this and the same in the parent is in the third char we have '*'

    virtual double calculateSalary() const;

    double efficiency() const;



};


#endif //HW6_EMPLOYEE_H
