#ifndef SYS_PROG_2ND_COURSE_TEST_TYPE_REPO_H
#define SYS_PROG_2ND_COURSE_TEST_TYPE_REPO_H
#include "../../Entities/Headers/test_type.h"
#include <vector>

using namespace std;
using namespace Entities;

class TestTypeRepository
{
public:
    virtual void Add(TestTypeEntity& entity) = 0;
    virtual void Remove(TestTypeEntity& entity) = 0;
    virtual void Update(TestTypeEntity& entity) = 0;
    virtual TestTypeEntity& Get(int Id) = 0;
    virtual vector<TestTypeEntity>& GetAll() = 0;
    virtual void Save() = 0;
};

#endif //SYS_PROG_2ND_COURSE_TEST_TYPE_REPO_H
