//
// Created by misha on 05.03.21.
//

#include "Headers/QuestionOptionFileRepository.h"

QuestionOptionFileRepository::QuestionOptionFileRepository() {
    _db = QuestionOptionFileDB();
}

void QuestionOptionFileRepository::Add(QuestionOptionEntity& entity) {
    _db.Add(entity);
}

QuestionOptionEntity& QuestionOptionFileRepository::Get(int Id) {
    return _db.Get(Id);
}

vector<QuestionOptionEntity>& QuestionOptionFileRepository::GetAll() {
    return _db.GetAll();
}

void QuestionOptionFileRepository::Remove(QuestionOptionEntity& entity) {
    _db.Delete(entity);
}

void QuestionOptionFileRepository::Update(QuestionOptionEntity& entity) {
    _db.Update(entity);
}

void QuestionOptionFileRepository::Save() {
    _db.SaveChanges();
}

vector<QuestionOptionEntity> QuestionOptionFileRepository::GetByQuestionId(int questionId) {
    vector<QuestionOptionEntity> qos;
    for (auto qo: _db.GetAll())
    {
        if (qo.QuestionId == questionId)
            qos.push_back(qo);
    }
    return qos;
}
