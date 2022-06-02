#pragma once
#include <ctime>
#include "MyString.h"
#include <iostream>
class Account
{
	MyString username;
	MyString pass;
	MyString iban;
	int id;
	long double amount;
	time_t dateOfCreation;
public:
	virtual ~Account()=default;
	virtual Account* clone()  const = 0;
	virtual void deposit(long double&) = 0;
	virtual bool withdraw(long double&) = 0;
	virtual void display() const = 0;
	long double getBalance() const;
	int getId()const;
	void setPass(MyString& pass);
	void setUsername(MyString& Username);
	void setIban(MyString& Iban);
	void setId(int id);
	void setAmountUp(long double& money);
	bool setAmountDown(long double& money);
	bool setAmountDownOverdraft(long double& money);
	void setDateOfCreation();
	MyString getName() const;
	MyString getIban() const;
	long double getAmount() const;
	time_t getDateOfCreation()const;
	MyString getPass() const;
};
