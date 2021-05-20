//
// Created by misha on 09.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SelectUser.h" resolved

#include "selectuser.h"
#include "ui_selectuser.h"
#include "userresults.h"
#include "window.h"

SelectUser::SelectUser(TestController* tc, QWidget *parent) :
        QWidget(parent), ui(new Ui::SelectUser) {
    _tc = tc;
    ui->setupUi(this);
    connect(ui->btnSearchUser, SIGNAL(released()), this, SLOT(TryShowUserTestResultsEvent()));
    connect(ui->btnBack, SIGNAL(released()), SLOT(BackEvent()));
}

SelectUser::~SelectUser() {
    delete ui;
}

bool SelectUser::CheckUserExists(const QString& inp) {
    return _tc->GetUserByName(&inp) != nullptr;
}

void SelectUser::TryShowUserTestResultsEvent() {
    const QString& inp = ui->inpUserName->text();
    if (CheckUserExists(inp)) {
        ShowUserTestResultsEvent(_tc->GetUserByName(&inp));
    } else {
        ui->lbErrorUserNotFound->setText("User not found");
    }
}

void SelectUser::ShowUserTestResultsEvent(User* user) {
    UserResults* widget = new UserResults(_tc);
    widget->user = user;
    widget->ShowResults();
    widget->setGeometry(this->geometry());
    widget->show();
    this->~SelectUser();
}

void SelectUser::BackEvent() {
    auto w = new class window(_tc);
    w->setGeometry(this->geometry());
    w->show();
    this->~SelectUser();
}
