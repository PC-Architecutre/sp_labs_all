#ifndef SYS_PROG_2ND_COURSE_TESTTYPEFILEREPOSITORY_H
#define SYS_PROG_2ND_COURSE_TESTTYPEFILEREPOSITORY_H
#include "../Abstract/test_type_repo.h"
#include "../../FileDatabase/Headers/test_type_db.h"

class TestTypeFileRepository: public  TestTypeRepository {
public:
    TestTypeFileRepository();
    void Add(TestTypeEntity& entity) override;
    void Remove(TestTypeEntity& entity) override;
    void Update(TestTypeEntity& entity) override;
    TestTypeEntity& Get(int Id) override;
    vector<TestTypeEntity>& GetAll() override;
    void Save() override;
private:
    TestTypeFileDB _db;
};

#endif //SYS_PROG_2ND_COURSE_TESTTYPEFILEREPOSITORY_H
