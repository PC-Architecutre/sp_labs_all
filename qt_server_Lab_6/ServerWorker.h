//
// Created by misha on 05.04.21.
//

#ifndef QT_SERVER_SERVERWORKER_H
#define QT_SERVER_SERVERWORKER_H

#include <QString>
#include <QVector>
#include <QtCore>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QTcpServer;
QT_END_NAMESPACE


class ServerWorker : public QObject
{
Q_OBJECT
    Q_DISABLE_COPY(ServerWorker)
public:
    explicit ServerWorker(QObject *parent = nullptr);
    virtual bool setSocketDescriptor(qintptr socketDescriptor);
    void sendJson(const QJsonObject &jsonData);
signals:
    void jsonReceived(const QJsonObject &jsonDoc);
    void disconnectedFromClient();
    void error();
    void logMessage(const QString &msg);
public slots:
    void disconnectFromClient();
private slots:
    void receiveJson();
private:
    QTcpSocket *m_serverSocket;
};


#endif //QT_SERVER_SERVERWORKER_H
