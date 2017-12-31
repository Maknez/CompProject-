#include "settings.h"
#include "stdlib.h"
#include <iostream>
int tab[12];

Settings::Settings() {
	for (int i = 0; i<12; i++) {
		tab[i] = NULL;
	}
}

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
    int number;
    do {
        number = 1 + (rand() % static_cast<int>(6));
    } while(!validation(number));
    tab[iterator] = number;
    return toString(number);
}

QString Settings::toString(int number) {
    return QString::number(number);
}

