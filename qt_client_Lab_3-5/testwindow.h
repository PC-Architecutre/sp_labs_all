//
// Created by misha on 08.03.21.
//

#ifndef CLION_FUCK_QT_TESTWINDOW_H
#define CLION_FUCK_QT_TESTWINDOW_H

#include <QWidget>
#include "Lab3/Controllers/test_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class testwindow; }
QT_END_NAMESPACE

class testwindow : public QWidget {
Q_OBJECT

public:
    explicit testwindow(TestController* tc, QWidget *parent = nullptr,  int testId = -1);

    ~testwindow() override;

private:
    Ui::testwindow *ui;
    TestController* tc;
    Test test;
    int current;
    vector<int> answers;
    void paintQuestionEvent(int index);
    TestController* _tc;

private slots:
    void cancelTestEvent();
    void nextEvent();
    void previousEvent();
    void calculateResult();

};

#endif //CLION_FUCK_QT_TESTWINDOW_H
