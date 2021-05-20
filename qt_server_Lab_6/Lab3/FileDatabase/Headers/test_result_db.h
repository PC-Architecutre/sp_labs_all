//
// Created by misha on 05.03.21.
//

#ifndef SYS_PROG_2ND_COURSE_TEST_RESULT_DB_H
#define SYS_PROG_2ND_COURSE_TEST_RESULT_DB_H


#include "../../Entities/Headers/test_result.h"
#include <vector>
using namespace Entities;

class TestResultFileDB {
public:
    TestResultFileDB();
    ~TestResultFileDB();

    TestResultEntity& Get(int Id);
    void Add(TestResultEntity& entity);
    void Delete(TestResultEntity& entity);
    void Update(TestResultEntity& entity);
    std::vector<TestResultEntity>& GetAll();
    void SaveChanges();
private:
    void _saveToFile();
    void _readFromFile();
    int _getIndex(int Id);
    std::vector<TestResultEntity> entities;
};


#endif //SYS_PROG_2ND_COURSE_TEST_RESULT_DB_H
