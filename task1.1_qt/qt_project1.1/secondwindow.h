#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_createFileButton_clicked();
};

#endif // SECONDWINDOW_H
