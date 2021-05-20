//
// Created by misha on 05.03.21.
//

#ifndef SYS_PROG_2ND_COURSE_TESTDB_H
#define SYS_PROG_2ND_COURSE_TESTDB_H

#include "../../Entities/Headers/test.h"
#include <vector>


using namespace Entities;

class TestFileDB {
public:
    TestFileDB();
    ~TestFileDB();

    TestEntity& Get(int Id);
    void Add(TestEntity& entity);
    void Delete(TestEntity& entity);
    void Update(TestEntity& entity);
    std::vector<TestEntity>& GetAll();
    void SaveChanges();
private:
    void _saveToFile();
    void _readFromFile();
    int _getIndex(int Id);
    std::vector<TestEntity> entities;
};

#endif //SYS_PROG_2ND_COURSE_TESTDB_H
