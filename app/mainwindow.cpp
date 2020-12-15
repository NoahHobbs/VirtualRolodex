#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "name.h"
#include <QRegExpValidator>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // these lines hide my frames when the window is made
    ui->NewContactFrame->hide();
    ui->AllContactsFrame->hide();
    ui->OneContactFrame->hide();
}

MainWindow::~MainWindow()
{
    //Destructor
    delete ui;
}

void MainWindow::testDatabase() {

}

void MainWindow::on_SaveContactButton_clicked()
{
    //Clears the 3 text fields in the form and saves the entered information
    Database();
    class name toCaps;
    QSqlQuery query;
    QString nameText = ui->NameTxtBox->toPlainText();

    QString phoneText = ui->PhoneTxtBox->toPlainText();
    QString emailText = ui->EmailTxtBox->toPlainText();
    //using regex to test user input
    QRegularExpression nameValid("^[A-Za-z0-9 ]+$");
    QRegularExpression emailValid("[^@ \t\r\n]+@[^@ \t\r\n]+\\.[^@ \t\r\n]+");
    QRegularExpression phoneValid("^[\\+]?[(]?[0-9]{3}[)]?[-\\s\\.]?[0-9]{3}[-\\s\\.]?[0-9]{4,6}$");
    QRegularExpressionMatch nameMatch = nameValid.match(nameText);
    QRegularExpressionMatch emailMatch = emailValid.match(emailText);
    QRegularExpressionMatch phoneMatch = phoneValid.match(phoneText);
    if (nameMatch.hasMatch() && emailMatch.hasMatch() && phoneMatch.hasMatch()) {
        QString capsName = toCaps.capsName(nameText);
        query.prepare("INSERT INTO Contacts (name, phone, email) VALUES (:name, :phone, :email)");
        query.bindValue(":name", capsName);
        query.bindValue(":phone", phoneText);
        query.bindValue(":email", emailText);
        query.exec();
        ui->EmailTxtBox->clear();
        ui->PhoneTxtBox->clear();
        ui->NameTxtBox->clear();
    }
    else {
        //Handeling if the user inputs incorrect information
        ui->ErrorLabel->setText("Please enter valid input");
    }


}

void MainWindow::on_allContacts_clicked()
{
    Database();
    QSqlQuery query;
    query.exec("SELECT * FROM Contacts");
    //The while loop below saves the columns to QString variables and then appends them to a text box in my GUI
    while (query.next()) {
        QString idNum = query.value(0).toString();
        QString name = query.value(1).toString();
        QString email = query.value(2).toString();
        QString phone = query.value(3).toString();
        ui->AllContactsTxt->appendPlainText("ID #: " + idNum);
        ui->AllContactsTxt->appendPlainText("Name: " + name);
        ui->AllContactsTxt->appendPlainText("Email: " + email);
        ui->AllContactsTxt->appendPlainText("Phone: " + phone);


    }

}

void MainWindow::on_SearchButton_clicked()
{
    //This line clears incase the user enters two or more contacts in a row
    ui->OneContactCheck->clear();
    Database();
    QSqlQuery query;
    //preparing the select statement to get the contact from the database
    query.prepare("SELECT * from Contacts where name = ?");
    //saving the user inputted name to search the rows with
    QString name = ui->CheckContactTxt->toPlainText();
    query.addBindValue(name);
    query.exec();
    //While loop to save the columns and show the user selected contact
    while (query.next()) {
        QString idNum = query.value(0).toString();
        QString name = query.value(1).toString();
        QString email = query.value(2).toString();
        QString phone = query.value(3).toString();
        ui->OneContactCheck->appendPlainText("ID #: " + idNum);
        ui->OneContactCheck->appendPlainText("Name: " + name);
        ui->OneContactCheck->appendPlainText("Email: " + email);
        ui->OneContactCheck->appendPlainText("Phone: " + phone);


    }

    //clears the search box when the user clicks the search button
    ui->CheckContactTxt->clear();

}


