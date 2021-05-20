#ifndef SYS_PROG_2ND_COURSE_TestService_CPP
#define SYS_PROG_2ND_COURSE_TestService_CPP
#include "../DataAccess/FileRepositories/UnitOfWorkFileDB.h"
#include "../Domain/Headers/test.h"
#include "Headers/TestService.h"
#include "../Mappers/Headers/test_mapper.h"
#include "../Mappers/Headers/question_mapper.h"
#include "../Mappers/Headers/question_option_mapper.h"
#include <vector>

using namespace Domain;
using namespace Mappers;

TestService::TestService(UnitOfWorkSqlDB* uof)
{
    _uof = uof;
}

TestService::~TestService() {}

vector<Test> TestService::GetAllTests()
{
    vector<Test> tests;
    for (auto ent : _uof->TestRepository->GetAll())
    {
        tests.push_back(TestMapper::FromEntityToDomain(ent));
    }
    return tests;
}

Test TestService::GetTestById(int id)
{
    TestEntity ent = _uof->TestRepository->Get(id);
    Test test = TestMapper::FromEntityToDomain(ent);

    for (auto questionEnt : _uof->QuestionRepository->GetByTestId(id))
    {
        Question question = QuestionMapper::FromEntityToDomain(questionEnt);
        for (auto questionOptionEnt : _uof->QuestionOptionRepository->GetByQuestionId(question.GetId()))
        {
            QuestionOption questionOption = QuestionOptionMapper::FromEntityToDomain(questionOptionEnt);
            question.AddOption(questionOption);
        }
        test.AddQuestion(question);
    }

    return test;
}

#endif
