#ifndef SETTINGS_H
#define SETTINGS_H
#include <qstring.h>


class Settings {
public:
    Settings();
    bool validation(int);
    QString random(int iterator);
    QString toString(int);
    ~Settings();
};

#endif // SETTINGS_H
