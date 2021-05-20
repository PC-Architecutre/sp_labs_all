#ifndef SYS_PROG_2ND_COURSE_TestController_CPP
#define SYS_PROG_2ND_COURSE_TestController_CPP

#include "../Domain/Headers/test.h"
#include "test_controller.h"
#include "../DataAccess/FileRepositories/UnitOfWorkFileDB.h"
#include <vector>

using namespace Domain;

TestController::TestController(UnitOfWorkSqlDB* uof)
{
    _testService = new TestService(uof);
    _testResultService = new  TestResultService(uof);
    _userService = new UserService(uof);
}

TestController::~TestController() {}

Test TestController::GetTestById(int id)
{

    return _testService->GetTestById(id);
}

vector<Test> TestController::GetAllTests()
{
    return _testService->GetAllTests();
}

void TestController::SaveUserResult(TestResult testResult)
{
    _testResultService->SaveUserResult(testResult);
}

User* TestController::GetUserByName(QString str) {
    return _userService->GetUserByName(str.toStdString());
}

vector<TestResult> TestController::GetUserResults(User &user) {
    return _testResultService->GetUserResults(user.GetId());
}

vector<TestResult> TestController::GetResultsByTestId(int testId) {
    return _testResultService->GetResultsByTestId(testId);
}

#endif