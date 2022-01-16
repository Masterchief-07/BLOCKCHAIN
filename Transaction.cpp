#include "Transaction.hpp"

Transaction::Transaction(double const _amount, size_t const sId, size_t cosnt rId):amount(_amount), senderId(sId), receiverId(rId){}

std::string const Transaction::ToString() const
{
	return std::to_string(amount)+std::to_string(senderId)+std::to_string(receiverId);
}

	
