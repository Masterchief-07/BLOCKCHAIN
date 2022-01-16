#include "User.hpp"


User::User(std::string &name, double amount ,Blockchain &chain):_name(name), _amount(amount),_chain(chain)
{
	std::time_t ti = time(0);
	_id = std::hash<string>{}(name + to_string(ti));
}


User::~User()
{
	delete _chain;
}

void User::Send(double amount, User &receiver)
{
	_chain->AddTransaction(amount, *this, receiver);
}

void User::Receive(double amount)
{
	_amount += amount;
}


