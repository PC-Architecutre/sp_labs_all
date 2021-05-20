#include "Headers/question_option.h"

using namespace Domain;

QuestionOption::QuestionOption()
{
}

QuestionOption::~QuestionOption()
{
}
int QuestionOption::GetId() const 
{
   return id; 
}

void QuestionOption::SetId(int id) 
{
    this->id = id;
}

bool QuestionOption::IsCorrect() const
{
    return correct;
}

const string& QuestionOption::GetText() const
{
    return text;
}

void QuestionOption::SetCorrect(bool correct)
{
    this->correct = correct;
}

void QuestionOption::SetText(const string& text)
{
    this->text = text;
}
