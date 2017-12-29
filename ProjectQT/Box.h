#include <QPushButton>

class Box {
	QPushButton *button;
	QString image;
	bool isUncovered;
public:
	Box(QPushButton *);
	~Box();
	void setImage(QString);
	QString getImage();
};
