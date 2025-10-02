#include "secondwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QDir>
#include <QDebug>
SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *createFileButton = new QPushButton("Create File and Exit", this);
    layout->addWidget(createFileButton, 0, Qt::AlignCenter);

    setLayout(layout);

    connect(createFileButton, &QPushButton::clicked, this, &SecondWindow::on_createFileButton_clicked);
}

SecondWindow::~SecondWindow()
{
}

void SecondWindow::on_createFileButton_clicked()
{
    qDebug()<<QDir::currentPath();
    QFile file("output.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out.setCodec("UTF-8");
        QString str("Миру мир!");
        out << str.toLocal8Bit();
        file.close();
    }
    QApplication::quit();
}
