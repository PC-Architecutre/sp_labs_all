//
// Created by misha on 08.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_resultwindow.h" resolved

#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "window.h"
#include <QInputDialog>

resultwindow::resultwindow(TestController* tc, QWidget *parent, Test* test, int score, int maxscore) :
        QWidget(parent), ui(new Ui::resultwindow) {
    _tc = tc;
    ui->setupUi(this);
    this->test = test;
    _score = score;
    _maxscore = maxscore;
    connect(ui->btnNotSave, SIGNAL(released()), this, SLOT(notSaveEvent()));
    connect(ui->btnSave, SIGNAL(released()), this, SLOT(saveEvent()));
    ui->lblResult->setText(QString::fromStdString("Ваш результат: ")+QString::number(score) + QString::fromStdString("/") + QString::number(maxscore));
}

resultwindow::~resultwindow() {
    delete ui;
}

void resultwindow::saveEvent() {
    bool ok;
    QString userName = QInputDialog::getText(this, tr("Ім'я користувача"), tr("Введіть ім'я"),
                                              QLineEdit::Normal, tr(""), &ok);
    if (ok && !userName.isEmpty())
    {
        auto usr = _tc->GetUserByName(&userName);
        TestResult tr = TestResult();
        tr.SetId(rand());
        tr.SetTest(test);
        tr.SetScore(_score);
        if ( usr == nullptr)
        {
            usr = new User();
            usr->SetId(rand());
            usr->SetName(userName.toStdString());
        }
        tr.SetUser(usr);
        _tc->SaveUserResult(tr);
        auto w = new class window(_tc);
        w->setGeometry(this->geometry());
        w->show();
        this->~resultwindow();
    }
}

void resultwindow::notSaveEvent() {
    auto w = new class window(_tc);
    w->setGeometry(this->geometry());
    w->show();
    this->~resultwindow();
}
