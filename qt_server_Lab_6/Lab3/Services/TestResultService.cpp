//
// Created by koler on 06.03.2021.
//

#include "Headers/TestResultService.h"
#include "../Mappers/Headers/test_mapper.h"

TestResultService::TestResultService(UnitOfWorkSqlDB* uof) {
    _uof = uof;
}

TestResultService::~TestResultService() {}

vector<TestResult> TestResultService::GetUserResults(int userId) {
    vector<TestResult> trs;

    for (auto tre: _uof->TestResultRepository->GetByUserId(userId))
    {
        TestResult tr = TestResultMapper::FromEntityToDomain(tre);
        Test t = TestMapper::FromEntityToDomain(_uof->TestRepository->Get(tre.TestId));
        Test* test = new Test();
        test->SetId(t.GetId());
        test->SetName(t.GetName());
        test->SetTimeConstrain(t.GetTimeConstraint());
        tr.SetTest(  test );
        User u = UserMapper::FromEntityToDomain(_uof->UserRepository->Get(tre.UserId));
        auto user = new User();
        user->SetName(u.GetName());
        user->SetId(u.GetId());
        tr.SetUser(&u);
        tr.usrname = u.GetName();
        trs.push_back(tr);
    }
    return trs;
}

void TestResultService::SaveUserResult(TestResult testResult) {
    _uof->TestResultRepository->Add(TestResultMapper::FromDomainToEntity(testResult));

    if (!_uof->UserRepository->Exists(testResult.GetUser().GetId()))
    {
        _uof->UserRepository->Add(UserMapper::FromDomainToEntity(testResult.GetUser()));
    }
    _uof->Commit();
}

vector<TestResult> TestResultService::GetResultsByTestId(int testId) {
    vector<TestResult> res;
    for (auto ent : _uof->TestResultRepository->GetByTestId(testId)) {
        TestResult tr = TestResultMapper::FromEntityToDomain(ent);
        Test t = TestMapper::FromEntityToDomain(_uof->TestRepository->Get(ent.TestId));
        Test* test = new Test();
        test->SetId(t.GetId());
        test->SetName(t.GetName());
        test->SetTimeConstrain(t.GetTimeConstraint());
        tr.SetTest(  test );
        User u = UserMapper::FromEntityToDomain(_uof->UserRepository->Get(ent.UserId));
        auto user = new User();
        user->SetName(u.GetName());
        user->SetId(u.GetId());
        tr.SetUser(&u);
        tr.usrname = u.GetName();
        res.push_back(tr);
    }
    return res;
}

