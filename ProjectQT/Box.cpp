#include "Box.h"
#include <QPushButton>


Box::Box(QPushButton *Button) {
	button = new QPushButton(Button);
	image = " ";
	isUncovered = false;
}

Box::~Box() {}

void Box::setImage(QString Image) {
	image = Image;
}
void Box::setCover(bool value) {
	isUncovered = value;
}

QPushButton* Box::getButton() {
	return button;
}

QString Box::getImage() {
	return image;
}

bool Box::getCover() {
	return isUncovered;
}
