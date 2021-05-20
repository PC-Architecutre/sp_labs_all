#ifndef SYS_PROG_2ND_COURSE_TestService_H
#define SYS_PROG_2ND_COURSE_TestService_H
# include "../../DataAccess/SqlRepositories/Headers/UnitOfWorkSqlDB.h"
#include "../../Domain/Headers/test.h"

using namespace Domain;
using namespace SqlRepositories;

class TestService 
{
    public:
        TestService(UnitOfWorkSqlDB* unitOfWork);
        ~TestService();
        vector<Test> GetAllTests();
        Test GetTestById(int id);

    private:
        UnitOfWorkSqlDB* _uof;
};

#endif
