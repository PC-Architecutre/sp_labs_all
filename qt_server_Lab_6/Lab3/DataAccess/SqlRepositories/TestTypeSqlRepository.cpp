//
// Created by misha on 28.03.21.
//

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include "Headers/TestTypeSqlRepository.h"

using namespace SqlRepositories;

TestTypeSqlRepository::TestTypeSqlRepository(QSqlDatabase db) {
    this -> db = db;
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString(
            "CREATE TABLE IF NOT EXISTS %1 (%2);").arg("TEST_TYPES",
                                                       "id INTEGER PRIMARY KEY NOT NULL, "
                                                       "name TEXT"
                                                       );
    query.exec(queryString);
}

TestTypeSqlRepository::~TestTypeSqlRepository() {}

void TestTypeSqlRepository::Add(TestTypeEntity &entity) {
    if (!db.isOpen()) db.open();
    QSqlQuery query;
    QString queryString = QString("INSERT INTO TEST_TYPES (%1) VALUES (%2)")
            .arg("id, name",
                 QString("%1, %2").arg(QString(entity.Id),
                                               QString::fromStdString(entity.Name)
                                               ));

}

TestTypeEntity TestTypeSqlRepository::Get(int id) {
    if (! db.isOpen())
        db.open();
    db.open();
    QSqlQuery query;
    QString queryString = QString("SELECT %1 FROM TEST_TYPES WHERE id=%2").arg(
            "id, name", QString(id)
    );
    query.exec(queryString);
    query.next();
    TestTypeEntity t;
    t.Id = query.value(0).toInt();
    t.Name = query.value(1).toString().toStdString();
    return t;
}

vector<TestTypeEntity> TestTypeSqlRepository::GetAll() {
    if (! db.isOpen())
        db.open();
    db.open();
    QSqlQuery query;
    QString queryString = QString("SELECT %1 FROM TEST_TYPES").arg(
            "id, name"
    );
    query.exec(queryString);
    vector<TestTypeEntity> tests;
    while(query.next())
    {
        TestTypeEntity t;
        t.Id = query.value(0).toInt();
        t.Name = query.value(1).toString().toStdString();
        tests.push_back(t);
    }
    return tests;
}

void TestTypeSqlRepository::Remove(TestTypeEntity& entity) {
    if (! db.isOpen())
        db.open();
    db.open();
    QSqlQuery query;
    QString queryString = QString("DELETE FROM TEST_TYPES WHERE id=%1").arg(
            QString(entity.Id)
    );
    query.exec(queryString);
}

void TestTypeSqlRepository::Update(TestTypeEntity& entity) {
    if (! db.isOpen())
        db.open();
    db.open();
    QSqlQuery query;
    QString queryString = QString("UPDATE TEST_TYPES SET %1 WHERE id=%2").arg(
            QString("id =%1, name=%2")
                    .arg(QString(entity.Id), QString::fromStdString(entity.Name)),
            QString(entity.Id)
    );
    query.exec(queryString);
}

void TestTypeSqlRepository::Save() {

}