//
// Created by misha on 28.03.21.
//

#ifndef CLION_FUCK_QT_TESTTYPESQLREPOSITORY_H
#define CLION_FUCK_QT_TESTTYPESQLREPOSITORY_H

#include <QtSql>
#include "../../Abstract/test_repo.h"
#include "../../../Entities/Headers/test_type.h"
using namespace Entities;

namespace SqlRepositories {
    class TestTypeSqlRepository {
    public:
        explicit TestTypeSqlRepository(QSqlDatabase db);
        ~TestTypeSqlRepository();
        void Add(TestTypeEntity &entity) ;
        void Remove(TestTypeEntity &entity) ;
        void Update(TestTypeEntity &entity) ;
        TestTypeEntity Get(int Id) ;
        vector<TestTypeEntity> GetAll() ;
        void Save() ;

    private:
        QSqlDatabase db;
    };

}

#endif //CLION_FUCK_QT_TESTTYPESQLREPOSITORY_H
