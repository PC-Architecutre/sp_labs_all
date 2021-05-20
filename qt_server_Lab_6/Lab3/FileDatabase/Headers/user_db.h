//
// Created by misha on 05.03.21.
//

#ifndef SYS_PROG_2ND_COURSE_USER_DB_H
#define SYS_PROG_2ND_COURSE_USER_DB_H

#include "../../Entities/Headers/user.h"
#include <vector>
using namespace Entities;


class UserFileDB {
public:
    UserFileDB();
    ~UserFileDB();

    UserEntity& Get(int Id);
    void Add(UserEntity& entity);
    void Delete(UserEntity& entity);
    void Update(UserEntity& entity);
    bool Exists(int Id);
    std::vector<UserEntity>& GetAll();
    void SaveChanges();
private:
    void _saveToFile();
    void _readFromFile();
    int _getIndex(int Id);
    std::vector<UserEntity> entities;
};

#endif //SYS_PROG_2ND_COURSE_USER_DB_H
