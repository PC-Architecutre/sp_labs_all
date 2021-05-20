//
// Created by artem on 08.03.21.
//

#ifndef CLION_FUCK_QT_USERRESULTS_H
#define CLION_FUCK_QT_USERRESULTS_H

#include <QWidget>
#include "Lab3/Controllers/test_controller.h"
#include "Lab3/Domain/Headers/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserResults; }
QT_END_NAMESPACE

using namespace Domain;
class UserResults : public QWidget {
Q_OBJECT

public:
    explicit UserResults(TestController* tc, QWidget *parent = nullptr);

    ~UserResults() override;
    User* user;
    void ShowResults();

private slots:
    void backEvent();
private:
    Ui::UserResults *ui;
    TestController* _tc;
};

#endif //CLION_FUCK_QT_USERRESULTS_H