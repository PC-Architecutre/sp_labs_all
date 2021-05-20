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
   return score;
}

void Domain::TestResult::SetScore(int score)
{
    this->score = score;
}

Domain::User Domain::TestResult::GetUser() const {
    return *user;
}

Domain::User* Domain::TestResult::GetUserPtr() const {
    return user;
}

void Domain::TestResult::SetUser(Domain::User* user) {
    this->user = user;
}

Domain::Test Domain::TestResult::GetTest() const
{
    return *test;
}

void Domain::TestResult::SetTest(Test* test)
{
    this->test = test;
}
