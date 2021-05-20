//
// Created by artem on 3/28/21.
//

#ifndef CLION_FUCK_QT_USERSQLREPOSITORY_H
#define CLION_FUCK_QT_USERSQLREPOSITORY_H


#include "../../Abstract/user_repo.h"
#include <QSql>

namespace SqlRepositories {
    class UserSqlRepository {
    public:
        explicit UserSqlRepository(QSqlDatabase db);
        ~UserSqlRepository();
        void Add(UserEntity entity);
        void Remove(UserEntity entity);
        void Update(UserEntity entity);
        UserEntity Get(int Id);
        vector <UserEntity> GetAll();
        void Save();
        bool Exists(int id);

    private:
        QSqlDatabase db;
    };
}
#endif //CLION_FUCK_QT_USERSQLREPOSITORY_H
