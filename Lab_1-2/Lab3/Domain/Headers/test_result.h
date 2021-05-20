#ifndef SYS_PROG_2ND_COURSE_TestResultDomain_H
#define SYS_PROG_2ND_COURSE_TestResultDomain_H
#include <string>

using namespace std;

namespace Domain { 
class User;
class Test;

    class User;
class TestResult
{
public:
    TestResult();
    ~TestResult();

    int GetId() const;
    void SetId(int score);

    int GetScore() const;
    void SetScore(int score);

    User GetUser() const;
    void SetUser(User user);

    Test GetTest() const;
    void SetTest(Test test);


private:
    User* user;
    int id;
    int score;
    Test *test;
};
}
#endif
