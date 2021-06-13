#include <iostream>
#include "Address.h"
#include "Person.h"
#include "Employee.h"
#include "Boss.h"
#include "Company.h"

using namespace std;

int main() {

    Boss *boss = new Boss( 5, 10000, 20, 25,10,"Ali Mehrabi", "89*am12832", *(new Address("Iran", "Tehran", "Enghelab")));

    Employee **employee = new Employee *[boss->getNumberOfEmployees()];
    employee[0] = new Employee(5, 8500, 18,15,"Reza Moradi", "93*r97320", *(new Address("Iran", "Shiraz", "Fattah")));
    employee[1] = new Employee( 9, 10000, 20,8,"Mehran Asadi", "90*m13320", *(new Address("Iran", "Shiraz", "Fattah")));
    employee[2] = new Employee( 6, 7000, 30,15,"Ahmad Ahmadi", "93*90182", *(new Address("Iran", "Shiraz", "Fattah")));
    employee[3] = new Employee( 7, 5000, 8,5,"Ghorban Rezaie", "91*ax32320", *(new Address("Iran", "Shiraz", "Fattah")));
    employee[4] = new Employee( 11, 5500, 6,6,"Masoud Rahmati", "88*qq93227", *(new Address("Iran", "Shiraz", "Fattah")));
    employee[5] = new Employee(10, 11000, 14,12,"Kaveh Moshiri", "85*r97320", *(new Address("Iran", "Shiraz", "Fattah")));
    employee[6] = new Employee(4, 3000, 10,2, "Bahram Sedighi", "98*97320", *(new Address("Iran", "Shiraz", "Fattah")) );
    employee[7] = new Employee( 3, 6000, 12,11,"Reza Shiri", "99*rt11320", *(new Address("Iran", "Shiraz", "Fattah")));
    employee[8] = new Employee(8, 15000,25, 19,"Amirhosein Momen", "94*a01203", *(new Address("Iran", "Shiraz", "Fattah")) );
    employee[9] = new Employee(2, 4000, 30,25,"Mohammad Rad", "87*ox19280", *(new Address("Iran", "Shiraz", "Fattah")) );
Company c(222,boss,employee);
cout<<c.maxEfficiency() ;

    return 0;
}
