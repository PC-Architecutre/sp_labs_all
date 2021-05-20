#include <string>
#include "../Domain/Headers/user.h"
#include "../Domain/Headers/test.h"
#include "Headers/test_result_mapper.h"

namespace Mappers
{
     Entities::TestResultEntity TestResultMapper::FromDomainToEntity(Domain::TestResult testResult) 
    {
        Entities::TestResultEntity entityTestResult;
        entityTestResult.Id = testResult.GetId();
        entityTestResult.Score = testResult.GetScore();
        entityTestResult.UserId = testResult.GetUser().GetId();
        entityTestResult.TestId = testResult.GetTest().GetId();
        return entityTestResult;
    }

    Domain::TestResult TestResultMapper::FromEntityToDomain(Entities::TestResultEntity testResult)
    {
        Domain::TestResult domainTestResult;
        domainTestResult.SetId(testResult.Id);
        domainTestResult.SetScore(testResult.Score);
        return domainTestResult;
    }
}
