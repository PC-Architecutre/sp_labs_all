#ifndef SYS_PROG_2ND_COURSE_QUESTION_REPO_H
#define SYS_PROG_2ND_COURSE_QUESTION_REPO_H

#include "../../Entities/Headers/question.h"
#include <vector>

using namespace std;
using namespace Entities;

class QuestionRepository
{
public :
    virtual void Add(QuestionEntity& entity) = 0;
    virtual void Remove(QuestionEntity& entity) = 0;
    virtual void Update(QuestionEntity& entity) = 0;
    virtual QuestionEntity& Get(int Id) = 0;
    virtual vector<QuestionEntity>& GetAll() = 0;
    virtual vector<QuestionEntity> GetByTestId(int testId) = 0;
    virtual void Save() = 0;
};

#endif //SYS_PROG_2ND_COURSE_QUESTION_REPO_H
