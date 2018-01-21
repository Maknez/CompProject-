#ifndef Box_HEADER
#define Box_HEADER
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
class Icon {
	private:
		QPushButton *button;
		QString image;
		bool isUncovered;
	public:
		Icon(QPushButton*);
		~Icon();
		void setButton(QPushButton *);
		void setImage(QString);
		void setCover(bool);
		QPushButton* getButton();
		QString getImage();
		bool getCover();
		void emitClick();
};

#endif