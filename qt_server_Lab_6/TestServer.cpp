//
// Created by misha on 05.04.21.
//

#include <iostream>
#include "TestServer.h"
#include "Parser.h"
#include <QDebug>
#include "Lab3/Controllers/test_controller.h"
#include "Lab3/DataAccess/SqlRepositories/Headers/UnitOfWorkSqlDB.h"

void TestServer::incomingConnection(qintptr socketDescriptor)
{
    auto *worker = new ServerWorker(this);
    if (!worker->setSocketDescriptor(socketDescriptor)) {
        worker->deleteLater();
        return;
    }
    connect(worker, &ServerWorker::disconnectedFromClient, this, [this, worker] { });
    connect(worker, &ServerWorker::error, this, [this, worker] { });
    connect(worker, &ServerWorker::jsonReceived, this, std::bind(&TestServer::jsonReceived, this, worker, std::placeholders::_1));
    connect(worker, &ServerWorker::logMessage, this, &TestServer::logMessage);
    m_clients.append(worker);
    emit logMessage(QStringLiteral("New client Connected"));
}


void TestServer::sendJson(ServerWorker *destination, const QJsonObject &message)
{
    Q_ASSERT(destination); // make sure destination is not null
    destination->sendJson(message); // call directly the worker method
}

void TestServer::broadcast(const QJsonObject &message, ServerWorker *exclude)
{
    // iterate over all the workers that interact with the clients
    for (ServerWorker *worker : m_clients) {
        if (worker == exclude)
            continue; // skip the worker that should be excluded
        sendJson(worker, message); //send the message to the worker
    }
}

void TestServer::jsonReceived(ServerWorker *sender, const QJsonObject &request) {
    QJsonObject response;
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("test_cpp.sqlite");
    auto* uof = new UnitOfWorkSqlDB(dbase);
    TestController* tc = new TestController(uof);
    Parser* parser = new Parser(tc);
    response = parser->parse(request);
    delete uof;
    delete tc;
    delete parser;
    sendJson(sender, response);
}

bool TestServer::startServer(const QHostAddress &address, quint16 port)
{
    if(listen(address, port))
    {
        return true;
    }
    return false;
}

void TestServer::stopServer() {
    for (auto *client : m_clients)
    {
        client->disconnectFromClient();
    }
    close();
}

TestServer::TestServer(QObject *parent) : QTcpServer(parent) {
    connect(this, &TestServer::logMessage, this, &TestServer::consoleMessage);
    emit logMessage("Debug check");
}

void TestServer::consoleMessage(const QString &msg) {
    qDebug() << msg;
}
