#include "Headers/test.h"

using namespace Domain;

Test::Test() {}

Test::~Test() {}

int Test::GetId() const 
{
   return id; 
}

void Test::SetId(int id) 
{
    this->id = id;
}
int Test::GetTimeConstraint() const
{
    return timeConstraint;
}

void Test::SetTimeConstrain(int time)
{
    this->timeConstraint = time;
}

const vector<Question>& Test::GetQuestions() const
{
   return questions;
}

void Test::AddQuestion(Question &question)
{
    questions.push_back(question);
}

const vector<TestResult>& Test::GetTestResults() const 
{
    return this->testResults;
}

void Test::AddTestResult(const TestResult& testResult) 
{
    testResults.push_back(testResult); 
}

void Test::SetName(const string &name) {
    this->name = name;
}

const string& Test::GetName() const {
    return name;
}
