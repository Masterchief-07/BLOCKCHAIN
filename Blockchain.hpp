#pragma once

#include "Block.hpp"
#include <vector>
#include <cassert>

class Blockchain
{
	public:
		Blockchain();
		~BlockChain();

		void AddTransaction(double const& amount, User const& sender, User const& receiver);
		bool const VerifyChain() const;

	private:
		vector<Block> _chain;
		void AddBlock(Transaction const& transact);
};
