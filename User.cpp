#include "User.hpp"


User::User(std::string name, double amount ,Blockchain *block):_name(name), _amount(amount), _chain(block) 
{
	std::time_t ti = time(0);
	_id = std::hash<std::string>{}(name + std::to_string(ti));
}


User::~User()
{
	//delete _chain;
}

void User::Send(double amount, User &receiver)
{
	_chain->AddTransaction(amount, this->GetId(), receiver.GetId());
	receiver.Receive(amount);
	_chain->AddTransaction(-amount, this->GetId(), this->GetId());
	this->Receive(-amount);
}

void User::Receive(double amount)
{
	_amount += amount;
}


