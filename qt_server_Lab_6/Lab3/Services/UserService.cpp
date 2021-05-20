//
// Created by artem on 08.03.21.
//


#include "../DataAccess/FileRepositories/UnitOfWorkFileDB.h"
#include "../Domain/Headers/user.h"
#include "Headers/UserService.h"
#include "../Mappers/Headers/user_mapper.h"
#include "../Mappers/Headers/question_option_mapper.h"
#include <iostream>
#include <vector>

using namespace Domain;
using namespace Mappers;

UserService::UserService(UnitOfWorkSqlDB* uof) {
    _uof = uof;
}

UserService::~UserService() {}

User* UserService::GetUserByName(const string &name) {
    for(UserEntity ent : _uof->UserRepository->GetAll())
    {
        User u = UserMapper::FromEntityToDomain(ent);
        if (u.GetName() == name) {
            auto user = new User();
            user->SetId(u.GetId());
            user->SetName(u.GetName());
            return user;
        }
    }
    return nullptr;
}
