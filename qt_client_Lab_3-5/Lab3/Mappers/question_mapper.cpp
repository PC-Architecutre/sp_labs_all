#include <string>
#include "Headers/question_mapper.h"


using namespace Domain;
namespace Mappers
{
    Entities::QuestionEntity QuestionMapper::FromDomainToEntity(Domain::Question question) 
    {
        Entities::QuestionEntity entityQuestion;
        entityQuestion.Id = question.GetId();
        entityQuestion.IsMultipleChoice = question.IsMultipleChoice();
        entityQuestion.QuestionText = question.GetQuestionText();
        entityQuestion.Points = question.GetPoints();
        return entityQuestion;
    }
    Domain::Question QuestionMapper::FromEntityToDomain(Entities::QuestionEntity question)
    {
        Domain::Question domainQuestion;
        domainQuestion.SetId(question.Id);
        domainQuestion.SetQuestionText(question.QuestionText);
        domainQuestion.SetMultipleChoice(question.IsMultipleChoice);
        domainQuestion.SetPoints(question.Points);
        return domainQuestion;
    }
}
