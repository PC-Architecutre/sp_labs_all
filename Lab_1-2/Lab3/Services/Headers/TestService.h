#ifndef SYS_PROG_2ND_COURSE_TestService_H
#define SYS_PROG_2ND_COURSE_TestService_H
#include "../../DataAccess/UnitOfWorkFileDB.h"
#include "../../Domain/Headers/test.h"

using namespace Domain;

class TestService 
{
    public:
        TestService(UnitOfWorkFileDB unitOfWork);
        ~TestService();
        vector<Test> GetAllTests();
        Test GetTestById(int id);

    private:
        UnitOfWorkFileDB _uof;
};

#endif
