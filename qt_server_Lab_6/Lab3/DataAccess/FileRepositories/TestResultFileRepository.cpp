//
// Created by misha on 05.03.21.
//

#include "Headers/TestResultFileRepository.h"

TestResultFileRepository::TestResultFileRepository() {
    _db = TestResultFileDB();
}

void TestResultFileRepository::Add(TestResultEntity entity) {
    _db.Add(entity);
}

TestResultEntity& TestResultFileRepository::Get(int Id) {
    return _db.Get(Id);
}

vector<TestResultEntity>& TestResultFileRepository::GetAll() {
    return _db.GetAll();
}

void TestResultFileRepository::Remove(TestResultEntity& entity) {
    _db.Delete(entity);
}

void TestResultFileRepository::Update(TestResultEntity& entity) {
    _db.Update(entity);
}

void TestResultFileRepository::Save() {
    _db.SaveChanges();
}

vector<TestResultEntity> TestResultFileRepository::GetByUserId(int userId) {
    vector<TestResultEntity> trs = vector<TestResultEntity>();
    for (auto tr: _db.GetAll())
    {
        if (tr.UserId == userId)
            trs.push_back(tr);
    }
    return trs;
}

vector<TestResultEntity> TestResultFileRepository::GetByTestId(int testId) {
    vector<TestResultEntity> trs = vector<TestResultEntity>();
    for (auto tr: _db.GetAll())
    {
        if (tr.TestId == testId)
            trs.push_back(tr);
    }
    return trs;
}
