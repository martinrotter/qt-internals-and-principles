#ifndef BANK_H
#define BANK_H

#include <QObject>


class Account;

class Bank : public QObject {
    Q_OBJECT

  public:
    explicit Bank(QObject *parent = 0);
    void printAccounts();
    void transfer(const QString &from, const QString &to, int sum);

  signals:
    // Emitted if both accounts are ready for money transfer and
    // money should be withdrawn from the first one.
    void withdrawalWanted(int sum);

  protected:
    // Seeks for accounts in children of this bank.
    void checkAccounts();

    // Returns account with given name or nullptr if no
    // such account exists.
    Account *getAccountByName(const QString &name);

  protected slots:
    // Adds given sum to account and disconnects
    // account.
    void serveAccount(int sum);

  private:
    QList<Account*> m_accounts;

    Account *m_sendingAccount;
    Account *m_waitingAccount;
};

#endif // BANK_H
