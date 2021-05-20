//
// Created by misha on 05.03.21.
//

#include "Headers/question_db.h"
#include <iostream>
#include <fstream>
#define DB_PATH "./QuestionDB.txt"

QuestionFileDB::QuestionFileDB() {
    entities = std::vector<QuestionEntity>();
    _readFromFile();
}

QuestionFileDB::~QuestionFileDB() = default;

std::vector<QuestionEntity> &QuestionFileDB::GetAll() {
    return entities;
}

void QuestionFileDB::Add(QuestionEntity &entity) {
    entities.push_back(entity);
}

QuestionEntity& QuestionFileDB::Get(int Id) {
    return entities.at(_getIndex(Id));
}

void QuestionFileDB::Delete(QuestionEntity &entity) {
    entities.erase(entities.begin()+_getIndex(entity.Id));
}

void QuestionFileDB::Update(QuestionEntity &entity) {
    int i = _getIndex(entity.Id);
    if (i != -1)
    {
        entities[i] = entity;
    }
}

void QuestionFileDB::SaveChanges() {
    _saveToFile();
}

void QuestionFileDB::_saveToFile() {
    std::ofstream out;
    out.open(DB_PATH);
    for (auto & e : entities)
    {
        out << e.Id << std::endl;
        out << e.TestId << std::endl;
        out << e.IsMultipleChoice << std::endl;
        out << e.QuestionText << std::endl;
        out << e.Points << std::endl;
    }
    out.close();
}

void QuestionFileDB::_readFromFile() {
    std::ifstream in;
    in.open(DB_PATH);
    std::string nline;

    while (in.peek() != EOF)
    {
        QuestionEntity e;
        in >> e.Id;
        getline(in, nline);
        in >> e.TestId;
        getline(in, nline);
        in >> e.IsMultipleChoice;
        getline(in, nline);
        in >> e.QuestionText;
        getline(in, nline);
        in >> e.Points;
        getline(in, nline);
        entities.push_back(e);
    }
    in.close();
}

int QuestionFileDB::_getIndex(int Id) {
    for (std::vector<QuestionEntity>::size_type i = 0; i < entities.size(); i++)
    {
        if (entities.at(i).Id == Id)
            return i;
    }
    return -1;
}

