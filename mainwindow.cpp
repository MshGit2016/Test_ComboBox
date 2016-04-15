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

    QDate dt1=QDate(2016,3,15);
    QDate dt2=QDate::currentDate();
    ui->dateEdit->setDate(dt1.addYears(2));
    ui->dateEdit->setGeometry(10,350,140,40);
    ui->dateEdit_2->setDate(dt1.addMonths(3));
    ui->dateEdit_2->setGeometry(160,350,140,40);

    ui->dateEdit_3->setDate(dt1.addDays(10));
    ui->dateEdit_3->setGeometry(310,350,140,40);
    ui->dateEdit_4->setDate(dt2);
    ui->dateEdit_4->setGeometry(10,400,140,40);
    QString str1="01123456";
    QString str2="345";
    QString str3="qwer";
    QString str4="14.34";
    QStringList strlist;
    strlist<<str1<<str2<<str3<<str4;
    int id=200;
    QVector<QString> str=QVector<QString>::fromList(strlist);

    qDebug()<<str<<" str[0]= "<<str.at(0)<<" str[3]= "<<str.at(3).toFloat();

    m_stringList.insert(id,str);

    qDebug()<<m_stringList[id][0]<<" 1="<<m_stringList[id][1].toInt()<<" 3="<<m_stringList[id][3].toFloat();

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
