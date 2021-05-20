//
// Created by dmytro on 28.03.21.
//

#ifndef CLION_FUCK_QT_QUESTIONOPTIONSQLREPOSITORY_H
#define CLION_FUCK_QT_QUESTIONOPTIONSQLREPOSITORY_H

#include "../../Abstract/question_option_repo.h"
#include "../../../FileDatabase/Headers/question_option_db.h"

#include <QSqlDatabase>

namespace SqlRepositories {
    class QuestionOptionSqlRepository {
    public:
        explicit QuestionOptionSqlRepository(QSqlDatabase db);
        ~QuestionOptionSqlRepository();
        void Add(QuestionOptionEntity &entity) ;
        void Remove(QuestionOptionEntity &entity) ;
        void Update(QuestionOptionEntity &entity) ;
        QuestionOptionEntity Get(int Id) ;
        vector<QuestionOptionEntity> GetAll() ;
        vector<QuestionOptionEntity> GetByQuestionId(int questionId);
        void Save() ;

    private:
        QSqlDatabase db;
    };

}

#endif //CLION_FUCK_QT_QUESTIONOPTIONSQLREPOSITORY_H