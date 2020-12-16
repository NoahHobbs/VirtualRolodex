#ifndef PHONE_H
#define PHONE_H
#include <string>
#include "database.h"
#include "mainwindow.h"
#include <QRegExpValidator>

class phone
{
public:
    phone();
    QString checkPhone(QString p);
};

#endif // PHONE_H
