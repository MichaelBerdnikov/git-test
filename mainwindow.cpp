#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qfile.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::valueChanged(int i)
{
    QFile file("name.txt");
    file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    stream << ui->firstSpinBox->text() << "+" << ui->secondSpinBox->text();
    file.close();
}
