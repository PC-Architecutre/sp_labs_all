//
// Created by misha on 06.04.21.
//

#ifndef QT_SERVER_PARSER_H
#define QT_SERVER_PARSER_H
#include <string>
#include <QJsonValue>
#include "Lab3/Controllers/test_controller.h"

using namespace std;

static const QString& GET_TEST_BY_ID_REQ = "GetTestById";
static const QString& GET_ALL_TESTS_REQ = "GetAllTests";
static const QString& SAVE_USER_RES_REQ = "SaveUserResult";
static const QString& GET_USER_BY_NAME_REQ = "GetUserByName";
static const QString& GET_USER_RES_REQ = "GetUserResults";
static const QString& GET_RES_BY_TEST_ID_REQ = "GetResultsByTestId";
static const QString& TYPE_VAL = "type";

static const QString& ID = "id";
static const QString& NAME = "name";
static const QString& TIME_CONSTRAINT = "timeConstraint";
static const QString& QUESTIONS = "questions";
// Question
static const QString& TEST_ID = "testId";
static const QString& IS_MULT_CHOICE = "isMultipleChoice";
static const QString& POINTS = "points";
static const QString& QUESTION_TEXT = "questionText";
static const QString& QUESTION_OPTIONS = "question_options";
// QuestionOption
static const QString& QUESTION_ID = "questionId";
static const QString& TEXT = "text";
static const QString& IS_CORRECT = "isCorrect";

// TestResult
static const QString& USER_ID = "userId";
static const QString& SCORE = "score";
static const QString& USER = "user";
static const QString& TEST = "test";
// User (already done)

// Server constants
static const QString& STATUS = "status";
static const QString& RESULT = "response";

class Parser : QObject {
    Q_OBJECT



public:
    Parser(TestController *tc);
    QJsonObject parse(QJsonObject request);

private:
    TestController* _tc;
    QJsonObject getTest(Test t);
};


#endif //QT_SERVER_PARSER_H
