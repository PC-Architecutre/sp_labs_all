#ifndef SYS_PROG_2ND_COURSE_TestController_H
#define SYS_PROG_2ND_COURSE_TestController_H

#include "../Domain/Headers/test.h"
#include <vector>
#include <QString>
#include "../Services/Headers/TestService.h"
#include "../Services/Headers/UserService.h"
#include "../Services/Headers/TestResultService.h"
#include "../DataAccess/SqlRepositories/Headers/UnitOfWorkSqlDB.h"

using namespace Domain;
using namespace SqlRepositories;

class TestController
{
public:
    TestController(UnitOfWorkSqlDB* uof);
    ~TestController();
    Test GetTestById(int id);
    vector<Test> GetAllTests();
    void SaveUserResult(TestResult TestResult);
    User* GetUserByName(QString str);
    vector<TestResult> GetUserResults(User& user);
    vector<TestResult> GetResultsByTestId(int testId);
private:
    TestService* _testService;
    TestResultService* _testResultService;
    UserService* _userService;
};

#endif