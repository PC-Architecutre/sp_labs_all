#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "TestServer.h"

#define ADDRESS "127.0.0.1"
#define PORT 8888

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";
    auto *server = new TestServer();
    QHostAddress address;
    address.setAddress(ADDRESS);
    std::cout << server->startServer(address, PORT);
    return QCoreApplication::exec();
}
