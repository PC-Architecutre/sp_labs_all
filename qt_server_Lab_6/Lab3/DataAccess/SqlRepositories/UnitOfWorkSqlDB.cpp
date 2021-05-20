//
// Created by artem on 3/28/21.
//

#include "Headers/UnitOfWorkSqlDB.h"
#include <QSql>
using namespace SqlRepositories;

using namespace SqlRepositories;

UnitOfWorkSqlDB::UnitOfWorkSqlDB(QSqlDatabase db) {
    _db = db;
    QuestionRepository = new QuestionSqlRepository(db);
    QuestionOptionRepository = new QuestionOptionSqlRepository(db);
    UserRepository = new UserSqlRepository(db);
    TestResultRepository = new TestResultsSqlRepository(db);
    TestTypeRepository = new TestTypeSqlRepository(db);
    TestRepository = new TestSqlRepository(db);
}

void UnitOfWorkSqlDB::Commit() {
    QuestionRepository->Save();
    QuestionOptionRepository->Save();
    UserRepository->Save();
    TestResultRepository->Save();
    TestTypeRepository->Save();
    TestRepository->Save();
}

void UnitOfWorkSqlDB::Rollback() {
    QuestionRepository = new QuestionSqlRepository(_db);
    QuestionOptionRepository = new QuestionOptionSqlRepository(_db);
    UserRepository = new UserSqlRepository(_db);
    TestResultRepository = new TestResultsSqlRepository(_db);
    TestTypeRepository = new TestTypeSqlRepository(_db);
    TestRepository = new TestSqlRepository(_db);
}
