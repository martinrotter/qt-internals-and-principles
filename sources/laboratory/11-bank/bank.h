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
	void withdrawalWanted(int sum);

    protected:
	void checkAccounts();
	Account *getAccountByName(const QString &name);

    protected slots:
	void serveAccount(int sum);

	private:
	QList<Account*> m_accounts;

	Account *m_sendingAccount;
	Account *m_waitingAccount;

};

#endif // BANK_H
