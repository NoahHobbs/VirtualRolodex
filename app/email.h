#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include <qstring.h>
#include "database.h"
#include "mainwindow.h"

class email
{
public:
    email();
    QString checkEmail(QString e);

};

#endif // EMAIL_H
