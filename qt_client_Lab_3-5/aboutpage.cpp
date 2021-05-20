//
// Created by dmytro on 08.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AboutPage.h" resolved

#include "aboutpage.h"
#include "ui_aboutpage.h"
#include "window.h"

AboutPage::AboutPage(TestController* tc, QWidget *parent) :
        QWidget(parent), ui(new Ui::AboutPage) {
    _tc = tc;
    ui->setupUi(this);
    connect(ui->btnReturnToMain, SIGNAL(released()), this, SLOT(returnToMainEvent()));
}

AboutPage::~AboutPage() {
    delete ui;
}

void AboutPage::returnToMainEvent() {
    class window* window = new class window(_tc);
    window->setGeometry(this->geometry());
    window->show();
    this->~AboutPage();
}
