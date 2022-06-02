#include "AllAccounts.h"

void AllAccounts::free()
{
	for (int i = 0; i < accountsCount; i++)
		delete accounts[i];
	delete[] accounts;
}
void AllAccounts::copyFrom(const AllAccounts& other)
{
	accounts = new Account *[other.capacity];
	accountsCount = other.accountsCount;
	capacity = other.capacity;

	for (int i = 0; i < accountsCount; i++)
	{
		accounts[i] = other.accounts[i]->clone();
	}
}
void AllAccounts::resize()
{
	Account** newCollection = new Account * [capacity *= 2];
	for (int i = 0; i < accountsCount; i++)
		newCollection[i] = accounts[i];
	delete[] accounts;
	accounts = newCollection;
}
void AllAccounts::addAcount(const Account& account, MyString& pass, MyString& username, long double& money, int id, MyString& iban)
{
	
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i] == nullptr)
		{
			accounts[i]->setDateOfCreation();
			accounts[i] = account.clone();
			accounts[i]->setIban(iban);
			accounts[i]->setId(id);
			accounts[i]->setPass(pass);
			accounts[i]->setUsername(username);
			accounts[i]->deposit(money);
			return;
		}
	}
	if (accountsCount == capacity)
		resize();
	accounts[accountsCount - 1]->setDateOfCreation();
	accounts[accountsCount++] = account.clone();
	accounts[accountsCount-1]->setIban(iban);
	accounts[accountsCount-1]->setId(id);
	accounts[accountsCount-1]->setPass(pass);
	accounts[accountsCount-1]->setUsername(username);
	accounts[accountsCount-1]->deposit(money);
	
}
void AllAccounts::transfer(int posFiban, int posTiban, long double& money)
{
	accounts[posFiban]->withdraw(money);
	accounts[posTiban]->deposit(money);
}
MyString AllAccounts::getIban(int i) const
{
	return accounts[i]->getIban();
}
MyString AllAccounts::getName(int i) const
{
	return accounts[i]->getName();
}
MyString AllAccounts::getPass(int i) const
{
	return accounts[i]->getPass();
}
bool AllAccounts::withdraw(long double& money, int i)
{
	return accounts[i]->withdraw(money);
}
void AllAccounts::deposit(long double& money, int i)
{
	accounts[i]->deposit(money);
}
void AllAccounts::deleteId(int i)
{
	Account** s = new Account * [capacity];
	for (int j = 0; j < accountsCount; j++)
	{
		if (j==i)
		{
			s[j] = nullptr;
			continue;
		}
		s[j] = accounts[j];
	}
	delete[] accounts;
	accounts = s;
}
AllAccounts::AllAccounts()
{
	capacity = 8;
	accountsCount = 0;
	accounts = new Account * [capacity];
}
AllAccounts::AllAccounts(const AllAccounts& other)
{
	copyFrom(other);
}
AllAccounts& AllAccounts::operator=(const AllAccounts& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
AllAccounts::~AllAccounts()
{
	free();
}

void AllAccounts::display() const
{
	for (int i = 0; i < accountsCount; i++)
	{
		if (accounts[i]!=nullptr)
		{
			accounts[i]->display();
			std::cout << std::endl;
		}
	}
	
}

void AllAccounts::displayCustomer(int i) const
{
	accounts[i]->display();
}

int AllAccounts::getId(int i) const
{
	return accounts[i]->getId();
}
