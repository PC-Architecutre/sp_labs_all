//
// Created by dmytro on 28.03.21.
//

#ifndef CLION_FUCK_QT_QUESTIONSQLREPOSITORY_H
#define CLION_FUCK_QT_QUESTIONSQLREPOSITORY_H

#include "../../Abstract/question_repo.h"
#include "../../../FileDatabase/Headers/question_db.h"
#include <QString>
#include <QSqlDatabase>

namespace SqlRepositories {
    class QuestionSqlRepository {
    public:
        explicit QuestionSqlRepository(QSqlDatabase db);
        ~QuestionSqlRepository();
        void Add(QuestionEntity &entity) ;
        void Remove(QuestionEntity &entity) ;
        void Update(QuestionEntity &entity) ;
        QuestionEntity Get(int Id) ;
        vector<QuestionEntity> GetAll() ;
        vector<QuestionEntity> GetByTestId(int testId);
        void Save() ;

    private:
        QSqlDatabase db;
    };

}

#endif //CLION_FUCK_QT_QUESTIONSQLREPOSITORY_H