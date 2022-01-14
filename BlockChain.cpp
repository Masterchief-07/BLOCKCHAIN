#include "BlockChain.hpp"

BlockChain::BlockChain()
{
	Block genesis = CreateGenesisBlock();
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

	std::hash<int> hash1;
	Block genesis(0, data, hash1(0));
	return genesis;
}

Block *BlockChain::GetLatestBlock() { return &chain.back(); }

void BlockChain::AddBlock(Transaction d)
{
	int index = (int)chain.size() - 1;
	Block newBlock{index, d, GetLatestBlock()->GetHash()};
	chain.emplace_back(newBlock);
}

bool BlockChain::IsChainValid()
{
	int i = 0;
	for(auto it = chain.begin(); it!= chain.end(); ++it, ++i)
	{
		Block &currentBlock = *it;
		if(!it->Is_Valid())
			return false;

		if(i>0)
		{
			Block &previousBlock = *(it-1);
			if(currentBlock.GetPreviousHash() != previousBlock.GetHash())
				return false;

		}
	}
	return true;
}

