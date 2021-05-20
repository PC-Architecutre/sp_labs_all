//
// Created by misha on 05.03.21.
//

#include "Headers/TestTypeFileRepository.h"

TestTypeFileRepository::TestTypeFileRepository() {
    _db = TestTypeFileDB();
}

void TestTypeFileRepository::Add(TestTypeEntity& entity) {
    _db.Add(entity);
}

TestTypeEntity& TestTypeFileRepository::Get(int Id) {
    return _db.Get(Id);
}

vector<TestTypeEntity>& TestTypeFileRepository::GetAll() {
    return _db.GetAll();
}

void TestTypeFileRepository::Remove(TestTypeEntity& entity) {
    _db.Delete(entity);
}

void TestTypeFileRepository::Update(TestTypeEntity& entity) {
    _db.Update(entity);
}

void TestTypeFileRepository::Save() {
    _db.SaveChanges();
}
