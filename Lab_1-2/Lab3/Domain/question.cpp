#include "Headers/question.h"
#include <vector>
#include <string>
using namespace std;
using namespace Domain;

Question::Question() {}

Question::~Question() {}

int Question::GetId() const 
{
   return id; 
}

void Question::SetId(int id) 
{
    this->id = id;
}

const vector<QuestionOption>& Question::GetOptions() const
{
    return options;
}

void Question::AddOption(const QuestionOption &option)
{
    options.push_back(option);
}

const string& Question::GetQuestionText() const
{
    return text;
}

void Question::SetQuestionText(const string &text)
{
    this->text = text;
}
