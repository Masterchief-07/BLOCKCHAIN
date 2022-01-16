#pragma once

#include "Blockchain.hpp"
#include <ctime>

class User
{
	public:
		User(std::string name, double amount ,Blockchain &chain);
		~User();

		void Send(double amount, User &receiver);
		void Receive(double amount);

		size_t const GetId() const {return _id;}
		double const GetAmount() const{return _amount;}

	private:
		std::string _name;
		double _amount;
		size_t _id;
		Blockchain *_chain;

};
