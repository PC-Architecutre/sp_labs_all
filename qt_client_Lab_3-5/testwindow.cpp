//
// Created by misha on 08.03.21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_testwindow.h" resolved

#include <QRadioButton>
#include "testwindow.h"
#include "ui_testwindow.h"
#include "window.h"
#include "resultwindow.h"

void clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

testwindow::testwindow(TestController* tc, QWidget *parent, int testId) :
        QWidget(parent), ui(new Ui::testwindow) {
    _tc = tc;
    ui->setupUi(this);
    test = tc->GetTestById(testId);
    answers = vector<int>();
    for (int i = 0; i < test.GetQuestions().size(); i++)
    {
        answers.push_back(-1);
    }
    this->setWindowTitle(QString::fromStdString(test.GetName()));
    connect(ui->btnCancel, SIGNAL(released()), this, SLOT(cancelTestEvent()));
    connect(ui->btnNext, SIGNAL(released()), this, SLOT(nextEvent()));
    connect(ui->btnPrevious, SIGNAL(released()), this, SLOT(previousEvent()));
    current = 0;
    paintQuestionEvent(current);
}

testwindow::~testwindow() {
    delete ui;
}

void testwindow::paintQuestionEvent(int index) {
    auto question = test.GetQuestions().at(index);
    ui->lblQuestion->setText(QString::fromStdString(question.GetQuestionText()));
    int i = 0;
    for (auto qo: question.GetOptions())
    {
        auto radioBtn = new QRadioButton();
        radioBtn->setObjectName(QString::number(i));
        radioBtn->setText(QString::fromStdString(qo.GetText()));
        ui->verticalLayout->addWidget(radioBtn);
        i++;
    }
}

void testwindow::cancelTestEvent() {
    auto w = new class window(_tc);
    w->setGeometry(this->geometry());
    w->show();
    this->~testwindow();
}

void testwindow::nextEvent() {
    auto grid = ui->verticalLayout;
    bool checked = false;
    for (int i = 0; i < grid->count(); i++)
    {
        auto radio = qobject_cast<QRadioButton*>(grid->itemAt(i)->widget());
        if (radio->isChecked()) {
            checked = true;
            answers[current] = radio->objectName().toInt();
        }
    }
    if (checked)
    {
        if (current < test.GetQuestions().size() - 1)
        {
            clearLayout(grid);
            current++;
            paintQuestionEvent(current);
        }
        else
        {
            calculateResult();
        }
    }
}

void testwindow::previousEvent() {
    if (current > 0) {
        auto grid = ui->verticalLayout;
        clearLayout(grid);
        current--;
        paintQuestionEvent(current);
    }
}

void testwindow::calculateResult() {
    float score = 0;
    float maxscore = 0;
    for (int i=0; i < test.GetQuestions().size(); i++)
    {
        auto q = test.GetQuestions().at(i);
        if (q.GetOptions().at(answers[i]).IsCorrect())
            score += q.GetPoints();
        maxscore += q.GetPoints();
    }

    auto test_ptr = new Test();
    test_ptr->SetId(test.GetId());
    auto w = new resultwindow(_tc, nullptr, test_ptr, score, maxscore);
    w->setGeometry(this->geometry());
    w->show();
    this->~testwindow();
}

