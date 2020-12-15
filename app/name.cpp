#include "name.h"

name::name()
{

}
QString name::capsName(QString userName) {
    QStringList parts = userName.split(' ', QString::SkipEmptyParts);
    for (int i = 0; i < parts.size(); ++i) {
        parts[i].replace(0,1,parts[i] [0].toUpper());
    }
    return parts.join("");
}
