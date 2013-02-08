#ifndef MYQOBJECT_H
#define MYQOBJECT_H

#include <QObject>


class MyQObject : public QObject{
	Q_OBJECT

    public:
	explicit MyQObject(QObject *parent = 0);

    protected:
	void childEvent(QChildEvent *event);
};

#endif // MYQOBJECT_H
