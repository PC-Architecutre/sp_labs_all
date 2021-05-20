//
// Created by misha on 05.03.21.
//

#include "Headers/QuestionFileRepository.h"

QuestionFileRepository::QuestionFileRepository() {
    _db = QuestionFileDB();
}

void QuestionFileRepository::Add(QuestionEntity &entity) {

}

QuestionEntity& QuestionFileRepository::Get(int Id) {
    return _db.Get(Id);
}

vector<QuestionEntity>& QuestionFileRepository::GetAll() {
    return _db.GetAll();
}

void QuestionFileRepository::Remove(QuestionEntity& entity) {
    _db.Delete(entity);
}

void QuestionFileRepository::Update(QuestionEntity& entity) {
    _db.Update(entity);
}

void QuestionFileRepository::Save() {
    _db.SaveChanges();
}

vector<QuestionEntity> QuestionFileRepository::GetByTestId(int testId) {
    vector<QuestionEntity> qs;
    for (const auto& q: _db.GetAll())
    {
        if (q.TestId == testId)
            qs.push_back(q);
    }
    return qs;
}
