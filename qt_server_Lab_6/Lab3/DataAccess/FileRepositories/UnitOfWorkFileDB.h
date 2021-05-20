//
// Created by misha on 05.03.21.
//

#ifndef SYS_PROG_2ND_COURSE_UNITOFWORKFILEDB_H
#define SYS_PROG_2ND_COURSE_UNITOFWORKFILEDB_H

#include "Headers/QuestionFileRepository.h"
#include "Headers/QuestionOptionFileRepository.h"
#include "Headers/TestFileRepository.h"
#include "Headers/TestResultFileRepository.h"
#include "Headers/TestTypeFileRepository.h"
#include "Headers/UserFileRepository.h"

class UnitOfWorkFileDB {
public:
    UnitOfWorkFileDB();
    QuestionFileRepository QuestionRepository;
    QuestionOptionFileRepository QuestionOptionRepository;
    TestFileRepository TestRepository;
    TestResultFileRepository TestResultRepository;
    TestTypeFileRepository TestTypeRepository;
    UserFileRepository UserRepository;
    void Commit();
    void Rollback();
};


#endif //SYS_PROG_2ND_COURSE_UNITOFWORKFILEDB_H
