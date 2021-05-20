//
// Created by koler on 09.02.2021.
//

#include <string>
#include "Gender.h"
#include "Position.h"

#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H


class Employee {
    public:
        Employee();
        ~Employee();

        std::string getEmployeeCode() const;
        float getEmployeeSalary() const;
        std::string toString();

        const std::string& getEmployeeName() const;
        void setEmployeeName(const std::string& name);

        int getEmployeeAge() const;
        void setEmployeeAge(int age);

        Gender getEmployeeGender() const;
        void setEmployeeGender(Gender gender);

        const std::string& getEmployeeAddress() const;
        void setEmployeeAddress(const std::string& address);

        const std::string& getEmployeePassport() const;
        void setEmployeePassport(const std::string& passport);

        Position getEmployeePosition() const;
        void setEmployeePosition(Position position);


    private:
        std::string EmployeeName;
        int EmployeeAge;
        Gender EmployeeGender;
        std::string EmployeeAddress;
        std::string EmployeePassport;
        Position EmployeePosition;
        int StandardWage;
        int MinimalWage;
        std::string genderToString();
        std::string positionToString();
};


#endif //UNTITLED_EMPLOYEE_H
