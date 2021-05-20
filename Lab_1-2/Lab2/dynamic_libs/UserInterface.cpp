#include <iostream>
#include <stdexcept>
#include <string>
#include "FileDatabase.h"

using namespace std;

int displayMenu();
void createEmployee(FileDatabase& inDB);
void changePosition(FileDatabase& inDB);
void deleteEmployee(FileDatabase& inDB);
void displayInfo(FileDatabase& inDB);
void displayAllInPosition(FileDatabase& inDB);

static std::string selectGender();
static Gender checkInputGender(string inGen);
static std::string selectPosition();
static Position checkInputPosition(string inPos);

int main()
{
	int myInt = 0;
	int& myRef = myInt;
     FileDatabase employeeDB;
     bool done = false;
     while (!done) {
        int selection = displayMenu();
        switch (selection) {
        case 1:
            createEmployee(employeeDB);
            break;
        case 2:
            changePosition(employeeDB);
            break;
        case 3:
            deleteEmployee(employeeDB);
            break;
        case 4:
            displayInfo(employeeDB);
            break;
        case 5:
            displayAllInPosition(employeeDB);
            break;
        case 6:
            employeeDB.displayAll();
            break;
        case 0:
            done = true;
            employeeDB.SaveChanges();
            break;
        default:
            cout << "Unknown command." << endl;
        }
    }
}

int displayMenu() {
     int selection;
     cout << endl;
     cout << "Employee Database" << endl;
     cout << "-----------------" << endl;
     cout << "1 - Create a new employee" << endl;
     cout << "2 - Change employee position" << endl;
     cout << "3 - Delete employee" << endl;
     cout << "4 - Display all info about employee" << endl;
     cout << "5 - Display all employees in some position" << endl;
     cout << "6 - Display all employees" << endl;
     cout << "0 - Quit" << endl;
     cout << endl;
     cin >> selection;
     return selection;
}

static std::string selectPosition() {
    string position;

    cout << "Choose a position" << endl;
    cout << "1 - Director" << endl;
    cout << "2 - Manager" << endl;
    cout << "3 - OfficeWorker" << endl;
    cout << "4 - Consultant" << endl;
    cout << "5 - Unemployed" << endl;
    cin >> position;
    return position;
}

static Position checkInputPosition(string inPos) {
    switch(std::stoi(inPos)) {
    case 1:
        return Position::Director;
        break;
    case 2:
        return Position::Manager;
        break;
    case 3:
        return Position::OfficeWorker;
        break;
    case 4:
        return Position::Consultant;
        break;
    case 5:
        return Position::Unemployed;
        break;
    default:
        return Position::Unemployed;
        break;
    }
}

static std::string selectGender() {
    string gender;
    cout << "Choose a gender" << endl;
    cout << "1 - Male" << endl;
    cout << "2 - Female" << endl;
    cout << "3 - Else" << endl;
    cin >> gender;
    return gender;
}

static Gender checkInputGender(string inGen) {
    switch(std::stoi(inGen)) {
    case 1:
        return Gender::Male;
        break;
    case 2:
        return Gender::Female;
        break;
    case 3:
        return Gender::Else;
        break;
    default:
        return Gender::Else;
        break;
    }
}

void createEmployee(FileDatabase& inDB) {
    Employee emp1;
    string name;
    int age;
    Gender gender;
    Position position;
    string address;
    string passport;
    string input;

    cout << "Name? ";
    cin >> name;
    cout << "Age? ";
    cin >> age;

    cout << "Gender?" << endl;
    input = selectGender();
    gender = checkInputGender(input);

    cout << "Position?" << endl;
    input = selectPosition();
    position = checkInputPosition(input);
    cout << "Address? ";
    cin >> address;
    cout << "Passport? ";
    cin >> passport;

    emp1.setEmployeeName(name);
    emp1.setEmployeeAge(age);
    emp1.setEmployeeGender(gender);
    emp1.setEmployeeAddress(address);
    emp1.setEmployeePassport(passport);
    emp1.setEmployeePosition(position);
    try {
        inDB.Add(emp1);
    } catch (std::exception ex) {
        cerr << "Unable to add a new employee!" << endl;
    }
}

void changePosition(FileDatabase& inDB) {
    Position position;
    string employeeCode;
    string input;

    cout << "Employee code? ";
    cin >> employeeCode;
    input = selectPosition();
    position = checkInputPosition(input);
    try {
        Employee& emp = inDB.Get(employeeCode);
        emp.setEmployeePosition(position);
        cout << "Employee with code " << employeeCode << " now has new position: " << input << endl;
    } catch (std::exception ex) {
        cerr << "Unable to change position of employee!" << endl;
    }
}

void deleteEmployee(FileDatabase& inDB) {
    string employeeCode;

    cout << "Employee code? ";
    cin >> employeeCode;
    try {
        inDB.Delete(employeeCode);
        cout << "Employee with code" << employeeCode << " was successfully deleted" << endl;
    } catch (std::exception ex) {
        cerr << "Unable to delete employee with such code!" << endl;
    }
}

void displayInfo(FileDatabase& inDB) {
    string employeeCode;

    cout << "Employee code? ";
    cin >> employeeCode;
    try {
        inDB.displayInfo(employeeCode);
    } catch (std::exception ex) {
        cerr << "Unable to display info of employee with such code!" << endl;
    }
}

void displayAllInPosition(FileDatabase& inDB) {
    Position position;
    string input;

    input = selectPosition();
    position = checkInputPosition(input);
    try {
        cout << "Employees in position: " << input << endl;
        inDB.displayAllInPosition(position);
    } catch (std::exception ex) {
        cerr << "Unable to display employees in such position!" << endl;
    }
}



