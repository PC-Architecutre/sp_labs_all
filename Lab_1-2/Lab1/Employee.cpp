//
// Created by koler on 09.02.2021.
//

#include "Employee.h"

Employee::Employee()
{
    EmployeeName = "Unknown Employee";
    EmployeeAge = 0;
    EmployeeGender = Gender::Else;
    EmployeeAddress = "Not assigned";
    EmployeePassport = "Not assigned";
    EmployeePosition = Position::Unemployed;
    StandardWage = 4000;
    MinimalWage = 1250;
}

Employee::~Employee()
= default;

std::string Employee::getEmployeeCode() const
{
    std::string employeeCode;
    for (int i = 0; i < getEmployeeName().length(); i++)
    {
        if (getEmployeeName()[i] != ' ' && (i == 0 || getEmployeeName()[i-1] == ' '))
            employeeCode += getEmployeeName()[i];
    }
    employeeCode += std::to_string(getEmployeeAge());
    return employeeCode;
}

float Employee::getEmployeeSalary() const
{
    float salary = getEmployeePosition()*StandardWage;
    if (salary < MinimalWage && getEmployeePosition() != Position::Unemployed)
        return MinimalWage;
    return salary;
}

std::string Employee::toString()
{
    return  "Employee Name: " + getEmployeeName() +  "\n" +
            "Employee Age: " + std::to_string(getEmployeeAge()) +  "\n" +
            "Employee Code: " + getEmployeeCode() +  "\n" +
            "Employee Gender: " + genderToString() +  "\n" +
            "Employee Address: " + getEmployeeAddress() +  "\n" +
            "Employee Passport: " + getEmployeePassport() +  "\n" +
            "Employee Position: " + positionToString() +  "\n" +
            "Employee Salary: " + std::to_string(getEmployeeSalary()) +  "\n";
}

const std::string & Employee::getEmployeeName() const
{
    return EmployeeName;
}

void Employee::setEmployeeName(const std::string &name)
{
    EmployeeName = name;
}

int Employee::getEmployeeAge() const
{
    return EmployeeAge;
}

void Employee::setEmployeeAge(int age)
{
    EmployeeAge = age;
}

Gender Employee::getEmployeeGender() const
{
    return EmployeeGender;
}

void Employee::setEmployeeGender(Gender gender)
{
    EmployeeGender = gender;
}

const std::string & Employee::getEmployeeAddress() const
{
    return EmployeeAddress;
}

void Employee::setEmployeeAddress(const std::string &address)
{
    EmployeeAddress = address;
}

const std::string & Employee::getEmployeePassport() const
{
    return EmployeePassport;
}

void Employee::setEmployeePassport(const std::string &passport)
{
    EmployeePassport = passport;
}

Position Employee::getEmployeePosition() const
{
    return EmployeePosition;
}

void Employee::setEmployeePosition(Position position)
{
    EmployeePosition = position;
}

std::string Employee::genderToString()
{
    if (getEmployeeGender() == Gender::Male)
        return "Male";
    if (getEmployeeGender() == Gender::Female)
        return "Female";
    return "Else";
}

std::string Employee::positionToString()
{
    if (getEmployeePosition() == Position::Director)
        return "Director";
    if (getEmployeePosition() == Position::OfficeWorker)
        return "Office Worker";
    if (getEmployeePosition() == Position::Manager)
        return "Manager";
    return "Consultant";
}
