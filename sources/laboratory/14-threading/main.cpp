#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrentRun>


void faktorial(int input) {
    qDebug().nospace() << "Factorial from thread " << QThread::currentThreadId() << ".";

    if (input < 0) {
	return;
    }

    int result = 1;
    for (int i = 1; i <= input; i++) {
	result *= i;
    }

    qDebug() << result;
}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Call everyhing from main thread.
    qDebug() << "Main thread is " << QThread::currentThreadId() << ".";

    // Use QtConcurrent for glogal function.
    QFuture<void> result = QtConcurrent::run(faktorial, int(5));
    result.waitForFinished();

    return a.exec();
}
