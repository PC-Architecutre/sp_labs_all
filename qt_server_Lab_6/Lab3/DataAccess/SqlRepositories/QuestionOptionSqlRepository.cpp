//
// Created by dmytro on 28.03.21.
//

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "Headers/QuestionOptionSqlRepository.h"
#include <QVariant>
using namespace SqlRepositories;

QuestionOptionSqlRepository::QuestionOptionSqlRepository(QSqlDatabase db) {
    this->db = db;
    if (!db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Create table QuestionOptions "
                                                 "(Id Integer Primary key,"
                                                 "Text Text not null,"
                                                 "IsCorrect Text not null,"
                                                 "QuestionId Integer not null,"
                                                 "foreign key (QuestionId) References Questions(Id))");

    query.exec(queryString);
}

QuestionOptionSqlRepository::~QuestionOptionSqlRepository() {}

void QuestionOptionSqlRepository::Add(QuestionOptionEntity &entity)
{
    if (!db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Insert into QuestionOptions "
                                                 "Values (" + std::to_string(entity.Id) + ", " +
                                                 + "\"" + entity.Text + "\"" + ", " +
                                                 std::to_string(entity.IsCorrect) + ", " +
                                                 std::to_string(entity.QuestionId) + ")");
    query.exec(queryString);
}

QuestionOptionEntity QuestionOptionSqlRepository::Get(int id) {
    if (!db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Select * from QuestionOptions where id=" + std::to_string(id));
    query.exec(queryString);

    QuestionOptionEntity questionOption;
    questionOption.Id = query.value(0).toInt();
    questionOption.Text = query.value(1).toString().toStdString();
    questionOption.IsCorrect = query.value(2).toBool();
    questionOption.QuestionId = query.value(3).toInt();

    return questionOption;
}

vector<QuestionOptionEntity> QuestionOptionSqlRepository::GetAll() {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Select * from QuestionOptions");
    query.exec(queryString);

    vector<QuestionOptionEntity> questionOptions;
    while(query.next()) {
        QuestionOptionEntity questionOption;

        questionOption.Id = query.value(0).toInt();
        questionOption.Text = query.value(1).toString().toStdString();
        questionOption.IsCorrect = query.value(2).toBool();
        questionOption.QuestionId = query.value(3).toInt();

        questionOptions.push_back(questionOption);

    }
    return questionOptions;
}

void QuestionOptionSqlRepository::Remove(QuestionOptionEntity& entity) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Delete from QuestionOptions where id=" + std::to_string(entity.Id));
    query.exec(queryString);
}

void QuestionOptionSqlRepository::Update(QuestionOptionEntity& entity) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Update " + std::to_string(entity.Id));
    query.exec(queryString);
}

vector<QuestionOptionEntity> QuestionOptionSqlRepository::GetByQuestionId(int questionId) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString("Select * from QuestionOptions where QuestionId=" + std::to_string(questionId));
    query.exec(queryString);

    vector<QuestionOptionEntity> questionOptions;

    while(query.next()) {
        QuestionOptionEntity questionOption;

        questionOption.Id = query.value(0).toInt();
        questionOption.Text = query.value(1).toString().toStdString();
        questionOption.IsCorrect = query.value(2).toBool();
        questionOption.QuestionId = query.value(3).toInt();

        questionOptions.push_back(questionOption);
    }
    return questionOptions;
}

void QuestionOptionSqlRepository::Save() {

}