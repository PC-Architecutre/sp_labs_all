//
// Created by misha on 05.03.21.
//


#include "Headers/test_db.h"
#include <iostream>
#include <fstream>
#define DB_PATH "../Database/TestDB.txt"

TestFileDB::TestFileDB() {
    entities = std::vector<TestEntity>();
    _readFromFile();
}

TestFileDB::~TestFileDB() = default;

std::vector<TestEntity> &TestFileDB::GetAll() {
    return entities;
}

void TestFileDB::Add(TestEntity &entity) {
    entities.push_back(entity);
}

TestEntity& TestFileDB::Get(int Id) {
    return entities.at(_getIndex(Id));
}

void TestFileDB::Delete(TestEntity &entity) {
    entities.erase(entities.begin()+_getIndex(entity.Id));
}

void TestFileDB::Update(TestEntity &entity) {
    int i = _getIndex(entity.Id);
    if (i != -1)
    {
        entities[i] = entity;
    }
}

void TestFileDB::SaveChanges() {
    _saveToFile();
}

void TestFileDB::_saveToFile() {
    std::ofstream out;
    out.open(DB_PATH);
    for (auto & e : entities)
    {
        out << e.Id << std::endl;
        out << e.Name << std::endl;
        out << e.TestTypeId << std::endl;
        out << e.TimeConstraint << std::endl;
    }
    out.close();
}

void TestFileDB::_readFromFile() {
    std::ifstream in;
    in.open(DB_PATH);
    std::string nline;

    while (in.peek() != EOF)
    {
        TestEntity e;
        in >> e.Id;
        getline(in, nline);
        getline(in, nline);
        e.Name = nline;
        in >> e.TestTypeId;
        getline(in, nline);
        in >> e.TimeConstraint;
        getline(in, nline);
        entities.push_back(e);
    }
    in.close();
}

int TestFileDB::_getIndex(int Id) {
    for (std::vector<TestEntity>::size_type i = 0; i < entities.size(); i++)
    {
        if (entities.at(i).Id == Id)
            return i;
    }
    return -1;
}

