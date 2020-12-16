#include "email.h"

email::email()
{

}

QString emailLower(QString e) {
    QStringList parts = e.split('@', QString::SkipEmptyParts);
        for (int i = 0; i < parts.size(); ++i)
            parts[i].replace(0, 1, parts[i][0].toLower());

        return parts.join(" ");
}
