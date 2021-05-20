//
// Created by misha on 07.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_window.h" resolved

#include "window.h"
#include "ui_window.h"
#include "choosetestwidget.h"
#include "aboutpage.h"
#include "selectuser.h"
#include "choosetestforuserarrangement.h"

window::window(TestController* tc, QWidget *parent) :
        QWidget(parent), ui(new Ui::window) {
    _tc = tc;
    ui->setupUi(this);
    connect(ui->btnChooseTest, SIGNAL(released()), this, SLOT(OpenChooseTestWidgetEvent()));
    connect(ui->btnShowResult, SIGNAL(released()), this, SLOT(ShowUserResults()));
    connect(ui->btnAboutUs, SIGNAL(released()), this, SLOT(openFormAboutEvent()));
    connect(ui->btnShowResultsByScore, SIGNAL(released()), this, SLOT(ShowResultsArrangedByScore()));
}

window::~window() {
    delete ui;
}

void window::OpenChooseTestWidgetEvent() {
    choosetestwidget* widget = new choosetestwidget(_tc);
    widget->setGeometry(this->geometry());
    widget->show();
    this->~window();
}

void window::ShowUserResults() {
    auto* widget = new SelectUser(_tc);
    widget->setGeometry(this->geometry());
    widget->show();
    this->hide();
}
void window::openFormAboutEvent() {
    AboutPage* about = new AboutPage(_tc);
    about->show();
    about->setGeometry(this->geometry());
    this->~window();
}

void window::ShowResultsArrangedByScore() {
    auto widget = new ChooseTestForUserArrangement(_tc);
    widget->setGeometry(this->geometry());
    widget->show();
    this->~window();
}