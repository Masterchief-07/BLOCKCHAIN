#include "Blockchain.hpp"

Blockchain::Blockchain()
{
	Block genesis{0, 0, 0, 0};
	_chain.emplace_back(genesis);
}


void Blockchain::AddTransaction(double const& amount, User const& sender, User const& receiver)
{
	Transaction transact{amount, sender.GetId(), receiver.GetId()};
	AddBlock(transact);
}

void BlockChain::AddBlock(Transaction const& transact)
{
	assert(_chain.size() > 1);
	block nblock(_chain.back()->GetHash(), transact);
	_chain.push_back(nblock);
}


bool const BlockChain::VerifyChain() const
{
	int i = 0;
	for(auto block = chain.begin(); block != chain.end(); ++block, i++)
	{
		assert(block->verifyHash());
		if(i>0)
			assert((block-1)->GetHash() == block->GetPrevHash());
	}
}
		
