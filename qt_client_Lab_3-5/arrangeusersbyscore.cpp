//
// Created by artem on 09.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ArrangeUsersByScore.h" resolved

#include "arrangeusersbyscore.h"
#include "ui_arrangeusersbyscore.h"
#include <QLabel>
#include "window.h"

using namespace std;

ArrangeUsersByScore::ArrangeUsersByScore(TestController* tc, QWidget *parent, int testId) :
        QWidget(parent), ui(new Ui::ArrangeUsersByScore) {
    _tc = tc;
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(released()), this, SLOT(GoBackEvent()));
    vector<TestResult> results = tc->GetResultsByTestId(testId);
    int idx = 0;

    std::sort(results.begin(), results.end(), [](TestResult a, TestResult b) {
        return a.GetScore() > b.GetScore();
    });
    for (; idx < results.size(); idx++) {
        auto label = new QLabel();
        label->setText(
                QString::fromStdString(results.at(idx).usrname) + QString::fromStdString("\t") + QString::number(results.at(idx).GetScore()));
        ui->verticalLayout->addWidget(label);
    }

//    vector<TestResult> sorted = SortByScore(results);
//    ShowSortedResults(results);
}

ArrangeUsersByScore::~ArrangeUsersByScore() {
    delete ui;
}

void ArrangeUsersByScore::ShowSortedResults(vector<TestResult>& res) {
    int idx = 0;
    for (; idx < res.size(); idx++) {
        User u = res.at(idx).GetUser();
        auto label = new QLabel();
        label->setText(  QString::fromStdString(u.GetName()).append("\t").append(QString::number(res.at(idx).GetScore()))  );
        ui->verticalLayout->addWidget(label);
    }
}

vector<TestResult> ArrangeUsersByScore::SortByScore(vector<TestResult> res) {
    std::sort(res.begin(), res.end(), CompareTestResultsByScore);
    return res;
}

bool ArrangeUsersByScore::CompareTestResultsByScore(TestResult t1, TestResult t2) {
    return t1.GetScore() > t2.GetScore();
}

void ArrangeUsersByScore::GoBackEvent() {
    auto w = new class window(_tc);
    w->setGeometry(this->geometry());
    w->show();
    this->~ArrangeUsersByScore();
}