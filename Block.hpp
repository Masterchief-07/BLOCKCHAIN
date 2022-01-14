#pragma once
#include <functional>
#include "Transaction.hpp"

class Block
{
	private:
		int index;
		size_t blockHash;
		size_t previousHash;
		size_t GenerateHash();

	public:
		Block(int index, Transaction d, size_t prevHash);
		
		size_t GetHash();
		size_t GetPreviousHash();

		Transaction data;
		
		bool Is_Valid();

};
