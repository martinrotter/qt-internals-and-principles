#include <QCoreApplication>
#include <QObject>

#include "bank.h"
#include "account.h"


int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);


  // Create bank.
  Bank bank(&a);

  // Create two accounts with some initial cash and register both accounts in the bank.
  Account acc_mar("Martin", 15000, &bank);
  Account acc_car("Carl", 11000, &bank);

  bank.printAccounts();

  bank.transfer("Martin", "Carl", 12000);
  bank.printAccounts();

  bank.transfer("Carl", "Martin", 2000);
  bank.printAccounts();

  bank.transfer("Carl", "Martin", 25000);
  bank.printAccounts();

  qDebug("Application exit.");
  return a.exec();
}
