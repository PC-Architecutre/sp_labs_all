#ifndef SYS_PROG_2ND_COURSE_QUESTION_OPTION_REPO_H
#define SYS_PROG_2ND_COURSE_QUESTION_OPTION_REPO_H

#include "../../Entities/Headers/question_option.h"
#include <vector>

using namespace std;
using namespace Entities;

class QuestionOptionRepository
{
public:
    virtual void Add(QuestionOptionEntity& entity) = 0;
    virtual void Remove(QuestionOptionEntity& entity) = 0;
    virtual void Update(QuestionOptionEntity& entity) = 0;
    virtual QuestionOptionEntity& Get(int Id) = 0;
    virtual vector<QuestionOptionEntity>& GetAll() = 0;
    virtual vector<QuestionOptionEntity> GetByQuestionId(int questionId) = 0;
    virtual void Save() = 0;
};

#endif //SYS_PROG_2ND_COURSE_QUESTION_OPTION_REPO_H
