//
// Created by artem on 3/28/21.
//

#include "Headers/TestResultSqlRepository.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace SqlRepositories;

TestResultsSqlRepository::TestResultsSqlRepository(QSqlDatabase db) {
    _db = db;
    if (! _db.isOpen())
        _db.open();
    QSqlQuery query;
    QString queryString = "CREATE TABLE TestResults ("
                          "id INTEGER PRIMARY KEY NOT NULL,"
                          "user_id INTEGER NOT NULL, "
                          "test_id INTEGER NOT NULL, "
                          "score INTEGER NOT NULL, "
                          "FOREIGN KEY (user_id) REFERENCES Users (id), "
                          "FOREIGN KEY (test_id) REFERENCES Tests (id) "
                          ");";
    query.exec(queryString);
}

void TestResultsSqlRepository::Add(TestResultEntity entity) {
    if (! _db.isOpen())
        _db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "INSERT INTO TestResults (user_id, test_id, score) VALUES (" +
            std::to_string(entity.UserId) + ", " +
            std::to_string(entity.TestId) + ", " +
            std::to_string(entity.Score) + ");"
    );
    query.exec(queryString);
}

TestResultEntity TestResultsSqlRepository::Get(int id) {
    if (! _db.isOpen())
        _db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "SELECT id, user_id, test_id, score FROM TestResults WHERE "
            "id = " + std::to_string(id) + ";"
    );
    query.exec(queryString);
    TestResultEntity entity;
    entity.Id = query.value(0).toInt();
    entity.UserId = query.value(1).toInt();
    entity.TestId = query.value(2).toInt();
    entity.Score = query.value(3).toInt();
    return entity;
}

vector<TestResultEntity> TestResultsSqlRepository::GetAll() {
    vector<TestResultEntity> entities;
    if (! _db.isOpen())
        _db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "SELECT id, user_id, test_id, score FROM TestResults; "
    );
    query.exec(queryString);
    while (query.next()) {
        TestResultEntity entity;
        entity.Id = query.value(0).toInt();
        entity.UserId = query.value(1).toInt();
        entity.TestId = query.value(2).toInt();
        entity.Score = query.value(3).toInt();
        entities.push_back(entity);
    }
   return entities;
}

void TestResultsSqlRepository::Remove(TestResultEntity entity) {
    if (! _db.isOpen())
        _db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "DELETE FROM TestResults WHERE id = " + std::to_string(entity.Id) + ";"
    );
    query.exec(queryString);
}

void TestResultsSqlRepository::Update(TestResultEntity entity) {
    if (! _db.isOpen())
        _db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "UPDATE TestResults SET user_id = " + std::to_string(entity.UserId) + ", " +
            "test_id = " + std::to_string(entity.TestId) + ", " +
            "score = " + std::to_string(entity.Score) + " WHERE id = " + std::to_string(entity.Id) + "; "
    );
    query.exec(queryString);
}

void TestResultsSqlRepository::Save() {

}

vector<TestResultEntity> TestResultsSqlRepository::GetByUserId(int id) {
    vector<TestResultEntity> trs;
    if (! _db.isOpen())
        _db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "SELECT id, user_id, test_id, score FROM TestResults WHERE user_id = " + std::to_string(id) + "; "
    );
    query.exec(queryString);
    TestResultEntity entity;
    while (query.next()) {
        TestResultEntity entity;
        entity.Id = query.value(0).toInt();
        entity.UserId = query.value(1).toInt();
        entity.TestId = query.value(2).toInt();
        entity.Score = query.value(3).toInt();
        trs.push_back(entity);
    }
    return trs;
}

vector<TestResultEntity> TestResultsSqlRepository::GetByTestId(int id) {
    vector<TestResultEntity> trs;
    if (! _db.isOpen())
        _db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "SELECT id, user_id, test_id, score FROM TestResults WHERE test_id = " + std::to_string(id) + "; "
    );
    query.exec(queryString);
    TestResultEntity entity;
    while (query.next()) {
        entity.Id = query.value(0).toInt();
        entity.UserId = query.value(1).toInt();
        entity.TestId = query.value(2).toInt();
        entity.Score = query.value(3).toInt();
        trs.push_back(entity);
    }
    return trs;
}
