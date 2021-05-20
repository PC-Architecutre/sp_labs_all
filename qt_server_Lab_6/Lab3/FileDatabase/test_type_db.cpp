//
// Created by misha on 05.03.21.
//

#include "Headers/test_type_db.h"
#include <iostream>
#include <fstream>
#define DB_PATH "../Database/TestTypeDB.txt"

TestTypeFileDB::TestTypeFileDB() {
    entities = std::vector<TestTypeEntity>();
    _readFromFile();
}

TestTypeFileDB::~TestTypeFileDB() = default;

std::vector<TestTypeEntity> &TestTypeFileDB::GetAll() {
    return entities;
}

void TestTypeFileDB::Add(TestTypeEntity &entity) {
    entities.push_back(entity);
}

TestTypeEntity& TestTypeFileDB::Get(int Id) {
    return entities.at(_getIndex(Id));
}

void TestTypeFileDB::Delete(TestTypeEntity &entity) {
    entities.erase(entities.begin()+_getIndex(entity.Id));
}

void TestTypeFileDB::Update(TestTypeEntity &entity) {
    int i = _getIndex(entity.Id);
    if (i != -1)
    {
        entities[i] = entity;
    }
}

void TestTypeFileDB::SaveChanges() {
    _saveToFile();
}

void TestTypeFileDB::_saveToFile() {
    std::ofstream out;
    out.open(DB_PATH);
    for (auto & e : entities)
    {
        out << e.Id << std::endl;
        out << e.Name << std::endl;
    }
    out.close();
}

void TestTypeFileDB::_readFromFile() {
    std::ifstream in;
    in.open(DB_PATH);
    std::string nline;

    while (in.peek() != EOF)
    {
        TestTypeEntity e;
        in >> e.Id;
        getline(in, nline);
        getline(in, nline);
        e.Name = nline;
        entities.push_back(e);
    }
    in.close();
}

int TestTypeFileDB::_getIndex(int Id) {
    for (std::vector<TestTypeEntity>::size_type i = 0; i < entities.size(); i++)
    {
        if (entities.at(i).Id == Id)
            return i;
    }
    return -1;
}

