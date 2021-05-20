#ifndef SYS_PROG_2ND_COURSE_UserDomain_H
#define SYS_PROG_2ND_COURSE_UserDomain_H
#include <string>
#include <vector>
#include "test_result.h"

using namespace std;

namespace Domain { 

class User
{
public:
    User();
    ~User();

    int GetId() const;
    void SetId(int id);

    const string& GetName() const;
    void SetName(const string& name);

    const vector<TestResult>& GetTestResults() const;
    void AddTestResult(const TestResult& option);
    void RemoveTestResult(const TestResult& option);
private:
    vector<TestResult> testResults;
     int id;
     string name;
};
}

#endif
