#include "phone.h"


phone::phone()
{

}

QString phone::checkPhone(QString p) {
    QRegularExpression phoneContains("[\\(\\)\\-]$");
    QRegularExpressionMatch phoneMatch = phoneContains.match(p);
    if (!phoneMatch.hasMatch()) {
        p.insert( 0, "(" );
        p.insert( 4, ")" );
        p.insert( 5, "-" );
        p.insert( 9, "-" );
    }
    return p;
}
