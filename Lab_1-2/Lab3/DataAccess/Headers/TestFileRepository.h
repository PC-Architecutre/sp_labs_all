#ifndef SYS_PROG_2ND_COURSE_TESTFILEREPOSITORY_H
#define SYS_PROG_2ND_COURSE_TESTFILEREPOSITORY_H
#include "../Abstract/test_repo.h"
#include "../../FileDatabase/Headers/test_db.h"

class TestFileRepository: public  TestRepository {
public:
    TestFileRepository();
    void Add(TestEntity& entity) override;
    void Remove(TestEntity& entity) override;
    void Update(TestEntity& entity) override;
    TestEntity& Get(int Id) override;
    vector<TestEntity>& GetAll() override;
    void Save() override;
private:
    TestFileDB _db;
};


#endif //SYS_PROG_2ND_COURSE_TESTFILEREPOSITORY_H
