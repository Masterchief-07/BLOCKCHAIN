#pragma once

#include "Block.hpp"
#include <vector>
#include <cassert>

class Blockchain
{
	public:
		Blockchain();

		void AddTransaction(double amount, size_t const& sId, size_t const& rId);
		bool const VerifyChain() const;

	private:
		std::vector<Block> _chain;
		void AddBlock(Transaction const& transact);
};
