#include "Headers/user.h"
#include "Headers/test_result.h"
#include "Headers/test.h"

Domain::TestResult::TestResult()
{
}

Domain::TestResult::~TestResult()
{
}

int Domain::TestResult::GetId() const 
{
   return id; 
}

void Domain::TestResult::SetId(int id) 
{
    this->id = id;
}

int Domain::TestResult::GetScore() const 
{
   return id; 
}

void Domain::TestResult::SetScore(int id) 
{
    this->id = id;
}

Domain::User Domain::TestResult::GetUser() const {
    return *user;
}

void Domain::TestResult::SetUser(Domain::User user) {
    this->user = &user;
}

Domain::Test Domain::TestResult::GetTest() const
{
    return *test;
}

void Domain::TestResult::SetTest(Test test)
{
    this->test = &test;
}
