#ifndef UNTITLED_FILEDATABASE_H
#define UNTITLED_FILEDATABASE_H
#include "Employee.h"
#include <vector>

class FileDatabase {
public:
    FileDatabase();
    ~FileDatabase();

    Employee& Get(std::string employee_code);
    void Add(Employee& employee);
    void Delete(std::string employee_code);
    std::vector<Employee>& GetAll();
    void SaveChanges();
    void displayInfo(std::string& employee_code);
    void displayAllInPosition(Position position);
    void displayAll();
private:
    void _saveToFile();
    void _readFromFile();
    int _getIndex(std::string& employee_code);
    std::vector<Employee> employees;
};


#endif //UNTITLED_FILEDATABASE_H
