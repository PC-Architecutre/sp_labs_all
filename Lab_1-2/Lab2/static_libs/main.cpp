#include <iostream>
#include "Employee.h"
using namespace  std;

int main() {
    Employee emp1;
    emp1.setEmployeeName("Daniel Wessley");
    emp1.setEmployeeAge(25);
    emp1.setEmployeeGender(Gender::Male);
    emp1.setEmployeeAddress("New York");
    emp1.setEmployeePassport("4839483854");
    emp1.setEmployeePosition(Position::Manager);
    cout << emp1.toString();
}

