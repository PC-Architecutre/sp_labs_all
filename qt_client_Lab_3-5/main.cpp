#include <QApplication>
#include "window.h"
#include "Lab3/Entities/Headers/test.h"
#include "Lab3/DataAccess/SqlRepositories/Headers/TestSqlRepository.h"
#include "Lab3/DataAccess/SqlRepositories/Headers/QuestionSqlRepository.h"
#include "Lab3/DataAccess/SqlRepositories/Headers/QuestionOptionSqlRepository.h"
#include "Lab3/DataAccess/SqlRepositories/Headers/UserSqlRepository.h"
#include "Lab3/DataAccess/SqlRepositories/Headers/TestResultSqlRepository.h"
#include "Lab3/DataAccess/FileRepositories/Headers/TestTypeFileRepository.h"
#include "Lab3/DataAccess/FileRepositories/Headers/QuestionFileRepository.h"
#include "Lab3/DataAccess/FileRepositories/Headers/QuestionOptionFileRepository.h"
#include "Lab3/DataAccess/FileRepositories/Headers/TestResultFileRepository.h"
#include "Lab3/DataAccess/FileRepositories/Headers/UserFileRepository.h"
#include "Lab3/DataAccess/SqlRepositories/Headers/UnitOfWorkSqlDB.h"
#include <QtSql>

using namespace Entities;
using namespace SqlRepositories;
int main(int argc, char *argv[]) {
    srand (time(NULL));
    QApplication a(argc, argv);

//    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
//    dbase.setDatabaseName("test_cpp.sqlite");
//    if (!dbase.open()) {
//        qDebug() << "Something went wrong!";
//        return -1;
//    }

//    auto uof = new UnitOfWorkSqlDB(dbase);
    TestController* tc = new TestController();
    window w(tc);
    w.show();

    return QApplication::exec();
}
