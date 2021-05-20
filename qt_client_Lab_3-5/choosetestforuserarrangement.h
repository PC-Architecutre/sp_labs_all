//
// Created by artem on 09.03.21.
//

#ifndef CLION_FUCK_QT_CHOOSETESTFORUSERARRANGEMENT_H
#define CLION_FUCK_QT_CHOOSETESTFORUSERARRANGEMENT_H

#include <QWidget>
#include "choosetestwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChooseTestForUserArrangement; }
QT_END_NAMESPACE

class ChooseTestForUserArrangement : public QWidget {
Q_OBJECT

public:
    explicit ChooseTestForUserArrangement(TestController* tc, QWidget *parent = nullptr);

    ~ChooseTestForUserArrangement() override;

private:
    Ui::ChooseTestForUserArrangement *ui;
    TestController* _tc;
private slots:
    void backEvent();
    void chooseTestEvent();
};

#endif //CLION_FUCK_QT_CHOOSETESTFORUSERARRANGEMENT_H
