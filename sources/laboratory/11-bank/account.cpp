#include "account.h"
#include "bank.h"


Account::Account(const QString &owner, int deposit, Bank *parent)
  : QObject(parent), m_owner(owner), m_deposit(deposit < 0 ? 0 : deposit) {
  qDebug("Account '%s' with initial deposit %d USD created.",
         qPrintable(m_owner),
         m_deposit);
}

void Account::withdrawMoney(int sum) {
  if (sum < 0 || sum > m_deposit) {
    qDebug("Sum of %d USD NOT withdrawn from account '%s'.", sum, qPrintable(m_owner));
  }
  else {
    m_deposit -= sum;
    qDebug("Sum of %d USD withdrawn from account '%s'.", sum, qPrintable(m_owner));
    emit withdrawn(sum);
  }
}

void Account::saveMoney(int sum) {
  if (sum > 0) {
    m_deposit += sum;
    qDebug("Sum of %d USD saved in account '%s'.", sum, qPrintable(m_owner));
    emit saved(sum);
  }
  else {
    qDebug("Sum of %d USD NOT saved in account '%s'.", sum, qPrintable(m_owner));
  }
}

QString Account::name() {
  return m_owner;
}

void Account::status() {
  qDebug("Account name: %s\n"
         "Deposit: %d",
         qPrintable(m_owner),
         m_deposit);
}
