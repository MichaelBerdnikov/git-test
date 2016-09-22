#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qfile.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList lst;
    lst << "+" << "-" << "/" << "*";
    ui->comboBox->addItems(lst);
    QObject::connect(ui->comboBox, QComboBox::currentTextChanged, this, &textChanged);
    QObject::connect(ui->firstSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &valueChanged);
    QObject::connect(ui->secondSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &valueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateFile() const
{
    QFile file("name.txt");
    file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    stream << ui->firstSpinBox->text() << ui->comboBox->currentText() << ui->secondSpinBox->text();
    file.close();
}

void MainWindow::valueChanged(int i)
{
    updateFile();

    /*int temp1 = ui->firstSpinBox->text().toInt();
    int temp2 = ui->secondSpinBox->text().toInt();
    int result;
    if (ui->comboBox->currentText() == "+") {
        result = temp1 + temp2;
    } else if (ui->comboBox->currentText() == "-") {
        result = temp1 - temp2;
    } else if (ui->comboBox->currentText() == "/" && temp2 != 0) {
        result = temp1 / temp2;
    } else {
        result = temp1 * temp2;
    }
    QString res = QString::number(result);
    stream << ' = ' << res;*/

}

void MainWindow::textChanged(const QString& text)
{
    updateFile();
}


