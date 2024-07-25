#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CoTree.h"

class CoTree : public QMainWindow
{
    Q_OBJECT

public:
    CoTree(QWidget *parent = nullptr);
    ~CoTree();

public slots:
    void HandleStartButtonClicked();

private:
    Ui::CoTreeClass ui;
};