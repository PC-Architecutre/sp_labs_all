//
// Created by artem on 3/28/21.
//

#include <QSqlDatabase>
#include <QSqlQuery>
#include "Headers/UserSqlRepository.h"
#include <QVariant>

using namespace SqlRepositories;

UserSqlRepository::UserSqlRepository(QSqlDatabase db) {
    this -> db = db;
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = "CREATE TABLE Users ("
    "id INTEGER PRIMARY KEY NOT NULL,"
    "name TEXT"
    ");";
    query.exec(queryString);
}

void UserSqlRepository::Add(UserEntity entity) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString =  QString::fromStdString( "INSERT INTO Users (id, name) VALUES (" +
                   std::to_string(entity.Id) + ", " +
                    "\"" + entity.Name + "\"" +
                    ");"
            );
    query.exec(queryString);
}

UserEntity UserSqlRepository::Get(int Id) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "SELECT id, name FROM Users WHERE id = " + std::to_string(Id) + ";"
            );
    query.exec(queryString);
    query.next();
    UserEntity u;
    u.Id = query.value(0).toInt();
    u.Name = query.value(1).toString().toStdString();
    return u;
}

vector<UserEntity> UserSqlRepository::GetAll() {
    vector<UserEntity> users;
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "SELECT id, name FROM Users;"
    );
    query.exec(queryString);
    UserEntity u;
    while (query.next()) {
        u.Id = query.value(0).toInt();
        u.Name = query.value(1).toString().toStdString();
        users.push_back(u);
    }
    return users;
}

void UserSqlRepository::Remove(UserEntity entity) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "DELETE FROM Users WHERE id = " + std::to_string(entity.Id) + ";"
            );
    query.exec(queryString);
}

void UserSqlRepository::Update(UserEntity entity) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "UPDATE Users SET name = \"" + entity.Name + "\" WHERE id = " + std::to_string(entity.Id) + ";"
    );
    query.exec(queryString);
}

void UserSqlRepository::Save() {

}

bool UserSqlRepository::Exists(int id) {
    if (! db.isOpen())
        db.open();
    QSqlQuery query;
    QString queryString = QString::fromStdString(
            "SELECT id, name FROM Users WHERE id = " + std::to_string(id) + ";"
    );
    query.exec(queryString);
    return query.next();
}
