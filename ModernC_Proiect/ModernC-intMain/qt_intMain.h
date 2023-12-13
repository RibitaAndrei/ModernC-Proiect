#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt_intMain.h"

class qt_intMain : public QMainWindow
{
    Q_OBJECT

public:
    qt_intMain(QWidget *parent = nullptr);
    ~qt_intMain();

private:
    Ui::qt_intMainClass ui;
};
