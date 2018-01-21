#include "icon.h"
#include <QPushButton>
#include <windows.h>
#include <QObject>
Icon::Icon(QPushButton * button) {
	isUncovered = false;
	this->button = button;
}

Icon::~Icon() {}

void Icon::setButton(QPushButton *button) {
	this->button = button;
}

void Icon::setImage(QString image) {
	this->image = image;
}
void Icon::setCover(bool value) {
	this->isUncovered = value;
}

QPushButton* Icon::getButton() {
	return this->button;
}

QString Icon::getImage() {
	return this->image;
}

bool Icon::getCover() {
	return this->isUncovered;
}

void Icon::emitClick() {
	//Sleep(100);
	this->button->click();
}

