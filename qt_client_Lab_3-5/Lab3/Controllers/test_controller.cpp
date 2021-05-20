#ifndef SYS_PROG_2ND_COURSE_TestController_CPP
#define SYS_PROG_2ND_COURSE_TestController_CPP

#include "../Domain/Headers/test.h"
#include "test_controller.h"
#include <vector>
#include <QJsonArray>
#include "../Domain/Headers/user.h"
#include <stdio.h>
#include <iostream>
#include <QDebug>


#define ADDRESS "127.0.0.1"
#define PORT 8888

using namespace Domain;

const QString& GET_TEST_BY_ID_REQ = "GetTestById";
const QString& GET_ALL_TESTS_REQ = "GetAllTests";
const QString& SAVE_USER_RES_REQ = "SaveUserResult";
const QString& GET_USER_BY_NAME_REQ = "GetUserByName";
const QString& GET_USER_RES_REQ = "GetUserResults";
const QString& GET_RES_BY_TEST_ID_REQ = "GetResultsByTestId";
const QString& TYPE_VAL = "type";

const QString& ID = "id";
const QString& NAME = "name";
const QString& TIME_CONSTRAINT = "timeConstraint";
const QString& QUESTIONS = "questions";
// Question
const QString& TEST_ID = "testId";
const QString& IS_MULT_CHOICE = "isMultipleChoice";
const QString& POINTS = "points";
const QString& QUESTION_TEXT = "questionText";
const QString& QUESTION_OPTIONS = "question_options";
// QuestionOption
const QString& QUESTION_ID = "questionId";
const QString& TEXT = "text";
const QString& IS_CORRECT = "isCorrect";

// TestResult
const QString& USER_ID = "userId";
const QString& SCORE = "score";
const QString& USER = "user";
const QString& TEST = "test";
// User (already done)

// Server constants
const QString& STATUS = "status";
const QString& RESULT = "response";

TestController::TestController(QObject *parent) : QObject(parent)
{
    clientSocket = new QTcpSocket(this);
//    connect(clientSocket, &QTcpSocket::connected, this, &TestController::connectToServer);
    connect(clientSocket, &QTcpSocket::disconnected, this, &TestController::disconnectFromHost);
    connect(clientSocket, &QTcpSocket::readyRead, this, &TestController::onReadyRead);

    QHostAddress address;
    address.setAddress(ADDRESS);
    connectToServer(address, PORT);
}

TestController::~TestController() {}

void TestController::WaitUntilConnect() {

}

void TestController::disconnectFromHost() {
    clientSocket->disconnectFromHost();
}

void TestController::connectToServer(const QHostAddress &address, quint16 port) {
    cout << "Start connecting..." << endl;
    QEventLoop loop;
    connect(clientSocket, &QTcpSocket::connected, &loop, &QEventLoop::quit);
    clientSocket->connectToHost(address, port);
    loop.exec();
    qDebug () <<  "Connected! ";
}

Test TestController::GetTestById(int id)
{
    qDebug() << "Getting test by id ... ";
    QJsonObject json;
    json[TYPE_VAL] = GET_TEST_BY_ID_REQ;
    json[ID] = id;
    QEventLoop loop;
    connect(this, &TestController::dataAcquired, &loop, &QEventLoop::quit);
    SendMessage(json);
    loop.exec();
    return _gotTestById;
}

vector<Test> TestController::GetAllTests()
{
    QJsonObject json;
    json[TYPE_VAL] = GET_ALL_TESTS_REQ;
    qDebug() << "Getting all tests...";
    QEventLoop loop;
    connect(this, &TestController::dataAcquired, &loop, &QEventLoop::quit);
    SendMessage(json);
    loop.exec();
    return _gotTests;
}

void TestController::SaveUserResult(TestResult testResult)
{
    QJsonObject json;
    json[TYPE_VAL] = SAVE_USER_RES_REQ;
    json[ID] = testResult.GetId();
    json[SCORE] = testResult.GetScore();
    QJsonObject userObj;
    userObj.insert(ID , testResult.GetUser().GetId());
    userObj.insert(NAME, testResult.GetUser().GetName().c_str());
    json[USER] = userObj;
    QJsonObject testObj;
    testObj.insert(ID, testResult.GetTest().GetId());
    json[TEST] = testObj;
    QEventLoop loop;
    connect(this, &TestController::dataAcquired, &loop, &QEventLoop::quit);
    SendMessage(json);
    loop.exec();
}

User* TestController::GetUserByName(const QString *str) {
    QJsonObject json;
    json[TYPE_VAL] = GET_USER_BY_NAME_REQ;
    json[NAME] = str->toStdString().c_str();
    cout << "Getting user by name...";
    QEventLoop loop;
    connect(this, &TestController::dataAcquired, &loop, &QEventLoop::quit);
    SendMessage(json);
    loop.exec();
    cout << "User acquired!";
    return _gotUser;
}

vector<TestResult> TestController::GetUserResults(User &user) {
    QJsonObject json;
    json[TYPE_VAL] = GET_USER_RES_REQ;
    json[NAME] = user.GetName().c_str();
    json[ID] = user.GetId();
    QEventLoop loop;
    connect(this, &TestController::dataAcquired, &loop, &QEventLoop::quit);
    SendMessage(json);
    loop.exec();
    return _gotTestResults;
}

vector<TestResult> TestController::GetResultsByTestId(int testId) {
    QJsonObject json;
    json[TYPE_VAL] = GET_RES_BY_TEST_ID_REQ;
    json[TEST_ID] = testId;
    QEventLoop loop;
    connect(this, &TestController::dataAcquired, &loop, &QEventLoop::quit);
    SendMessage(json);
    loop.exec();
    return _gotTestResults;
}

void TestController::SendMessage(const QJsonObject &json)
{
    qDebug() << "Sending message ...";
    const QByteArray jsonData = QJsonDocument(json).toJson(QJsonDocument::Compact);
    // we notify the central server we are about to send the message
    qDebug() << "Sending - " + QString::fromUtf8(jsonData);
//    if (text.isEmpty())
//        return; // We don't send empty messages
    // create a QDataStream operating on the socket
    QDataStream clientStream(clientSocket);
    // set the version so that programs compiled with different versions of Qt can agree on how to serialise
    clientStream.setVersion(QDataStream::Qt_5_15);
    // Create the JSON we want to send
//    QJsonObject message;
//    message["type"] = QStringLiteral("message");
//    message["text"] = text;
    // send the JSON using QDataStream
    clientStream << QJsonDocument(json).toJson(QJsonDocument::Compact);
}

void TestController::onReadyRead()
{
    // prepare a container to hold the UTF-8 encoded JSON we receive from the socket
    QByteArray jsonData;
    // create a QDataStream operating on the socket
    QDataStream socketStream(clientSocket);
    // set the version so that programs compiled with different versions of Qt can agree on how to serialise
    socketStream.setVersion(QDataStream::Qt_5_15);
    // start an infinite loop
    for (;;) {
        // we start a transaction so we can revert to the previous state in case we try to read more data than is available on the socket
        socketStream.startTransaction();
        // we try to read the JSON data
        socketStream >> jsonData;
        if (socketStream.commitTransaction()) {
            // we successfully read some data
            // we now need to make sure it's in fact a valid JSON
            QJsonParseError parseError;
            // we try to create a json document with the data we received
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            if (parseError.error == QJsonParseError::NoError) {
                // if the data was indeed valid JSON
                if (jsonDoc.isObject()) // and is a JSON object
                    JsonReceived(jsonDoc.object()); // parse the JSON
            }
            // loop and try to read more JSONs if they are available
        } else {
            // the read failed, the socket goes automatically back to the state it was in before the transaction started
            // we just exit the loop and wait for more data to become available
            break;
        }
    }
}

void TestController::JsonReceived(const QJsonObject &response)
{
    const QByteArray jsonData = QJsonDocument(response).toJson(QJsonDocument::Compact);
    qDebug() << "Receiving... - " + QString::fromUtf8(jsonData);
    // actions depend on the type of message
    const QJsonValue typeVal = response.value(TYPE_VAL);

    if (typeVal.isNull() || !typeVal.isString())
        return; // a message with no type was received so we just ignore it

    QString type = typeVal.toString();
    const QJsonValue status = response[STATUS];
    if (status.isNull())
        return;

    if ((type.compare(GET_TEST_BY_ID_REQ, Qt::CaseInsensitive) == 0)) {
//        QJsonObject testObj = response[RESULT].toObject();
//        const QJsonValue testName = testObj[NAME].toString();
//        const QJsonValue testId = testObj[TEST_ID].toInt();
//        const QJsonValue testTimeConstraint = testObj[TIME_CONSTRAINT].toInt();
//        _gotTestById.SetId(testId.toInt());
//        _gotTestById.SetName(testName.toString().toStdString());
//        _gotTestById.SetTimeConstrain(testTimeConstraint.toInt());

        Test newTest = ParseTestFromJsonValue(response[RESULT]);
        _gotTestById = newTest;
        emit dataAcquired();
    }

    if ((type.compare(GET_ALL_TESTS_REQ), Qt::CaseInsensitive) == 0) {
        _gotTests.clear();
        QJsonArray testsArray = response[RESULT].toArray();
        foreach (const QJsonValue &testVal, testsArray) {
            Test newTest = ParseTestFromJsonValue(testVal);
            _gotTests.push_back(newTest);
        }
        emit dataAcquired();
    }
    if ((type.compare(SAVE_USER_RES_REQ), Qt::CaseInsensitive) == 0) {
        _gotTestResults.clear();
        QJsonArray resultsArray = response[RESULT].toArray();
        foreach (const QJsonValue &resVal, resultsArray) {
            TestResult testResult = ParseTestResultFromJsonValue(resVal);
            _gotTestResults.push_back(testResult);
        }
        if (status.toBool() == true) {
            emit dataAcquired();
        }
    }

    if ((type.compare(GET_USER_BY_NAME_REQ), Qt::CaseInsensitive) == 0) {
        User* newUser = ParseUserFromJsonValue(response[RESULT]);
        _gotUser = newUser;
        emit dataAcquired();
    }
}

User* TestController::ParseUserFromJsonValue(const QJsonValue &userVal) {
    QJsonObject userObj = userVal.toObject();
    User* newUser = new User();
    const QJsonValue userId = userObj[ID].toInt();
    const QJsonValue userName = userObj[NAME].toString();
    newUser->SetId(userId.toInt());
    newUser->SetName(userName.toString().toStdString());
    return newUser;
}

TestResult TestController::ParseTestResultFromJsonValue(const QJsonValue &json) {
    QJsonObject resObj = json.toObject();
    TestResult testResult;
    const QJsonValue resId = resObj[ID].toInt();
    const QJsonValue resName = resObj[NAME].toString();
    const QJsonValue resScore = resObj[SCORE].toInt();

    QJsonValue testVal = json[TEST];
    QJsonObject testObj = testVal.toObject();
    Test* test = new Test();
    const QJsonValue testId = testObj[ID].toInt();
    const QJsonValue testName = testObj[NAME].toString();
    test->SetId(testId.toInt());
    test->SetName(testName.toString().toStdString());

    testResult.SetId(resId.toInt());
    testResult.SetScore(resScore.toInt());
    testResult.SetTest(test);
    return testResult;
}

Test TestController::ParseTestFromJsonValue(const QJsonValue &testVal) {
    QJsonObject testObj = testVal.toObject();
    Test newTest;
    const QJsonValue testName = testObj[NAME].toString();
    const QJsonValue testId = testObj[ID].toInt();
    const QJsonValue testTimeConstraint = testObj[TIME_CONSTRAINT].toInt();
    newTest.SetId(testId.toInt());
    newTest.SetName(testName.toString().toStdString());
    newTest.SetTimeConstrain(testTimeConstraint.toInt());

    QJsonValue val = testVal[QUESTIONS];
//    QJsonObject debugObj = val.toObject();
//    const QByteArray jsonData = QJsonDocument(debugObj).toJson(QJsonDocument::Compact);
    if (! (val.toArray().empty())) {
        QJsonArray questionsArray = val.toArray();
                foreach(const QJsonValue &testQuestionVal, questionsArray) {
                QJsonObject testQuestionObj = testQuestionVal.toObject();

                Question newQuestion;
                const QJsonValue questionId = testQuestionObj[ID];
                const QJsonValue questionIsMultipleChoice = testQuestionObj[IS_MULT_CHOICE].toBool();
                const QJsonValue questionPoints = testQuestionObj[POINTS].toDouble();
                const QJsonValue questionText = testQuestionObj[QUESTION_TEXT].toString();

                newQuestion.SetMultipleChoice(questionIsMultipleChoice.toBool());
                newQuestion.SetPoints(questionPoints.toDouble());
                newQuestion.SetQuestionText(questionText.toString().toStdString());
                newQuestion.SetId(questionId.toInt());


                QJsonArray questionOptionsArray = testQuestionVal[QUESTION_OPTIONS].toArray();
                        foreach(const QJsonValue &questionOptionVal, questionOptionsArray) {
                        QJsonObject questionOptionObj = questionOptionVal.toObject();

                        QuestionOption newQuestionOption;
                        const QJsonValue questionOptionText = questionOptionObj[TEXT].toString();
                        const QJsonValue questionOptionIsCorrect = questionOptionObj[IS_CORRECT].toBool();
                        const QJsonValue questionOptionId = questionOptionObj[ID].toInt();

                        newQuestionOption.SetText(questionOptionText.toString().toStdString());
                        newQuestionOption.SetCorrect(questionOptionIsCorrect.toBool());
                        newQuestionOption.SetId(questionOptionId.toInt());

                        newQuestion.AddOption(newQuestionOption);
                    }
                newTest.AddQuestion(newQuestion);
            }
    }
    return newTest;
}

#endif