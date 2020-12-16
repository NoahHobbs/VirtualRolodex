#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSlider>
#include <QDial>
#include <QGraphicsRectItem>
#include <random>
#include <string>
#include <QInputDialog>
#include "name.h"
#include "phone.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void testDatabase();
    void on_SaveContactButton_clicked();

    void on_SearchButton_clicked();

    void on_allContacts_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
