//
// Created by artem on 09.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChooseTestForUserArrangement.h" resolved

#include "choosetestforuserarrangement.h"
#include "ui_choosetestforuserarrangement.h"
#include <QPushButton>
#include "window.h"
#include "arrangeusersbyscore.h"

ChooseTestForUserArrangement::ChooseTestForUserArrangement(TestController* tc, QWidget *parent) :
        QWidget(parent), ui(new Ui::ChooseTestForUserArrangement) {
    _tc = tc;
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(released()), this, SLOT(backEvent()));
    for (auto t: tc->GetAllTests()) {
        auto btn = new QPushButton();
        btn->setText(QString::fromStdString(t.GetName()));
        btn->setObjectName(QString::number(t.GetId()));
        btn->setStyleSheet(QString::fromStdString("QPushButton\n"
                                                  "{\n"
                                                  "\tbackground-color: #ea526f;\n"
                                                  "\tborder-radius: 20px;\n"
                                                  "\tpadding: 4px;\n"
                                                  "\tcolor: #f7f7ff;\n"
                                                  "}\n"
                                                  "QPushButton:hover\n"
                                                  " { \n"
                                                  "\tbackground-color: #ea526f;\n"
                                                  "}"));

        connect(btn, SIGNAL(released()), this, SLOT(chooseTestEvent()));
        ui->verticalLayout->addWidget(btn);
    }
}


ChooseTestForUserArrangement::~ChooseTestForUserArrangement() {
    delete ui;
}

void ChooseTestForUserArrangement::backEvent() {
    auto w = new class window(_tc);
    w->setGeometry(this->geometry());
    w->show();
    this->~ChooseTestForUserArrangement();
}

void ChooseTestForUserArrangement::chooseTestEvent() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    auto w = new ArrangeUsersByScore(_tc, nullptr, buttonSender->objectName().toInt());
    w->setGeometry(this->geometry());
    w->show();
    this->~ChooseTestForUserArrangement();
}

