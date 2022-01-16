#pragma once
#include <string>

struct Transaction
{
	double amount = 0;
	size_t senderId = 0;
	size_t receiverId = 0;
	
	Transaction(double const amount, size_t const& senderId, size_t const& receiverId);
	std::string const ToString() const;
};
