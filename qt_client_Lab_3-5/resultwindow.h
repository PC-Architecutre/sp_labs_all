//
// Created by misha on 08.03.21.
//

#ifndef CLION_FUCK_QT_RESULTWINDOW_H
#define CLION_FUCK_QT_RESULTWINDOW_H

#include <QWidget>
#include <QString>
#include "Lab3/Controllers/test_controller.h"
#include "Lab3/Domain/Headers/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class resultwindow; }
QT_END_NAMESPACE

class resultwindow : public QWidget {
Q_OBJECT

public:
    explicit resultwindow(TestController* tc, QWidget *parent = nullptr, Test* test = nullptr, int score = 0, int maxscore = 0);

    ~resultwindow() override;

private:
    Ui::resultwindow *ui;
    TestController* _tc;
    Test* test;
    int _score;
    int _maxscore;
private slots:
    void saveEvent();
    void notSaveEvent();
};

#endif //CLION_FUCK_QT_RESULTWINDOW_H
