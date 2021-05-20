#include "Headers/user.h"

using namespace Domain;

User::User()
{
}

User::~User()
{
}

int User::GetId() const 
{
   return id; 
}

void User::SetId(int id) 
{
    this->id = id;
}

const string& User::GetName() const
{
    return name;
}

void User::SetName(const string& name)
{
    this->name = name;
}


const vector<TestResult>& User::GetTestResults() const 
{
    return this->testResults;
}

void User::AddTestResult(const TestResult& testResult) 
{
    testResults.push_back(testResult); 
}
