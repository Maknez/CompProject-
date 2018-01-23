#include "settings.h"
#include "stdlib.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Settings::Settings() {}

Settings::~Settings() {}

bool Settings::validation(int number) {
    int hits = 0;
    for(int i = 0; i < 12; i++) {
        if(tab[i] == number) {
            hits++;
        }
    }
    if(hits == 2) {
        return false;
    }
    return true;
}

QString Settings::random(int iterator) {
	srand(time(NULL));
    int number;
    do {
        number = 1 + rand() % 6;
    } while(!validation(number));
    tab[iterator] = number;
    return toString(number);
}

QString Settings::toString(int number) {
    return QString::number(number);
}

