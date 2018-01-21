#pragma once
#include <qstring.h>


class Settings {
public:
	int tab[12];
    Settings();
    bool validation(int);
    QString random(int iterator);
    QString toString(int);
    ~Settings();
};
