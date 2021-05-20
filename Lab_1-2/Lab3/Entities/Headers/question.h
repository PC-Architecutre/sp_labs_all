#ifndef SYS_PROG_2ND_COURSE_Question_H
#define SYS_PROG_2ND_COURSE_Question_H
#include <string>
#include <vector>
using namespace std;

namespace Entities 
{
class QuestionEntity
{
public:
    int Id;
    int TestId;
    bool IsMultipleChoice;
    float Points;
    string QuestionText;
};
}

#endif
