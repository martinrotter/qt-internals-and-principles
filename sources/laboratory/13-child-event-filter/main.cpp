#include <QCoreApplication>

#include "myqobject.h"


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    MyQObject *object_1 = new MyQObject(); object_1->setObjectName("object_1");

    MyQObject *object_2 = new MyQObject(); object_2->setObjectName("object_2");
    object_2->setParent(object_1);

    MyQObject *object_3 = new MyQObject(); object_3->setObjectName("object_3");
    object_3->setParent(object_2);

    // object_2 is deleted and so is object_3.
    object_2->deleteLater();
    
    return a.exec();
}
