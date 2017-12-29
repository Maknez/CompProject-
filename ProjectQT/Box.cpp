#include "Box.h"
#include <QPushButton>


Box::Box(QPushButton *Button) {
	button = new QPushButton(Button);
	isUncovered = false;
}

Box::~Box() {
}

void Box::setImage(QString Image) {
	image = Image;
}

QString Box::getImage() {
	return image;
}
