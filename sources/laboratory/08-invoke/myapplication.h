#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QCoreApplication>

class MyApplication : public QCoreApplication {
	Q_OBJECT

    public:
	explicit MyApplication(int &argc, char **argv);
	
    public slots:
	void fancyMethod();
};

#endif // MYAPPLICATION_H
