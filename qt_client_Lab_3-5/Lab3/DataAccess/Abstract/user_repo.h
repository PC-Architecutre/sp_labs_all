#ifndef SYS_PROG_2ND_COURSE_USER_REPO_H
#define SYS_PROG_2ND_COURSE_USER_REPO_H

#include "../../Entities/Headers/user.h"
#include <vector>

using namespace std;
using namespace Entities;

class UserRepository
{
public:
    virtual void Add(UserEntity entity) = 0;
    virtual void Remove(UserEntity& entity) = 0;
    virtual void Update(UserEntity& entity) = 0;
    virtual UserEntity& Get(int Id) = 0;
    virtual vector<UserEntity>& GetAll() = 0;
    virtual void Save() = 0;
};

#endif //SYS_PROG_2ND_COURSE_USER_REPO_H
