//
// Created by misha on 07.03.21.
//

#ifndef CLION_FUCK_QT_CHOOSETESTWIDGET_H
#define CLION_FUCK_QT_CHOOSETESTWIDGET_H

#include <QWidget>
#include "Lab3/Controllers/test_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class choosetestwidget; }
QT_END_NAMESPACE

class choosetestwidget : public QWidget {
Q_OBJECT

public:
    explicit choosetestwidget(TestController* tc, QWidget *parent = nullptr);

    ~choosetestwidget() override;

private:
    Ui::choosetestwidget *ui;
    TestController* _tc;

private slots:
    void backEvent();
    void chooseTestEvent();
};

#endif //CLION_FUCK_QT_CHOOSETESTWIDGET_H
