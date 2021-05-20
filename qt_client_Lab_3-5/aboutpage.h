//
// Created by dmytro on 08.03.21.
//

#ifndef CLION_FUCK_QT_ABOUTPAGE_H
#define CLION_FUCK_QT_ABOUTPAGE_H

#include <QWidget>
#include "Lab3/Controllers/test_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AboutPage; }
QT_END_NAMESPACE

class AboutPage : public QWidget {
Q_OBJECT

public:
    explicit AboutPage(TestController* tc, QWidget *parent = nullptr);

    ~AboutPage() override;

private:
    Ui::AboutPage *ui;
    TestController* _tc;
private slots:
    void returnToMainEvent();
};

#endif //CLION_FUCK_QT_ABOUTPAGE_H
