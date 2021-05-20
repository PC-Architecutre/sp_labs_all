//
// Created by misha on 09.03.21.
//

#ifndef CLION_FUCK_QT_SELECTUSER_H
#define CLION_FUCK_QT_SELECTUSER_H

#include <QWidget>
#include "Lab3/Controllers/test_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SelectUser; }
QT_END_NAMESPACE

using namespace Domain;
class SelectUser : public QWidget {
Q_OBJECT

public:
    explicit SelectUser(TestController* tc, QWidget *parent = nullptr);

    ~SelectUser() override;
private slots:
    void TryShowUserTestResultsEvent();
    void ShowUserTestResultsEvent(User* user);
    void BackEvent();
private:
    bool CheckUserExists(const QString& inp);
    Ui::SelectUser *ui;
    TestController *_tc;
};

#endif //CLION_FUCK_QT_SELECTUSER_H
