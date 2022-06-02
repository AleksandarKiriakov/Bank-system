#include "Account.h"

long double Account::getBalance() const
{
	return amount;
}

int Account::getId() const
{
	return id;
}

void Account::setPass(MyString& pass)
{
	this->pass=pass;
}

void Account::setUsername(MyString& Username)
{
	username = Username;
}

void Account::setIban(MyString& Iban)
{
	iban = Iban;
}

void Account::setId(int id)
{
	this->id = id;
}

void Account::setAmountUp(long double& money)
{
	amount += money;
}

bool Account::setAmountDown(long double& money)
{
	if (amount>=money)
	{
		amount -= money;
		return true;
	}
	else
	{
		return false;
	}
}
bool Account::setAmountDownOverdraft(long double& money)
{
		amount -= money;
		return true;
}
void Account::setDateOfCreation()
{
	time_t timer;
	time(&timer);
	dateOfCreation = timer;
}

MyString Account::getName() const
{
	return username;
}

MyString Account::getIban() const
{
	return iban;
}

long double Account::getAmount() const
{
	return amount;
}

time_t Account::getDateOfCreation() const
{
	
	return dateOfCreation;
}

MyString Account::getPass() const
{
	return pass;
}
