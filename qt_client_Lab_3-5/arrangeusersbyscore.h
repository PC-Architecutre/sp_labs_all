//
// Created by artem on 09.03.21.
//

#ifndef CLION_FUCK_QT_ARRANGEUSERSBYSCORE_H
#define CLION_FUCK_QT_ARRANGEUSERSBYSCORE_H

#include <QWidget>
#include "Lab3/Controllers/test_controller.h"
#include "Lab3/Domain/Headers/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ArrangeUsersByScore; }
QT_END_NAMESPACE

class ArrangeUsersByScore : public QWidget {
Q_OBJECT

public:
    explicit ArrangeUsersByScore(TestController* tc, QWidget *parent = nullptr, int testId = -1);

    ~ArrangeUsersByScore() override;

private slots:
    void GoBackEvent();

private:
    Ui::ArrangeUsersByScore *ui;
    TestController* _tc;
    vector<TestResult> SortByScore(vector<TestResult> res);
    static bool CompareTestResultsByScore(TestResult t1, TestResult t2);
    void ShowSortedResults(vector<TestResult>& res);
};

#endif //CLION_FUCK_QT_ARRANGEUSERSBYSCORE_H
