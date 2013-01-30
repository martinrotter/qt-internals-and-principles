#include "myapplication.h"


MyApplication::MyApplication(int &argc, char **argv) : QCoreApplication(argc, argv) {
}

void MyApplication::fancyMethod() {
    qDebug("Somebody called me.");
}
