#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setGeometry(50,50,200,30);

    ui->comboBox->addItem(QIcon(":/Resources/clock"),"Application");
    ui->comboBox->addItem(QIcon(":/Resources/save"),"Graphics");
    ui->comboBox->addItem(QIcon(":/Resources/refresh"),"Database");
    ui->comboBox->addItem(QIcon(":/Resources/network"),"Network");

    ui->commandLinkButton->setText("Vision");

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(valueChanged()));
    connect(ui->commandLinkButton,SIGNAL(clicked(bool)),this,SLOT(clickFunc()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::valueChanged()
{
    int current_index=ui->comboBox->currentIndex();
    qDebug("Current ComboBox index:%d",current_index);

    QString str;
    str=ui->comboBox->currentText();
    qDebug()<<"Current ComboBox text"<<str;
    qDebug()<<"Total Item:"<<ui->comboBox->count();
    ui->comboBox->removeItem(3);

}
void MainWindow::clickFunc()
{
    qDebug()<<"Clicked the Button";

}
