//
// Created by artem on 3/28/21.
//

#ifndef CLION_FUCK_QT_TESTRESULTSQLREPOSITORY_H
#define CLION_FUCK_QT_TESTRESULTSQLREPOSITORY_H



#include <QSqlDatabase>
#include "../../Abstract/test_result_repo.h"

namespace SqlRepositories {
    class TestResultsSqlRepository {
    public:
        explicit TestResultsSqlRepository(QSqlDatabase db);
        ~TestResultsSqlRepository();
        void Add(TestResultEntity entity);
        void Remove(TestResultEntity entity);
        void Update(TestResultEntity entity);
        TestResultEntity Get(int Id);
        vector <TestResultEntity> GetAll();
        void Save();
        vector<TestResultEntity> GetByUserId(int id);
        vector<TestResultEntity> GetByTestId(int id);

    private:
        QSqlDatabase _db;
    };
}

#endif