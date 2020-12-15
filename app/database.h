#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

using namespace std;

class Database
{
private:
    long getLatestRowId();
public:
    Database();
    void rebuildTestDatabase();
    void createContact(long long contactId);
};

#endif // DATABASE_H
