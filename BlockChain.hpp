#pragma once 
#include "Block.hpp"
#include <vector>

class BlockChain
{
	private:
		Block CreateGenesisBlock();
	
	public:
		std::vector<Block> chain;
		
		BlockChain();

		void AddBlock(Transaction Data);
		bool IsChainValid();

		Block *GetLatestBlock();
};
