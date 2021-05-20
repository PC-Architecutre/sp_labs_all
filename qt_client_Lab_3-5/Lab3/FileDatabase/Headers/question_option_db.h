//
// Created by misha on 05.03.21.
//

#ifndef SYS_PROG_2ND_COURSE_QUESTION_OPTION_DB_H
#define SYS_PROG_2ND_COURSE_QUESTION_OPTION_DB_H

#include "../../Entities/Headers/question_option.h"
#include <vector>
using namespace Entities;

class QuestionOptionFileDB {
public:
    QuestionOptionFileDB();
    ~QuestionOptionFileDB();

    QuestionOptionEntity& Get(int Id);
    void Add(QuestionOptionEntity& entity);
    void Delete(QuestionOptionEntity& entity);
    void Update(QuestionOptionEntity& entity);
    std::vector<QuestionOptionEntity>& GetAll();
    void SaveChanges();
private:
    void _saveToFile();
    void _readFromFile();
    int _getIndex(int Id);
    std::vector<QuestionOptionEntity> entities;
};

#endif //SYS_PROG_2ND_COURSE_QUESTION_OPTION_DB_H
