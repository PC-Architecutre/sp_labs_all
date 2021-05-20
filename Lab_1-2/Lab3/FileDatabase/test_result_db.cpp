//
// Created by misha on 05.03.21.
//

#include "Headers/test_result_db.h"
#include <iostream>
#include <fstream>
#include <string>
#define DB_PATH "./TestResultDB.txt"

TestResultFileDB::TestResultFileDB() {
    entities = std::vector<TestResultEntity>();
    _readFromFile();
}

TestResultFileDB::~TestResultFileDB() = default;

std::vector<TestResultEntity> &TestResultFileDB::GetAll() {
    return entities;
}

void TestResultFileDB::Add(TestResultEntity &entity) {
    entities.push_back(entity);
}

TestResultEntity& TestResultFileDB::Get(int Id) {
    return entities.at(_getIndex(Id));
}

void TestResultFileDB::Delete(TestResultEntity &entity) {
    entities.erase(entities.begin()+_getIndex(entity.Id));
}

void TestResultFileDB::Update(TestResultEntity &entity) {
    int i = _getIndex(entity.Id);
    if (i != -1)
    {
        entities[i] = entity;
    }
}

void TestResultFileDB::SaveChanges() {
    _saveToFile();
}

void TestResultFileDB::_saveToFile() {
    std::ofstream out;
    out.open(DB_PATH);
    for (auto & e : entities)
    {
        out << e.Id << std::endl;
        out << e.TestId << std::endl;
        out << e.UserId << std::endl;
        out << e.Score << std::endl;
    }
    out.close();
}

void TestResultFileDB::_readFromFile() {
    std::ifstream in;
    in.open(DB_PATH);
    std::string nline;

    while (in.peek() != EOF)
    {
        TestResultEntity e;
        in >> e.Id;
        getline(in, nline);
        in >> e.TestId;
        getline(in, nline);
        in >> e.UserId;
        getline(in, nline);
        in >> e.Score;
        getline(in, nline);
        entities.push_back(e);
    }
    in.close();
}

int TestResultFileDB::_getIndex(int Id) {
    for (std::vector<TestResultEntity>::size_type i = 0; i < entities.size(); i++)
    {
        if (entities.at(i).Id == Id)
            return i;
    }
    return -1;
}

