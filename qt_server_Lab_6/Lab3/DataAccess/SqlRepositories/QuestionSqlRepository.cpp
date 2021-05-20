//
// Created by dmytro on 28.03.21.
//

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "Headers/QuestionSqlRepository.h"
#include <QVariant>
using namespace SqlRepositories;

QuestionSqlRepository::QuestionSqlRepository(QSqlDatabase db) {
    this->db = db;
    if (!db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Create table Questions "
                                                 "(Id Integer Primary key,"
                                                 "IsMultipleChoice Text not null,"
                                                 "QuestionText Text not null,"
                                                 "Points Integer not null,"
                                                 "TestId Integer not null,"
                                                 "foreign key (TestId) References Tests(Id))");

    query.exec(queryString);
}

QuestionSqlRepository::~QuestionSqlRepository() {}

void QuestionSqlRepository::Add(QuestionEntity &entity)
{
    if (!db.isOpen()) {
        db.open();
    }
    QSqlQuery query;
    QString queryString = QString::fromStdString("Insert into Questions "
                                                 "Values (" + std::to_string(entity.Id) + ", " +
                                                 std::to_string(entity.IsMultipleChoice)  + ", " + "\"" +
                                                 entity.QuestionText +  "\"" + ", " + std::to_string(entity.Points) + std::to_string(entity.TestId) + ")");
    string s = queryString.toStdString();
    query.exec(queryString);
}

QuestionEntity QuestionSqlRepository::Get(int id) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Select * from Questions where id=" + std::to_string(id));
    query.exec(queryString);

    QuestionEntity question;

    question.Id = query.value(0).toInt();
    question.IsMultipleChoice = query.value(1).toBool();
    question.QuestionText = query.value(2).toString().toStdString();
    question.Points = query.value(3).toInt();
    question.TestId = query.value(4).toInt();

    return question;
}

vector<QuestionEntity> QuestionSqlRepository::GetAll() {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Select * from Questions");
    query.exec(queryString);

    vector<QuestionEntity> questions;

    while(query.next()) {
        QuestionEntity question;

        question.Id = query.value(0).toInt();
        question.IsMultipleChoice = query.value(1).toBool();
        question.QuestionText = query.value(2).toString().toStdString();
        question.Points = query.value(3).toInt();
        question.TestId = query.value(4).toInt();

        questions.push_back(question);
    }
    return questions;
}

void QuestionSqlRepository::Remove(QuestionEntity& entity) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Delete from Questions where id=" + std::to_string(entity.Id));
    query.exec(queryString);
}

void QuestionSqlRepository::Update(QuestionEntity& entity) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Update " + std::to_string(entity.Id));
    query.exec(queryString);
}

vector<QuestionEntity> QuestionSqlRepository::GetByTestId(int testId) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Select * from Questions where TestId=" + std::to_string(testId));
    query.exec(queryString);

    vector<QuestionEntity> questions;

    while(query.next()) {
        QuestionEntity question;

        question.Id = query.value(0).toInt();
        question.IsMultipleChoice = query.value(1).toBool();
        question.QuestionText = query.value(2).toString().toStdString();
        question.Points = query.value(3).toInt();
        question.TestId = query.value(4).toInt();

        questions.push_back(question);
    }
    return questions;
}

void QuestionSqlRepository::Save() {

}

