#ifndef SYS_PROG_2ND_COURSE_TestController_H
#define SYS_PROG_2ND_COURSE_TestController_H

#include "../Domain/Headers/test.h"
#include <vector>
#include "../Services/Headers/TestService.h"
#include "../Services/Headers/TestResultService.h"

using namespace Domain;

class TestController 
{
    public:
        TestController();
        ~TestController();
        Test GetTestById(int id);
        vector<Test> GetAllTests();
        void SaveUserResult(TestResult TestResult);
    private:
        TestService* _testService;
        TestResultService* _testResultService;
};

#endif
