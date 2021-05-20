//
// Created by misha on 05.03.21.
//

#ifndef SYS_PROG_2ND_COURSE_TestType_TYPE_DB_H
#define SYS_PROG_2ND_COURSE_TestType_TYPE_DB_H

#include "../../Entities/Headers/test_type.h"
#include <vector>
using namespace Entities;

class TestTypeFileDB {
public:
    TestTypeFileDB();
    ~TestTypeFileDB();

    TestTypeEntity& Get(int Id);
    void Add(TestTypeEntity& entity);
    void Delete(TestTypeEntity& entity);
    void Update(TestTypeEntity& entity);
    std::vector<TestTypeEntity>& GetAll();
    void SaveChanges();
private:
    void _saveToFile();
    void _readFromFile();
    int _getIndex(int Id);
    std::vector<TestTypeEntity> entities;
};

#endif //SYS_PROG_2ND_COURSE_TestType_TYPE_DB_H
