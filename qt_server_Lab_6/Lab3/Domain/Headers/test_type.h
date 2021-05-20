#ifndef SYS_PROG_2ND_COURSE_TestTypeDomain_H
#define SYS_PROG_2ND_COURSE_TestTypeDomain_H
#include <string>
#include "test.h"
#include <vector>

using namespace std;

namespace Domain { 

class TestType
{
public:
    TestType();
    ~TestType();

    int GetId() const;
    void SetId(int id);

    const string& GetType() const;
    void SetType(const string& type);

    const vector<Test>& GetTests() const;
    void AddTest(const Test& test);
    void RemoveTest(const Test& test);

private:
     int id;
     string type;
     vector<Test> tests;
};
}
#endif
