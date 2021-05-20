#include "../Abstract/test_result_repo.h"
#include "../../FileDatabase/Headers/test_result_db.h"

class TestResultFileRepository: public  TestResultRepository {
public:
    TestResultFileRepository();
    void Add(TestResultEntity& entity) override;
    void Remove(TestResultEntity& entity) override;
    void Update(TestResultEntity& entity) override;
    TestResultEntity& Get(int Id) override;
    vector<TestResultEntity>& GetAll() override;
    void Save() override;
    vector<TestResultEntity> GetByUserId(int userId) override;
    vector<TestResultEntity> GetByTestId(int testId) override;
private:
    TestResultFileDB _db;
};