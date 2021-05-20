//
// Created by misha on 05.03.21.
//

#include "Headers/UserFileRepository.h"

UserFileRepository::UserFileRepository() {
    _db = UserFileDB();
}

void UserFileRepository::Add(UserEntity entity) {
    _db.Add(entity);
}

UserEntity& UserFileRepository::Get(int Id) {
    return _db.Get(Id);
}

vector<UserEntity>& UserFileRepository::GetAll() {
    return _db.GetAll();
}

void UserFileRepository::Remove(UserEntity& entity) {
    _db.Delete(entity);
}

void UserFileRepository::Update(UserEntity& entity) {
    _db.Update(entity);
}

void UserFileRepository::Save() {
    _db.SaveChanges();
}

bool UserFileRepository::Exists(int Id) {
    return _db.Exists(Id);
}
