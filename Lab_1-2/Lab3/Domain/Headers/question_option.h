#ifndef SYS_PROG_2ND_COURSE_QuestionOptionDomain_H
#define SYS_PROG_2ND_COURSE_QuestionOptionDomain_H
#include <string>

using namespace std;

namespace Domain { 

class QuestionOption
{
public:
    QuestionOption();
    ~QuestionOption();

    int GetId() const;
    void SetId(int id);

    const string& GetText() const;
    void SetText(const string& text);

    bool IsCorrect() const;
    void SetCorrect(bool correct);

private:
     int id;
     string text;
     bool correct;
};
}

#endif
