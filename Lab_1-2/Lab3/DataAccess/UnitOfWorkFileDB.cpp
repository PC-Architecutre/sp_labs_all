//
// Created by misha on 05.03.21.
//

#include "UnitOfWorkFileDB.h"

UnitOfWorkFileDB::UnitOfWorkFileDB() {
    QuestionRepository = QuestionFileRepository();
    QuestionOptionRepository = QuestionOptionFileRepository();
    TestRepository = TestFileRepository();
    TestResultRepository = TestResultFileRepository();
    TestTypeRepository = TestTypeFileRepository();
    UserRepository = UserFileRepository();
}

void UnitOfWorkFileDB::Commit() {
    QuestionRepository.Save();
    QuestionOptionRepository.Save();
    TestRepository.Save();
    TestResultRepository.Save();
    TestTypeRepository.Save();
    UserRepository.Save();
}

void UnitOfWorkFileDB::Rollback() {
    QuestionRepository = QuestionFileRepository();
    QuestionOptionRepository = QuestionOptionFileRepository();
    TestRepository = TestFileRepository();
    TestResultRepository = TestResultFileRepository();
    TestTypeRepository = TestTypeFileRepository();
    UserRepository = UserFileRepository();
}
