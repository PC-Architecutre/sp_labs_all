#ifndef SYS_PROG_2ND_COURSE_TEST_RESULT_REPO_H
#define SYS_PROG_2ND_COURSE_TEST_RESULT_REPO_H

#include "../../Entities/Headers/test_result.h"
#include <vector>

using namespace std;
using namespace Entities;

class TestResultRepository
{
public:
    virtual void Add(TestResultEntity entity) = 0;
    virtual void Remove(TestResultEntity& entity) = 0;
    virtual void Update(TestResultEntity& entity) = 0;
    virtual TestResultEntity& Get(int Id) = 0;
    virtual vector<TestResultEntity>& GetAll() = 0;
    virtual vector<TestResultEntity> GetByUserId(int userId) = 0;
    virtual vector<TestResultEntity> GetByTestId(int testId) = 0;
    virtual void Save() = 0;
};

#endif //SYS_PROG_2ND_COURSE_TEST_RESULT_REPO_H
