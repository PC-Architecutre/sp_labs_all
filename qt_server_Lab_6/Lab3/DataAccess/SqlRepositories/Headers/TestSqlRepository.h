//
// Created by artem on 3/28/21.
//

#ifndef CLION_FUCK_QT_TESTSQLREPOSITORY_H
#define CLION_FUCK_QT_TESTSQLREPOSITORY_H

#include "../../Abstract/test_repo.h"
#include "../../../FileDatabase/Headers/test_db.h"
#include <QtSql>

namespace SqlRepositories {
    class TestSqlRepository {
    public:
        explicit TestSqlRepository(QSqlDatabase db);
        ~TestSqlRepository();
        void Add(TestEntity &entity) ;
        void Remove(TestEntity &entity) ;
        void Update(TestEntity &entity) ;
        TestEntity Get(int Id) ;
        vector<TestEntity> GetAll() ;
        void Save() ;

    private:
        QSqlDatabase db;
    };


}

#endif //CLION_FUCK_QT_TESTSQLREPOSITORY_H
