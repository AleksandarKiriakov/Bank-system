#pragma once
#include "Account.h"
class normalAccount : public Account
{
public:
	void deposit(long double&) override;
	bool withdraw(long double&) override;
	void display() const override;
	Account* clone() const override;
};
