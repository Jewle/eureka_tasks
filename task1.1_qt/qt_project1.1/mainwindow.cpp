#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *openSecondWindowButton = new QPushButton("Open Second Window", this);
    layout->addWidget(openSecondWindowButton, 0, Qt::AlignCenter);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(openSecondWindowButton, &QPushButton::clicked, this, &MainWindow::on_openSecondWindowButton_clicked);

    secondWindow = new SecondWindow(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_openSecondWindowButton_clicked()
{
    secondWindow->show();
}
