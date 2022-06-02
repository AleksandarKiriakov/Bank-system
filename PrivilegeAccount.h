#pragma once
#include "Account.h"
class PrivilegeAccount : public Account
{
	long double overdraft;
public:
	void setOverdraft();
	void deposit(long double& money) override;
	bool withdraw(long double& money) override;
	void display()const override;
	void setOverdraft(int& s);
	Account* clone() const override;
};