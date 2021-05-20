#ifndef SYS_PROG_2ND_COURSE_QuestionFILEREPOSITORY_H
#define SYS_PROG_2ND_COURSE_QuestionFILEREPOSITORY_H
#include "../Abstract/question_repo.h"
#include "../../FileDatabase/Headers/question_db.h"

class QuestionFileRepository: public  QuestionRepository {
public:
    QuestionFileRepository();
    void Add(QuestionEntity& entity) override;
    void Remove(QuestionEntity& entity) override;
    void Update(QuestionEntity& entity) override;
    QuestionEntity& Get(int Id) override;
    vector<QuestionEntity>& GetAll() override;
    vector<QuestionEntity> GetByTestId(int testId) override;
    void Save() override;
private:
    QuestionFileDB _db;
};


#endif //SYS_PROG_2ND_COURSE_QuestionFILEREPOSITORY_H
