#include "Bank.h"
#include <fstream>
#include <iomanip>
#include <cstring>
#pragma warning(disable:4996)
#include <iostream>
template <typename T>
void Bank::resizeUp(T*& s,int& r)
{
	r++;
	T* newString = new T[r];
	if (r > 1)
	{
		for (int i = 0; i < r-1 ; i++)
		{
			newString[i] = s[i];
		}
	}
	s = newString;
	newString = nullptr;
}
void Bank::addCustomer(MyString& name, int& id, MyString& address)
{
	bool boolIsEmpty = false;
	int i = 0;
	for (; i < customCount; i++)
	{
		if (customers[i].getName()==nullptr)
		{
			boolIsEmpty = true;
			break;
		}
	}
	if (!boolIsEmpty)
	{
		resizeUp(customers, customCount);
		customers[customCount-1].setAddress(address);
		customers[customCount-1].setId(id);
		customers[customCount-1].setName(name);
	}
	else
	{
		customers[i].setAddress(address);
		customers[i].setId(id);
		customers[i].setName(name);
	}
	
}
void Bank::deleteCustomer(long double id)
{
	Customer* s = new Customer[customCount];
	for (int i = 0; i < customCount; i++)
	{
		if (customers[i].getId() == id)
		{
			continue;
		}
		s[i] = customers[i];
	}
	delete[] customers;
	customers = s;
}
void Bank::addAccount(MyString& pass, MyString& username, long double& money,int id,MyString& iban, int typeOfAcc)
{
	bool isValidId = false;
	for (int i = 0; i < customCount; i++)
	{
		if (customers[i].getId()==id)
		{
			isValidId = true;
		}
	}
	if (!isValidId)
	{
		std::cout << "User does not exist";
		return;
	}
	accCount++;
	if (typeOfAcc==1)
	{
		accounts.addAcount(normalAccount(),pass,username,money,id,iban);
	}
	else if (typeOfAcc == 2)
	{
		accounts.addAcount(PrivilegeAccount(), pass, username, money, id, iban);
	}
	else if (typeOfAcc == 3)
	{
		accounts.addAcount(SavingsAccount(), pass, username, money, id, iban);
	}
	
}

void Bank::deleteAccount(long double id)
{
	
	for (int i = 0; i < accCount; i++)
	{
		if (accounts.getId(i) == id)
		{
			accounts.deleteId(i);
			break;
		}
	}
	
	
}
void Bank::listCustomers()
{
	for (int i = 0; i < customCount; i++)
	{
		customers[i].print();
		std::cout << std::endl;
	}
}
void Bank::listAccount()
{
		accounts.display();
}
void Bank::listCustomerAccount(long double id)
{
	for (int i = 0; i < accCount; i++)
	{
		if (accounts.getId(i) == id)
		{
			accounts.displayCustomer(i);
			std::cout << std::endl;
		}
	}
}
void Bank::exportLog()
{
	std::ofstream file("Log.txt");
	if (!file.is_open())
	{
		std::cout << "Error opening file";
		return;
	}
	file << Log << std::endl;
	try
	{
		file.close();
	}
	catch (const std::exception&)
	{
		std::cout << "error closing file";
	}
	
}
void Bank::transfer(long double& money, MyString& fromIban, MyString& toIban)
{
	Log += "Transfer ";
	Log += (int)money;
	Log += " from ";
	Log += fromIban;
	Log += " to ";
	Log += toIban;
	Log += " ";
	int posFiban = 0;
	int posTiban = 0;
	if (isRealIban(fromIban, posFiban)&& isRealIban(toIban, posTiban))
	{
		accounts.transfer(posFiban, posTiban,money);
	}
}
void Bank::display()
{
	std::cout << name << std::endl << address << std::endl << customCount << std::endl << accCount << std::endl;
}
void Bank::listLog() const
{
	std::cout << Log;
}

void Bank::depositToAccount(long double& money, MyString& iban)
{
	for (int i = 0; i < accCount; i++)
	{
		if (accounts.getIban(i) == iban) 
		{
			accounts.deposit(money, i);
			break;
		}
	}
}
void Bank::setName(MyString& nameOfBank)
{
	name += nameOfBank;
}
void Bank::setAddress(MyString& Address)
{
	address += Address;
}
bool Bank::withdrawFromAccount(long double& money, MyString& iban, MyString& pass, MyString& username)
{
	for (int i = 0; i < accCount; i++)
	{
		if (accounts.getIban(i)==iban && accounts.getName(i)==username && accounts.getPass(i)==pass)
		{
			return accounts.withdraw(money, i);
		}
	}
	return false;
}
void Bank::free()
{
	delete[] customers;
	customCount = 0;
	accCount = 0;
}
void Bank::copyFrom(const Bank& other)
{
	name = other.name;
	address = other.address;
	customCount = other.customCount;
	customers = new Customer[customCount];
	for (int i = 0; i < customCount; i++)
	{
		customers[i] = other.customers[i];
	}
	accCount = other.accCount;
	accounts = other.accounts;
	Log = other.Log;
}
bool Bank::isRealIban(MyString& fromIban, int& i)
{
	for (; i < accCount; i++)
	{
		if (accounts.getIban(i)== fromIban)
		{
			return true;
		}
	}
	return false;
}
Bank::Bank()
{
	customers = nullptr;
	customCount = 0;
	accCount = 0;
}

Bank Bank::operator=(const Bank& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Bank::Bank(const Bank& other)
{
	copyFrom(other);
}
Bank::~Bank()
{
	free();
}

void Bank::opening() const
{
	std::ifstream file("Log.txt");

	if (!file.is_open())
	{
		std::cout << "Error opening file";
		return;
	}
	
	char* line = new char[1024];
	while (!file.eof())
	{
		file.getline(line, 1024);
		Log += line;
	}
	file.clear();
	try
	{
		file.close();
	}
	catch (const std::exception&)
	{
		std::cout << "Error closing file";
	}
}

