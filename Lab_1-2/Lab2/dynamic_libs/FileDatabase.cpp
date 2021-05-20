#include <iostream>
#include <fstream>
#include "FileDatabase.h"
#define DB_PATH "./FileDatabase.txt"

FileDatabase::FileDatabase() {
    employees = std::vector<Employee>();
    _readFromFile();
}

FileDatabase::~FileDatabase() = default;

std::vector<Employee> &FileDatabase::GetAll() {
    return employees;
}

void FileDatabase::Add(Employee &employee) {
    employees.push_back(employee);
}

Employee& FileDatabase::Get(std::string employee_code) {
    return employees.at(_getIndex(employee_code));
}

void FileDatabase::Delete(std::string employee_code) {
    employees.erase(employees.begin()+_getIndex(employee_code));
}

void FileDatabase::SaveChanges() {
   _saveToFile();
}

void FileDatabase::_saveToFile() {
    std::ofstream out;
    out.open(DB_PATH);
    for (auto & emp : employees)
    {
        out << emp.getEmployeeName() << std::endl;
        out << emp.getEmployeeAge() << std::endl;
        out << emp.getEmployeeAddress() << std::endl;
        out << emp.getEmployeePassport() << std::endl;
        out << emp.getEmployeePosition() << std::endl;
        out << emp.getEmployeeGender() << std::endl;
    }
    out.close();
}

void FileDatabase::_readFromFile() {
    std::ifstream in;
    in.open(DB_PATH);
    std::string name;
    int age;
    std::string address;
    std::string passport;
    int position;
    int gender;

    while (getline(in, name))
    {
        Employee emp = Employee();
        emp.setEmployeeName(name);
        in >> age;
        getline(in, name);
        emp.setEmployeeAge(age);
        getline(in,address);
        emp.setEmployeeAddress(address);
        getline(in,passport);
        emp.setEmployeePassport(passport);
        in >> position;
        getline(in, name);
        emp.setEmployeePosition(static_cast<Position>(position));
        in >> gender;
        getline(in, name);
        emp.setEmployeeGender(static_cast<Gender>(gender));
        employees.push_back(emp);
    }
    in.close();
}

int FileDatabase::_getIndex(std::string& employee_code) {
    for (std::vector<Employee>::size_type i = 0; i < employees.size(); i++)
    {
        if (employees.at(i).getEmployeeCode() == employee_code)
            return i;
    }
    return -1;
}

void FileDatabase::displayInfo(std::string& employee_code) {
    employees.at(_getIndex(employee_code)).display();
}

void FileDatabase::displayAllInPosition(Position position) {
    for (std::vector<Employee>::size_type i = 0; i < employees.size(); i++)
    {
        if (employees.at(i).getEmployeePosition() == position)
            employees.at(i).display();
    }
}

void FileDatabase::displayAll() {
    for (std::vector<Employee>::size_type i = 0; i < employees.size(); i++)
    {
        employees.at(i).display();
    }
}

