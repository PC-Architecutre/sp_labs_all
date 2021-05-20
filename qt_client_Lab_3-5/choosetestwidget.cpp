//
// Created by misha on 07.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_choosetestwidget.h" resolved

#include "choosetestwidget.h"
#include "ui_choosetestwidget.h"
#include "window.h"
#include "testwindow.h"


choosetestwidget::choosetestwidget(TestController* tc , QWidget *parent) :
        QWidget(parent), ui(new Ui::choosetestwidget) {
    _tc = tc;
    ui->setupUi(this);
    connect(ui->btnBack, SIGNAL(released()), this, SLOT(backEvent()));
    vector<Test> tests = tc->GetAllTests();
    for (auto t: tests)
    {
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

choosetestwidget::~choosetestwidget() {
    delete ui;
}

void choosetestwidget::backEvent() {
    class window* w = new class window(_tc);
    w->setGeometry(this->geometry());
    w->show();
    this->~choosetestwidget();
}

void choosetestwidget::chooseTestEvent() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    auto w = new testwindow(_tc, nullptr, buttonSender->objectName().toInt());
    w->setGeometry(this->geometry());
    w->show();
    this->~choosetestwidget();
}

