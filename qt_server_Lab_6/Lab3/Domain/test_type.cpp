#include "Headers/test_type.h"

using namespace Domain;

TestType::TestType()
{
}

TestType::~TestType()
{
}

int TestType::GetId() const 
{
   return id; 
}

void TestType::SetId(int id) 
{
    this->id = id;
}

const string& TestType::GetType() const
{
    return type;
}

void TestType::SetType(const string& type)
{
    this->type = type;
}

const vector<Test>& TestType::GetTests() const 
{
    return this->tests;
}

void TestType::AddTest(const Test& test) 
{
    tests.push_back(test); 
}
