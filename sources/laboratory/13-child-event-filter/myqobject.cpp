#include <QEvent>

#include "myqobject.h"


MyQObject::MyQObject(QObject *parent) : QObject(parent) {
    installEventFilter(this);
}

bool MyQObject::eventFilter(QObject *object, QEvent *event) {
    qDebug("Event happened in %s.", qPrintable(object->objectName()));

    if (event->type() == QEvent::ChildAdded) {
	qDebug("Observing child-event for %s and child %s.",
	       qPrintable(object->objectName()),
	       qPrintable(static_cast<QChildEvent*>(event)->child()->objectName()));
    }

    return QObject::eventFilter(object, event);
}
