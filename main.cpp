#include <iostream>
#include "Address.h"
#include "Person.h"
#include "Employee.h"
#include "Boss.h"
#include "Company.h"

using namespace std;

int main() {

    Boss *boss = new Boss( 10, 10000, 20, 25,10,"Azadeh Mansouri", "89*am12832", *(new Address("Iran", "Tehran", "Andarzgo")));

    Employee **employee = new Employee *[boss->getNumberOfEmployees()];
    employee[0] = new Employee(6, 8500, 18,15,"Reza Moradi", "93*r97320", *(new Address("Iran", "Shiraz", "Fattah")) );
    employee[1] = new Employee( 3, 10000, 20,8,"Hossein ghadirzadeh", "90*m13320", *(new Address("Iran", "karaj", "sasani")));
    employee[2] = new Employee( 8, 7000, 30,15,"amirhossein moayedinia", "93*90182", *(new Address("Iran", "Dorud", "Moalem")));
    employee[3] = new Employee( 7, 5000, 8,5,"alireza Rezaie", "91*ax32320", *(new Address("Iran", "esfahan", "abasabad")));
    employee[4] = new Employee( 12, 5500, 6,6,"babak poorbakht", "88*qq93227", *(new Address("Iran", "qom", "kashani")));
    employee[5] = new Employee( 5, 11000, 14,12,"Kaveh shahedi", "85*r97320", *(new Address("Iran", "Semnan", "Navab")));
    employee[6] = new Employee(12, 3000, 10,2,"Amirhosein Nickomanesh", "98*97320", *(new Address("Iran", "abadan", "konj")));
    employee[7] = new Employee( 3, 6000, 12,11,"Reza shiri", "99*rt11320", *(new Address("Iran", "mashahd", "shirazi")));
    employee[8] = new Employee(4, 15000,25, 19,"Mohammad radmand", "94*a01203", *(new Address("Iran", "Karaj", "Resalat")));
    employee[9] = new Employee( 12, 4000, 30,25,"Mohammad Rad", "87*ox19280", *(new Address("Iran", "Mashhad", "Tabarsi")));
    Company company(1000000, boss, employee);
    cout << "Company before changing the boss:" << endl << endl;
    cout << company << endl;
    cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ " << endl;

    cout << "IS the budget enough to pay?" << endl;
    if (company.isEnoughBudget())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    company.ChangeBoss();
    cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ " << endl;
    cout << "Company after changing the boss:" << endl << endl;
    cout << company << endl;
    cout << " $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ $ " << endl;
    cout << "Max efficiency:" << endl;
    cout << *company.maxEfficiency();
    cout << "details saved!";
    company.writeOnFile();
    return 0;
}
