#include <QCoreApplication>
#include <QThread>
#include <QDebug>

#define APP_LOW_NAME "NAME"


void debug_handler(QtMsgType type, const QMessageLogContext &placement, const QString &message) {
  switch (type) {
    case QtDebugMsg:
      fprintf(stderr, "[%s] INFO (%s, line %d) : %s\n",
              APP_LOW_NAME,
              placement.file,
              placement.line,
              qPrintable(message));
      break;
    case QtWarningMsg:
      fprintf(stderr, "[%s] WARNING (%s, line %d) : %s\n",
              APP_LOW_NAME,
              placement.file,
              placement.line,
              qPrintable(message));
      break;
    case QtCriticalMsg:
      fprintf(stderr, "[%s] CRITICAL (%s, line %d) : %s\n",
              APP_LOW_NAME,
              placement.file,
              placement.line,
              qPrintable(message));
      break;
    case QtFatalMsg:
      fprintf(stderr, "[%s] FATAL (%s, line %d) : %s\nApplication is halting now.\n",
              APP_LOW_NAME,
              placement.file,
              placement.line,
              qPrintable(message));
      qApp->exit(EXIT_FAILURE);
  }
}

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  // Create new QT_MESSAGE_PATTERN environment variable.
  qputenv("QT_MESSAGE_PATTERN",
          "[%{type}] %{appname} (%{file}:%{line}) - %{message}");

  // Print messages using QT_MESSAGE_PATTERN.
  qDebug() << "First information.";
  qDebug("Second information from %s.", "Martin");

  // Install custom message handler.
  qInstallMessageHandler(debug_handler);

  // Printing out custom type.
  qWarning() << QThread::currentThreadId();

  // No way to continue.
  qFatal("This is custom error message.");

  return a.exec();
}
