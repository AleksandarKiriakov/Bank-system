#pragma once
#include "Account.h"
class AllAccounts
{
	Account** accounts;
	int accountsCount;
	int capacity;

	void free();
	void copyFrom(const AllAccounts& other);
	void resize();

public:
	AllAccounts();
	AllAccounts(const AllAccounts& other);
	AllAccounts& operator=(const AllAccounts& other);
	~AllAccounts();

	void display()const;
	void displayCustomer(int i)const;
	int getId(int i)const;
	void addAcount(const Account& account, MyString& pass, MyString& username, long double& money, int id, MyString& iban);
	void transfer(int postFiban, int posTiban, long double& money);
	MyString getIban(int i) const;
	MyString getName(int i)const;
	MyString getPass(int i)const;
	bool withdraw(long double& money, int i);
	void deposit(long double& money, int i);
	void deleteId(int i);
};