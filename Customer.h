#pragma once
#include "MyString.h"
#include <iostream>
class Customer
{
	int id;
	MyString name;
	MyString address;
public:
	void setName(MyString& name);
	void setAddress(MyString& address);
	void setId(int& id);
	void print() const;
	MyString getName() const;
	int getId() const;
};
