#include <iostream>
#include "Address.h"
#include "Person.h"
#include "Employee.h"
#include "Boss.h"

using namespace std;

int main() {

Address a;
Employee e(2,2,2,2,"ss","98*ad37320",a);
cout<<e.validate();




    return 0;
}
