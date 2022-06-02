#include <iostream>
#include "Bank.h"
using namespace std;
int main()
{
	int id = 0;
	Bank bank;
	bank.opening();
	cout << endl;
	MyString name;
	cout << "Name of bank: ";
	cin >> name;
	bank.setName(name);
	cout << "Address of bank: ";
	cin >> name;
	bank.setAddress(name);
	
	long double choice;
	while (true)
	{
		id++;
		cout << endl;
		cout << "1.Edit" << endl << " 2.List" << endl
			<< "3.Action" << endl
			<< "4.Display info for the bank"
			<< endl << "5.Quit";
		cout << endl << "Enter number: ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			cout << "1.Customer" << endl << "2.Account" << endl;
			cout << endl << "Enter number: ";
			cin >> choice;
			cout << endl;
			if (choice == 1)
			{
				cout << "1.Add new customer" << endl << "2.Delete customer" << endl;
				cout << "Enter number: ";
				cin >> choice;
				cout << endl;
				if (choice == 1)
				{
					MyString address;
					cout << "Enter name: ";
					cin >> name;
					cout << "Enter address: ";
					cin >> address;
					cout << "Your id is: " << id;
					bank.addCustomer(name,id,address);
					continue;
				}
				else if (choice == 2)
				{
					cout << "Enter id: ";
					cin >> choice;
					bank.deleteCustomer(choice);
					continue;
				}
			}
			else if (choice == 2)
			{
				cout << "1.Add new account" << endl << "2.Delete account" << endl;
				cout << "Enter number: ";
				cin >> choice;
				cout << endl;
				if (choice == 1)
				{
					cout << "What type of account: 1. Normal account, 2.PrivilegeAccount, 3.SavingsAccount"<<endl;
					cout << "Enter your choice: ";
					cin >> choice;
					if (choice==1)
					{
						int yourId;
						MyString password, iban;
						cout << "Enter name: ";
						cin >> name;
						cout << "Enter password: ";
						cin >> password;
						cout << "Enter money: ";
						cin >> choice;
						cout << "Enter your id: ";
						cin >> yourId;
						iban += "BG";
						iban += id;
						iban += yourId;
						bank.addAccount(password, name, choice, yourId, iban,1);
						cout << "Your Iban: " << iban << " Your id: " << yourId << endl;
						continue;
					}
					else if (choice == 2)
					{
						int yourId;
						MyString password, iban;
						cout << "Enter name: ";
						cin >> name;
						cout << "Enter password: ";
						cin >> password;
						cout << "Enter money: ";
						cin >> choice;
						cout << "Enter your id: ";
						cin >> yourId;
						iban += "BG";
						iban += id;
						iban += yourId;
						bank.addAccount(password, name, choice, yourId, iban,2);
						cout << "Your Iban: " << iban << " Your id: " << yourId << endl;
						continue;

					}
					else if (choice == 3)
					{
						int yourId;
						MyString password, iban;
						cout << "Enter name: ";
						cin >> name;
						cout << "Enter password: ";
						cin >> password;
						cout << "Enter money: ";
						cin >> choice;
						cout << "Enter your id: ";
						cin >> yourId;
						iban += "BG";
						iban += id;
						iban += yourId;
						bank.addAccount(password, name, choice,yourId, iban,3);
						cout << "You can withdraw your money only after 5 years"<<endl;
						cout << "After this 5 years your money will be equal to: money/(money*70)" << endl;
						cout << "Your Iban: " << iban << " Your id: " << yourId << endl;
						continue;
					}
				}
				else if (choice == 2)
				{
					cout << "Enter id: ";
					cin >> choice;
					bank.deleteAccount(choice);
					continue;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "1.List all customers" << endl << " 2. List all accounts" << endl
				<< "3.List customer accounts" << endl<< "4.List log"<<endl;
			cout << "Enter number: ";
			cin >> choice;
			if (choice == 1)
			{
				bank.listCustomers();
				continue;
			}
			else if(choice == 2)
			{
				bank.listAccount();
				continue;
			}
			else if (choice == 3)
			{
				cout << endl << "Enter id: ";
				cin >> choice;
				bank.listCustomerAccount(choice);
				continue;
			}
			else if (choice == 4)
			{
				bank.listLog();
				continue;
			}
		}
		else if (choice == 3)
		{
			cout << "1.Withdraw from account" << endl << " 2.Deposit to account" << endl
				<< "3.Transfer" << endl;
				cout << "Enter number: ";
			cin >> choice;
			if (choice==1)
			{
				MyString iban,pass,username;
				long double money;
				cout << "Enter money: ";
				cin >> money;
				cout << endl << "Enter IBAN :";
				cin >> iban;
				cout << endl << "Enter password :";
				cin >> pass;
				cout << endl << "Enter username :";
				cin >> username;
				if (!(bank.withdrawFromAccount(money, iban, pass, username)))
				{
					cout << "You cant withdraw from that account"<<endl;
				}
				continue;
			}
			else if (choice == 2)
			{
				MyString iban;
				long double money;
				cout << "Enter money: ";
				cin >> money;
				cout << endl << "Enter IBAN :";
				cin >> iban;
				bank.depositToAccount(money, iban);
			}
			else if (choice == 3)
			{
				MyString fromIban, toIban;
				cout << "Enter count of money: ";
				cin >> choice;
				cout << endl << "Enter your IBAN: ";
				cin >> fromIban;
				cout << endl << "Enter other IBAN: ";
				cin >> toIban;
				bank.transfer(choice, fromIban, toIban);
				continue;
			}
		}
		else if (choice == 4)
		{
			bank.display();
			continue;
		}
		else if (choice == 5)
		{
			bank.exportLog();
			break;
		}
	}
}

