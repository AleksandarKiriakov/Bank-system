#include "NormalAccount.h"
void normalAccount::deposit(long double& money)
{
	setAmountUp(money);
}

bool normalAccount::withdraw(long double& money)
{
	return setAmountDown(money);
}

void normalAccount::display() const
{
	std::cout << getName() << " " << getIban() << " " << getId() << " " << getAmount()
		<< " " << getDateOfCreation();
}
Account* normalAccount::clone() const
{
	Account* newObj = new normalAccount(*this);
	return newObj;
}