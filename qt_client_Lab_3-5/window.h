//
// Created by misha on 07.03.21.
//

#ifndef CLION_FUCK_QT_WINDOW_H
#define CLION_FUCK_QT_WINDOW_H

#include <QWidget>
#include "Lab3/Controllers/test_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class window; }
QT_END_NAMESPACE

class window : public QWidget {
Q_OBJECT

public:
    explicit window(TestController* tc, QWidget *parent = nullptr);

    ~window() override;

private:
    Ui::window *ui;
    TestController* _tc;
private slots:
    void OpenChooseTestWidgetEvent();
    void ShowUserResults();
    void openFormAboutEvent();
    void ShowResultsArrangedByScore();
};

#endif //CLION_FUCK_QT_WINDOW_H