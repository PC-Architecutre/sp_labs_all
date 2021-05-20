//
// Created by koler on 06.03.2021.
//

#ifndef SYS_PROG_2ND_COURSE_1__TESTSERVICE_H
#define SYS_PROG_2ND_COURSE_1__TESTSERVICE_H

# include "../../DataAccess/UnitOfWorkFileDB.h"
# include "../../Mappers/Headers/test_result_mapper.h"
# include "../../Mappers/Headers/user_mapper.h"
# include "../../Domain/Headers/test_result.h"
# include <vector>
using namespace Mappers;
using namespace Domain;
using namespace Entities;

class TestResultService {
public:
    TestResultService(UnitOfWorkFileDB uof);
    ~TestResultService();
    vector<TestResult> GetUserResults(int userId);
    void SaveUserResult(TestResult testResult);

private:
    UnitOfWorkFileDB _uof;
};


#endif //SYS_PROG_2ND_COURSE_1__TESTSERVICE_H
