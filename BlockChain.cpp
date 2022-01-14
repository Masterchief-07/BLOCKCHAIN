#include "BlockChain.hpp"

BlockCHain::BlockCHain()
{
	block genesis = CreateGenesisBlock();
	chain.push_back(genesis);
}

Block BlockChain::CreateGenesisBlock()
{
	std::time_t current;
	Transaction data;
	data.amount = 0;
	data.receiverKey = "None";
	data.senderKey = "None";
	data.timestamp = time(&current);

	hash<int> hash1;
	block genesis(0, d, hash1(0));
	return genesis;
}

Block *BlockChain::GetLatestBlock() { return &chain.back(); }

void BlockChain::AddBlock(Transaction d)
{
	int index = (int)chain.size() - 1;
	Block newBlock(index, d, getLatestBlock()->getHash());
	if(newBlock.IsValid())
		chain.push_back(newBlock);
}

bool BlockChain::isChainValid()
{
	int chainLen = (int) chain.size();
	for(auto it = chain.begin(); it!= chain.end(); ++it)
	{
		Block currentBlock = *it;
		if(!it->isHashValid())
			return false

		if(chain>1)
		{
			Block previousBlock = *(it-1);
			if(currentBlock.GetPreviousHash() != previousBlock.GetHash())
				return false

		}
	}
	return true;
}

