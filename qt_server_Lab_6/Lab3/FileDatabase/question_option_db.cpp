//
// Created by misha on 05.03.21.
//

#include "Headers/question_option_db.h"
#include <iostream>
#include <fstream>
#define DB_PATH "../Database/QuestionOptionDB.txt"

QuestionOptionFileDB::QuestionOptionFileDB() {
    entities = std::vector<QuestionOptionEntity>();
    _readFromFile();
}

QuestionOptionFileDB::~QuestionOptionFileDB() = default;

std::vector<QuestionOptionEntity> &QuestionOptionFileDB::GetAll() {
    return entities;
}

void QuestionOptionFileDB::Add(QuestionOptionEntity &entity) {
    entities.push_back(entity);
}

QuestionOptionEntity& QuestionOptionFileDB::Get(int Id) {
    return entities.at(_getIndex(Id));
}

void QuestionOptionFileDB::Delete(QuestionOptionEntity& entity) {
    entities.erase(entities.begin()+_getIndex(entity.Id));
}

void QuestionOptionFileDB::Update(QuestionOptionEntity &entity) {
    int i = _getIndex(entity.Id);
    if (i != -1)
    {
        entities[i] = entity;
    }
}

void QuestionOptionFileDB::SaveChanges() {
    _saveToFile();
}

void QuestionOptionFileDB::_saveToFile() {
    std::ofstream out;
    out.open(DB_PATH);
    for (auto & e : entities)
    {
        out << e.Id << std::endl;
        out << e.QuestionId << std::endl;
        out << e.IsCorrect << std::endl;
        out << e.Text << std::endl;
    }
    out.close();
}

void QuestionOptionFileDB::_readFromFile() {
    std::ifstream in;
    in.open(DB_PATH);
    std::string nline;

    while (in.peek() != EOF)
    {
        QuestionOptionEntity e;
        in >> e.Id;
        getline(in, nline);
        in >> e.QuestionId;
        getline(in, nline);
        in >> e.IsCorrect;
        getline(in, nline);
        getline(in, nline);
        e.Text = nline;
        entities.push_back(e);
    }
    in.close();
}

int QuestionOptionFileDB::_getIndex(int Id) {
    for (std::vector<QuestionOptionEntity>::size_type i = 0; i < entities.size(); i++)
    {
        if (entities.at(i).Id == Id)
            return i;
    }
    return -1;
}

