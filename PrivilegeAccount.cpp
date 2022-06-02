#pragma once
#include "PrivilegeAccount.h"
void PrivilegeAccount::setOverdraft()
{
	long double am = getAmount();
	am /= 2;
	overdraft = am ;
}
void PrivilegeAccount::deposit(long double& money)
{
	setAmountUp(money);
	if (getAmount()>0)
	{
		setOverdraft();
	}
}

bool PrivilegeAccount::withdraw(long double& money)
{
	long double am = getAmount() + overdraft;
	if (money > am)
	{
		std::cout << "You can't withdraw that much money!";
		return false;
	}
	else if(money>getAmount() && money < am)
	{
		return setAmountDownOverdraft(money);
	}
	else
	{
		return setAmountDownOverdraft(money);
	}
	
}

void PrivilegeAccount::display() const
{
	std::cout << getName() << " " << getIban() << " " << getId() << " " << getAmount()
		<< " " << getDateOfCreation() << " " << overdraft;
}

void PrivilegeAccount::setOverdraft(int& s)
{
	overdraft = s;
}

Account* PrivilegeAccount::clone() const
{
	Account* newObj = new PrivilegeAccount(*this);
	return newObj;
}
