//
// Created by artem on 08.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserResults.h" resolved

#include "userresults.h"
#include "ui_userresults.h"
#include <QLabel>
#include "Lab3/Domain/Headers/test_result.h"
#include "window.h"

UserResults::UserResults(TestController* tc, QWidget *parent) :
        QWidget(parent), ui(new Ui::UserResults) {
    _tc = tc;
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(released()), this, SLOT(backEvent()));
}

UserResults::~UserResults() {
    delete ui;
}

void UserResults::ShowResults() {
    for (TestResult res : _tc->GetUserResults(*user)) {
        auto label = new QLabel();
        Test t = res.GetTest();
        label->setText(  QString::fromStdString(t.GetName()).append("\t").append(QString::number(res.GetScore()))  );
        ui->vlTest->addWidget(label);
    }
}

void UserResults::backEvent() {
    class window* w = new class window(_tc);
    w->setGeometry(this->geometry());
    w->show();
    this->~UserResults();
}
