#include "CoTree.h"
#include <QPushButton>
#include <QMessageBox>
#include ".\RandomNumberTool\RandomNumberTool.h"
#include ".\FileIOTool\FileIOTool.h"

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
    RandomNumberTool randomNumberTool;
    string uuid = randomNumberTool.generateRandomBytes(4);

    FileIOTool fileIOTool;

    QMessageBox::information(this, "Generated UUID", QString::fromStdString(uuid));
}
