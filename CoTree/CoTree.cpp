#include "CoTree.h"
#include <QPushButton>
#include <QMessageBox>
#include <QTextBrowser>
#include "RandomNumberTool.h"
#include "FileIOTool.h"
#include "DebugMachine.h"

CoTree::CoTree(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.StartButton, &QPushButton::clicked, this, &CoTree::HandleStartButtonClicked);
}

CoTree::~CoTree()
{}

void CoTree::HandleStartButtonClicked()
{
    DebugMachine debuger(this);
    debuger.LogMessageBox("test log");
}
