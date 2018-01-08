#ifndef Box_HEADER
#define Box_HEADER
#include <QPushButton>

class Box {
private:
	QPushButton *button;
	QString image;
	bool isUncovered;
public:
	Box(QPushButton*);
	~Box();
	void setButton(QPushButton *);
	void setImage(QString);
	void setCover(bool);
	QPushButton* getButton();
	QString getImage();
	bool getCover();
};
#endif