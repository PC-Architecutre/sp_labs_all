//
// Created by misha on 05.03.21.
//

#ifndef Question_db
#define Question_db

#include "../../Entities/Headers/question.h"
#include <vector>
using namespace Entities;

class QuestionFileDB {
public:
    QuestionFileDB();
    ~QuestionFileDB();

    QuestionEntity& Get(int Id);
    void Add(QuestionEntity& entity);
    void Delete(QuestionEntity& entity);
    void Update(QuestionEntity& entity);
    std::vector<QuestionEntity>& GetAll();
    void SaveChanges();
private:
    void _saveToFile();
    void _readFromFile();
    int _getIndex(int Id);
    std::vector<QuestionEntity> entities;
};

#endif