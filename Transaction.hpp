#pragma once

#include <ctime>
#include <string>

struct Transaction
{
	double amount;
	std::string senderKey;
	std::string receiverKey;

	std::time_t timestamp;
};

