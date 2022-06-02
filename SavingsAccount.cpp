#include "SavingsAccount.h"
bool SavingsAccount::growMoney()
{
	time_t timer;
	unsigned long long int realTimeDate = time(&timer);
	realTimeDate += getDateOfCreation();
	unsigned long long int dateAfer5YearsOfCreation = getDateOfCreation();
	dateAfer5YearsOfCreation += 157680000;
	if (dateAfer5YearsOfCreation <= realTimeDate)
	{
		long double money = getAmount();
		money *= interestRate;
		setAmountUp(money);
		return true;
	}
	return false;
}
void SavingsAccount::deposit(long double& money)
{
	long double interestRate = (money / (money * 0.7));
	setInterestRate(interestRate);
	setAmountUp(money);
	growMoney();
}

bool SavingsAccount::withdraw(long double& money)
{
	
	if (growMoney())
	{
		return setAmountDownOverdraft(money);
	}
	return false;
}

void SavingsAccount::display() const
{
	std::cout << getName() << " " << getIban() << " " << getId() << " " << getAmount()
		<< " " << getDateOfCreation() << " " << interestRate;
}

void SavingsAccount::setInterestRate(long double& s)
{
	interestRate = s;
}


Account* SavingsAccount::clone() const
{
	Account* newObj = new SavingsAccount(*this);
	return newObj;
}
