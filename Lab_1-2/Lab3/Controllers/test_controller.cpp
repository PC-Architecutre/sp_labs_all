#ifndef SYS_PROG_2ND_COURSE_TestController_CPP
#define SYS_PROG_2ND_COURSE_TestController_CPP

#include "../Domain/Headers/test.h"
#include "test_controller.h"
#include "../DataAccess/UnitOfWorkFileDB.h"
#include <vector>

using namespace Domain;

TestController::TestController()
{
       UnitOfWorkFileDB uof = UnitOfWorkFileDB();
      _testService = new TestService(uof);
      _testResultService = new  TestResultService(uof);
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

#endif
