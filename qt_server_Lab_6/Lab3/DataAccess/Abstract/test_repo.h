#ifndef SYS_PROG_2ND_COURSE_TEST_REPO_H
#define SYS_PROG_2ND_COURSE_TEST_REPO_H

#include "../../Entities/Headers/test.h"
#include <vector>

using namespace std;
using namespace Entities;

class TestRepository
{
public:
    virtual void Add(TestEntity& entity) = 0;
    virtual void Remove(TestEntity& entity) = 0;
    virtual void Update(TestEntity& entity) = 0;
    virtual TestEntity& Get(int Id) = 0;
    virtual vector<TestEntity>& GetAll() = 0;
    virtual void Save() = 0;
};

#endif //SYS_PROG_2ND_COURSE_TEST_REPO_H
