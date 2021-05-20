#ifndef SYS_PROG_2ND_COURSE_QuestionOption_H
#define SYS_PROG_2ND_COURSE_QuestionOption_H
#include <string>

using namespace std;

namespace Entities { 
class QuestionOptionEntity
{
public:
    int Id;
    int QuestionId;
    string Text;
    bool IsCorrect;
};
}

#endif
