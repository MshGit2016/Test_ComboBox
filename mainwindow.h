#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QDateEdit>
#include <QMap>
#include <QFocusFrame>
#include <QPixmap>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QMap<int,QVector<QString>> m_stringList;

    QMenu *menu[3];
    QAction *act[2];
    QMenuBar * menubar;
public slots:
   void valueChanged();
   void clickFunc();
   void btn_click();
   void btn_pressed();
   void btn_released();

   void changedIndex(int idx);
   void changedFont(const QFont &f);

   void trigerMenu(QAction*);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
