#ifndef SYS_PROG_2ND_COURSE_TestResult_H
#define SYS_PROG_2ND_COURSE_TestResult_H
#include <string>
using namespace std;

namespace Entities 
{
class TestResultEntity
{
public:
    int Id;
    int UserId;
    int TestId;
    int Score;
};
}

#endif
