//
// Created by artem on 3/28/21.
//

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include "Headers/TestSqlRepository.h"
#include <QVariant>
using namespace SqlRepositories;

TestSqlRepository::TestSqlRepository(QSqlDatabase db) {
    this -> db = db;
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString(
            "CREATE TABLE IF NOT EXISTS %1 (%2);").arg("TESTS",
                                                       "id INTEGER PRIMARY KEY NOT NULL, "
                                                       "name TEXT, "
                                                       "test_type_id INTEGER, "
                                                       "time_constraint INTEGER, "
                                                       "FOREIGN KEY(test_type_id) REFERENCES TEST_TYPES (id)");
    query.exec(queryString);
}

TestSqlRepository::~TestSqlRepository() {}

void TestSqlRepository::Add(TestEntity &entity) {
    if (!db.isOpen()) db.open();
    QSqlQuery query;
    QString queryString = QString("INSERT INTO TESTS (%1) VALUES (%2)")
            .arg("id, name, test_type_id, time_constraint",
                 QString("%1, \"%2\", %3, %4").arg(QString::number(entity.Id),
                                               QString::fromStdString(entity.Name),
                                               QString::number(entity.TestTypeId),
                                               QString::number(entity.TimeConstraint)));
    auto s = queryString.toStdString();
    query.exec(queryString);

}

TestEntity TestSqlRepository::Get(int id) {
    if (! db.isOpen())
        db.open();
    db.open();
    QSqlQuery query;
    QString queryString = QString("SELECT %1 FROM TESTS WHERE id=%2").arg(
            "id, name, test_type_id, time_constraint", QString::number(id)
    );
    query.exec(queryString);
    query.next();
    TestEntity t;
    t.Id = query.value(0).toInt();
    t.Name = query.value(1).toString().toStdString();
    t.TestTypeId = query.value(2).toInt();
    t.TimeConstraint = query.value(3).toInt();
    return t;
}

vector<TestEntity> TestSqlRepository::GetAll() {
    if (! db.isOpen())
        db.open();
    db.open();
    QSqlQuery query;
    QString queryString = QString("SELECT %1 FROM TESTS").arg(
            "id, name, test_type_id, time_constraint"
    );
    query.exec(queryString);
    vector<TestEntity> tests;
    while(query.next())
    {
        TestEntity t;
        t.Id = query.value(0).toInt();
        t.Name = query.value(1).toString().toStdString();
        t.TestTypeId = query.value(2).toInt();
        t.TimeConstraint = query.value(3).toInt();
        tests.push_back(t);
    }
    return tests;
}

void TestSqlRepository::Remove(TestEntity& entity) {
    if (! db.isOpen())
        db.open();
    db.open();
    QSqlQuery query;
    QString queryString = QString("DELETE FROM TESTS WHERE id=%1").arg(
            QString::number(entity.Id)
    );
    query.exec(queryString);
}

void TestSqlRepository::Update(TestEntity& entity) {
    if (! db.isOpen())
        db.open();
    db.open();
    QSqlQuery query;
    QString queryString = QString("UPDATE TESTS SET %1 WHERE id=%2").arg(
            QString("id =%1, name=%2, test_type_id=%3, time_constraint=%4")
            .arg(QString::number(entity.Id), QString::fromStdString(entity.Name), QString::number(entity.TestTypeId), QString::number(entity.TimeConstraint)),
                                                                                QString::number(entity.Id)
    );
    query.exec(queryString);
}

void TestSqlRepository::Save() {

}
