#include "database.h"

Database::Database()
{
    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qWarning() << "ERROR: driver not available";
    }
    QString path = "/Users/jasonhobbs/Documents/";
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(path + "contacts");
    if(!db.open()) {
        qWarning() << "ERROR: " << db.lastError();
    }
    rebuildTestDatabase();
}

long Database::getLatestRowId() {
    QSqlQuery query;
    query.exec("SELECT last_insert_rowid()");
    query.next();
    return query.value(0).toLongLong();
}

void Database::createContact(long long contactId) {
    QSqlQuery insertContact;
    insertContact.prepare("INSERT INTO Contacts (ContactId, Name, PhoneNum, EmailAddr) VALUES (:contactId, :Name, :Phone, :Email)");
    insertContact.bindValue(":contactId", contactId);
    insertContact.bindValue(":Name", "Name");
    insertContact.exec();
}

void Database::rebuildTestDatabase() {
    QSqlQuery query;
    // (re)create table
    query.exec("CREATE TABLE Contacts (contactId INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Email TEXT, Phone TEXT)");

    QSqlQuery insertContact;
    insertContact.prepare("INSERT INTO Contact (Name) VALUES (:Name)");
    insertContact.bindValue(":Name", "Test1");
    insertContact.bindValue(":Email", "emailTest1");
    insertContact.bindValue(":Phone", "phoneTest1");
    long long contactId1 = getLatestRowId();
    insertContact.bindValue(":contactId", contactId1);

    insertContact.exec();

    insertContact.bindValue(":Name", "test2");
    insertContact.bindValue(":Email", "emailTest2");
    insertContact.bindValue(":Name", "phoneTest2");
    long long contactId2 = getLatestRowId();
    insertContact.bindValue(":contactId", contactId2);
    insertContact.exec();
}
