#ifndef SYS_PROG_2ND_COURSE_QuestionDomain_H
#define SYS_PROG_2ND_COURSE_QuestionDomain_H
#include <string>
#include <vector>
#include "question_option.h"
using namespace std;

namespace Domain { 

class Question
{
public:
    Question();
    ~Question();

    int GetId() const;
    void SetId(int id);

    const string& GetQuestionText() const;
    void SetQuestionText(const string& text);

    bool IsMultipleChoice() const;
    void SetMultipleChoice(bool mchoice);

    float GetPoints() const;
    void SetPoints(float points);

    const vector<QuestionOption>& GetOptions() const;
    void AddOption(const QuestionOption& option);
    void RemoveOption(const QuestionOption& option);

private:
    int id;
    bool multipleChoice;
    string text;
    float points;
    vector<QuestionOption> options;
};

}

#endif
