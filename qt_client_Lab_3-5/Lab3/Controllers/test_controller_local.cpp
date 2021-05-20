#ifndef SYS_PROG_2ND_COURSE_TestControllerLocal_CPP
#define SYS_PROG_2ND_COURSE_TestControllerLocal_CPP

#include "../Domain/Headers/test.h"
#include "test_controller_local.h"
#include "../DataAccess/FileRepositories/UnitOfWorkFileDB.h"
#include <vector>

using namespace Domain;

TestControllerLocal::TestControllerLocal(UnitOfWorkSqlDB* uof)
{
    _testService = new TestService(uof);
    _testResultService = new  TestResultService(uof);
    _userService = new UserService(uof);
}

TestControllerLocal::~TestControllerLocal() {}

Test TestControllerLocal::GetTestById(int id)
{

    return _testService->GetTestById(id);
}

vector<Test> TestControllerLocal::GetAllTests()
{
    return _testService->GetAllTests();
}

void TestControllerLocal::SaveUserResult(TestResult testResult)
{
    _testResultService->SaveUserResult(testResult);
}

User* TestControllerLocal::GetUserByName(const QString *str) {
    return _userService->GetUserByName(str->toStdString());
}

vector<TestResult> TestControllerLocal::GetUserResults(User &user) {
    return _testResultService->GetUserResults(user.GetId());
}

vector<TestResult> TestControllerLocal::GetResultsByTestId(int testId) {
    return _testResultService->GetResultsByTestId(testId);
}

#endif