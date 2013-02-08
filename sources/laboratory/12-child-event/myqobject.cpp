#include <QChildEvent>

#include "myqobject.h"


MyQObject::MyQObject(QObject *parent) : QObject(parent) {
}

void MyQObject::childEvent(QChildEvent *event) {
    if (event->added()) {
	qDebug("Child %s (%s) was added to %s.",
	       event->child()->metaObject()->className(),
	       qPrintable(event->child()->objectName()),
	       qPrintable(objectName()));
    }
    else if (event->removed()) {
	qDebug("Child %s (%s) was removed from %s.",
	       event->child()->metaObject()->className(),
	       qPrintable(event->child()->objectName()),
	       qPrintable(objectName()));
    }

    QObject::childEvent(event);
}
