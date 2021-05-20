//
// Created by misha on 05.04.21.
//

#ifndef QT_SERVER_TESTSERVER_H
#define QT_SERVER_TESTSERVER_H


#include <QTcpServer>
#include "ServerWorker.h"

class TestServer : public QTcpServer
{
    Q_OBJECT
    Q_DISABLE_COPY(TestServer)
public:
    explicit TestServer(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr socketDescriptor) override;
    signals:
    void logMessage(const QString &msg);
public slots:
    bool startServer(const QHostAddress &address, quint16 port);
    void stopServer();
private slots:
    void broadcast(const QJsonObject &message, ServerWorker *exclude);
    void jsonReceived(ServerWorker *sender, const QJsonObject &doc);
    void consoleMessage(const QString &msg);
private:
    void sendJson(ServerWorker *destination, const QJsonObject &message);
    QVector<ServerWorker *> m_clients;
};


#endif //QT_SERVER_TESTSERVER_H
