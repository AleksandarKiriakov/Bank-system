#pragma once
#include "Account.h"
class SavingsAccount : public Account 
{
	long double interestRate;
public:
	bool growMoney();
	void deposit(long double& money) override;
	bool withdraw(long double& money) override;
	void display() const override;
	Account* clone() const override;
	void setInterestRate(long double& s);
};