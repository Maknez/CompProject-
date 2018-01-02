#include "box.h"
#include <QPushButton>

Box::Box(QPushButton * button) {
	isUncovered = false;
	this->button = button;
}

Box::~Box() {}

void Box::setButton(QPushButton *button) {
	this->button = button;
}

void Box::setImage(QString image) {
	this->image = image;
}
void Box::setCover(bool value) {
	this->isUncovered = value;
}

QPushButton* Box::getButton() {
	return this->button;
}

QString Box::getImage() {
	return this->image;
}

bool Box::getCover() {
	return this->isUncovered;
}
