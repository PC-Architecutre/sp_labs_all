#ifndef SYS_PROG_2ND_COURSE_QuestionOptionFILEREPOSITORY_H
#define SYS_PROG_2ND_COURSE_QuestionOptionFILEREPOSITORY_H
#include "../Abstract/question_option_repo.h"
#include "../../FileDatabase/Headers/question_option_db.h"

class QuestionOptionFileRepository: public  QuestionOptionRepository {
public:
    QuestionOptionFileRepository();
    void Add(QuestionOptionEntity& entity) override;
    void Remove(QuestionOptionEntity& entity) override;
    void Update(QuestionOptionEntity& entity) override;
    QuestionOptionEntity& Get(int Id) override;
    vector<QuestionOptionEntity>& GetAll() override;
    vector<QuestionOptionEntity> GetByQuestionId(int questionId) override;
    void Save() override;
private:
    QuestionOptionFileDB _db;
};


#endif //SYS_PROG_2ND_COURSE_QuestionOptionFILEREPOSITORY_H
