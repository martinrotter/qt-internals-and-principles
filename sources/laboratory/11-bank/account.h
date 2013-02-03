#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>


class Bank;

class Account : public QObject {
	Q_OBJECT

    public:
	explicit Account(const QString &owner,
			 int deposit,
			 Bank *parent);

	// These are NOT slots.
	void status();
	QString name();

    public slots:
	// Used by customer who requests money from his account.
	// Customer can be either bank or account owner.
	void withdrawMoney(int sum);

	// Used by customer to save money to this account.
	// Customer can be either bank or account owner.
	void saveMoney(int sum);

    signals:
	// Emitted when money is withdrawn successfully from this account.
	void withdrawn(int sum);

	// Emitted when money is saved successfully into this account.
	void saved(int sum);

    private:
	QString m_owner;
	int m_deposit;
};

#endif // ACCOUNT_H
