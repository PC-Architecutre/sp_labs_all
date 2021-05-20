//
// Created by misha on 05.03.21.
//

#include "Headers/TestFileRepository.h"

TestFileRepository::TestFileRepository() {
    _db = TestFileDB();
}

void TestFileRepository::Add(TestEntity& entity) {
    _db.Add(entity);
}

TestEntity& TestFileRepository::Get(int Id) {
    return _db.Get(Id);
}

vector<TestEntity>& TestFileRepository::GetAll() {
    return _db.GetAll();
}

void TestFileRepository::Remove(TestEntity& entity) {
    _db.Delete(entity);
}

void TestFileRepository::Update(TestEntity& entity) {
    _db.Update(entity);
}

void TestFileRepository::Save() {
    _db.SaveChanges();
}
