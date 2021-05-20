#ifndef SYS_PROG_2ND_COURSE_TestDomain_H
#define SYS_PROG_2ND_COURSE_TestDomain_H
#include <vector>
#include <string>
#include "question.h"
#include <vector>
#include "test_result.h"

using namespace std;

namespace Domain 
{ 
    class Test
    {
        public:
            Test();
            ~Test();

            int GetId() const;
            void SetId(int id);

            int GetTimeConstraint() const;
            void SetTimeConstrain(int time);

            const string& GetName() const;
            void SetName(const string& name);

            const vector<Question>& GetQuestions() const;
            void AddQuestion(Question& question);

            const vector<TestResult>& GetTestResults() const;
            void AddTestResult(const TestResult& option);
            void RemoveTestResult(const TestResult& option);

        private:
            int id;
            vector<Question> questions;
            vector<TestResult> testResults;
            string name;
            int timeConstraint;
    };
} 

#endif
