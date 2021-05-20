#ifndef SYS_PROG_2ND_COURSE_TestController_H
#define SYS_PROG_2ND_COURSE_TestController_H

#include "../Domain/Headers/test.h"
#include <QHostAddress>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <vector>
#include <QString>
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QEventLoop>

using namespace Domain;

class TestController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(TestController)
public:
    explicit TestController(QObject *parent = 0);
    ~TestController();
    Test GetTestById(int id);
    vector<Test> GetAllTests();
    void SaveUserResult(TestResult TestResult);
    User* GetUserByName(const QString* str);
    vector<TestResult> GetUserResults(User& user);
    vector<TestResult> GetResultsByTestId(int testId);
private:
    QTcpSocket *clientSocket;
    vector<TestResult> _gotTestResults;
    vector<Test> _gotTests;
    Test _gotTestById;
    User* _gotUser;
    Test ParseTestFromJsonValue(const QJsonValue &json);
    TestResult ParseTestResultFromJsonValue(const QJsonValue &json);
    User* ParseUserFromJsonValue(const QJsonValue &json);
    void SendMessage(const QJsonObject &json);
    void JsonReceived(const QJsonObject &response);
    void WaitUntilConnect();
private slots:
    void connectToServer(const QHostAddress &address, quint16 port);
    void disconnectFromHost();
    void onReadyRead();

signals:
    void connected();
    void disconnected();
    void dataAcquired();
    void error();
};

#endif
