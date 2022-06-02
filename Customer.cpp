#include "Customer.h"
#pragma once
void Customer::setName(MyString& name)
{
	this->name = name;
}

void Customer::setAddress(MyString& address)
{
		this->address = address;
}

void Customer::setId(int& id)
{
	this->id = id;
}

void Customer::print() const
{
	std::cout << id << " " << name << " " << address <<" ";
}

MyString Customer::getName() const
{
	return name;
}

int Customer::getId() const
{
	return id;
}
