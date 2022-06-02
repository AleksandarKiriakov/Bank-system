#pragma once
#include "MyString.h"
#include "Customer.h"
#include "Account.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include "AllAccounts.h"
#include <cstring>
class Bank {
	MyString name;
	MyString address;
	Customer* customers;
	int customCount;
	AllAccounts accounts;
	int accCount;
	mutable MyString Log;
	template <typename T>
	void resizeUp(T*& s,int& r);
	void free();
	void copyFrom(const Bank& other);
	bool isRealIban(MyString& fromIban, int& i);
public:
	Bank();
	Bank operator=(const Bank& other);
	Bank(const Bank& other);
	~Bank();
	void opening()const;
	void addCustomer(MyString& name,int& id, MyString& address);
	void deleteCustomer(long double id);
	void addAccount(MyString& pass, MyString& username, long double& money, int id, MyString& iban,int typeOfAcc);
	void deleteAccount(long double id);
	void listCustomers();
	void listAccount();
	void listCustomerAccount(long double id);
	void exportLog();
	void transfer(long double& money,MyString& fromIban, MyString& toIban);
	void display();
	void listLog() const;
	void depositToAccount(long double& money, MyString& iban);
	void setName(MyString& nameOfBank);
	void setAddress(MyString& Address);
	bool withdrawFromAccount(long double& money, MyString & iban, MyString & pass, MyString & username);
};
