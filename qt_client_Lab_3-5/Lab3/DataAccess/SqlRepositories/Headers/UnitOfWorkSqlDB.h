//
// Created by artem on 3/28/21.
//

#ifndef CLION_FUCK_QT_UNITOFWORKSQLDB_H
#define CLION_FUCK_QT_UNITOFWORKSQLDB_H

#include "QuestionSqlRepository.h"
#include "QuestionOptionSqlRepository.h"
#include "TestResultSqlRepository.h"
#include "UserSqlRepository.h"
#include "TestSqlRepository.h"
#include "TestTypeSqlRepository.h"
#include <QtSql>


namespace SqlRepositories {
    class UnitOfWorkSqlDB {
    public:
        UnitOfWorkSqlDB(QSqlDatabase db);

        QuestionSqlRepository* QuestionRepository;
        QuestionOptionSqlRepository* QuestionOptionRepository;
        UserSqlRepository* UserRepository;
        TestResultsSqlRepository* TestResultRepository;
        TestTypeSqlRepository* TestTypeRepository;
        TestSqlRepository* TestRepository;

        void Commit();

        void Rollback();

    private:
        QSqlDatabase _db;
    };
}

#endif //CLION_FUCK_QT_UNITOFWORKSQLDB_H
