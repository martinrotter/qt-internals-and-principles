#include "bank.h"
#include "account.h"


Bank::Bank(QObject *parent) : QObject(parent) {
    qDebug("Bank was created.");
}

void Bank::transfer(const QString &from, const QString &to, int sum) {
    if (sum <= 0) {
	qDebug("You cannot transfer sum %d USD.", sum);
	return;
    }

    checkAccounts();

    Account *acc_from;
    Account *acc_to;
    if ((acc_from = getAccountByName(from)) == NULL) {
	qDebug("Source account is not registered in this bank.");
	return;
    }
    if ((acc_to = getAccountByName(to)) == NULL) {
	qDebug("Destination account is not registered in this bank.");
	return;
    }

    m_sendingAccount = acc_from;
    m_waitingAccount = acc_to;
    connect(this, &Bank::withdrawalWanted, acc_from, &Account::withdrawMoney);
    connect(acc_from, &Account::withdrawn, this, &Bank::serveAccount);

    emit withdrawalWanted(sum);
}

void Bank::serveAccount(int sum) {
    m_waitingAccount->saveMoney(sum);
    m_sendingAccount->disconnect();
    disconnect();
}

Account *Bank::getAccountByName(const QString &name) {
    foreach (Account *account, m_accounts) {
	if (account->name().compare(name, Qt::CaseSensitive) == 0) {
	    return account;
	}
    }
    return NULL;
}

void Bank::checkAccounts() {
    m_accounts.clear();
    Account *account;

    foreach (QObject *child, children()) {
	if ((account = qobject_cast<Account*>(child)) != 0) {
	    m_accounts.push_back(account);
	}
    }
}

void Bank::printAccounts() {
    checkAccounts();

    qDebug("\n=== Bank accounts overview ===");
    foreach (Account *account, m_accounts) {
	account->status();
    }
    qDebug("=== Bank accounts overview ===\n");
}
