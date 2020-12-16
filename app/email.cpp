#include "email.h"

email::email()
{

}

QString email::checkEmail(QString e) {
    QStringList list = e.split(QRegExp("[@\\.]"), QString::SkipEmptyParts);
    list[0] = list[0].toLower();
    list[1] = list[1].toLower();
    list[2] = list[2].toLower();
    QString join = list[0] + "@" + list[1] + "." + list[2];
    return join;
}
