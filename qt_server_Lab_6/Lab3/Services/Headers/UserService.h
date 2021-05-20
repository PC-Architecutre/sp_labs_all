//
// Created by artem on 08.03.21.
//

#ifndef CLION_FUCK_QT_USERSERVICE_H
#define CLION_FUCK_QT_USERSERVICE_H

# include "../../DataAccess/SqlRepositories/Headers/UnitOfWorkSqlDB.h"
#include "../../Domain/Headers/user.h"

using namespace Domain;
using namespace SqlRepositories;
class UserService {
public:
    UserService(UnitOfWorkSqlDB* unitOfWork);
    ~UserService();
    User* GetUserByName(const string& name);
private:
    UnitOfWorkSqlDB* _uof;
};


#endif //CLION_FUCK_QT_USERSERVICE_H
