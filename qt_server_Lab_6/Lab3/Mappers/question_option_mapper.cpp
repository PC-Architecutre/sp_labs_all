#include <string>
#include "Headers/question_option_mapper.h"

namespace Mappers
{
    Entities::QuestionOptionEntity QuestionOptionMapper::FromDomainToEntity(Domain::QuestionOption questionOption) 
    {
        Entities::QuestionOptionEntity entityQuestionOption;
        entityQuestionOption.Id = questionOption.GetId();
        entityQuestionOption.IsCorrect = questionOption.IsCorrect();
        entityQuestionOption.Text = questionOption.GetText();
        return entityQuestionOption;
    }
    Domain::QuestionOption QuestionOptionMapper::FromEntityToDomain(Entities::QuestionOptionEntity questionOption)
    {
        Domain::QuestionOption domainQuestionOption;
        domainQuestionOption.SetId(questionOption.Id);
        domainQuestionOption.SetCorrect(questionOption.IsCorrect);
        domainQuestionOption.SetText(questionOption.Text);
        return domainQuestionOption;
    }
}
