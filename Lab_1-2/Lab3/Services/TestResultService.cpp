//
// Created by koler on 06.03.2021.
//

#include "Headers/TestResultService.h"

TestResultService::TestResultService(UnitOfWorkFileDB uof) {
    _uof = uof;
}

TestResultService::~TestResultService() {}

vector<TestResult> TestResultService::GetUserResults(int userId) {
    vector<TestResult> trs;

    for (auto tre: _uof.TestResultRepository.GetByUserId(userId))
    {
        trs.push_back(TestResultMapper::FromEntityToDomain(tre));
    }
    return trs;
}

void TestResultService::SaveUserResult(TestResult testResult) {
    // implement
}
