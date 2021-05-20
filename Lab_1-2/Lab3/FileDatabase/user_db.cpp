//
// Created by misha on 05.03.21.
//

#include "Headers/user_db.h"
#include <iostream>
#include <fstream>
#define DB_PATH "./UserDB.txt"

UserFileDB::UserFileDB() {
    entities = std::vector<UserEntity>();
    _readFromFile();
}

UserFileDB::~UserFileDB() = default;

std::vector<UserEntity> &UserFileDB::GetAll() {
    return entities;
}

void UserFileDB::Add(UserEntity &entity) {
    entities.push_back(entity);
}

UserEntity& UserFileDB::Get(int Id) {
    int index = _getIndex(Id);
    return entities.at(index);
}

bool

void UserFileDB::Delete(UserEntity &entity) {
    entities.erase(entities.begin()+_getIndex(entity.Id));
}

void UserFileDB::Update(UserEntity &entity) {
    int i = _getIndex(entity.Id);
    if (i != -1)
    {
        entities[i] = entity;
    }
}

void UserFileDB::SaveChanges() {
    _saveToFile();
}

void UserFileDB::_saveToFile() {
    std::ofstream out;
    out.open(DB_PATH);
    for (auto & e : entities)
    {
        out << e.Id << std::endl;
        out << e.Name << std::endl;
    }
    out.close();
}

void UserFileDB::_readFromFile() {
    std::ifstream in;
    in.open(DB_PATH);
    std::string nline;

    while (in.peek() != EOF)
    {
        UserEntity e;
        in >> e.Id;
        getline(in, nline);
        in >> e.Name;
        getline(in, nline);
        entities.push_back(e);
    }
    in.close();
}

int UserFileDB::_getIndex(int Id) {
    for (std::vector<UserEntity>::size_type i = 0; i < entities.size(); i++)
    {
        if (entities.at(i).Id == Id)
            return i;
    }
    return -1;
}

bool UserFileDB::Exists(int Id) {
    return _getIndex(Id) != -1;
}

