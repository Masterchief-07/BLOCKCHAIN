#include "Blockchain.hpp"

Blockchain::Blockchain()
{
	Block genesis{0, 0, 0, 0};
	_chain.emplace_back(genesis);
}

void Blockchain::AddTransaction(double amount, size_t const& sId, size_t const& rId)
{
	Transaction tran{amount, sId, rId};
	this->AddBlock(tran);
}
void Blockchain::AddBlock(Transaction const& transact)
{
	assert(_chain.size() > 0);
	Block nblock(_chain.back().GetHash(), transact);
	_chain.push_back(nblock);
}


bool const Blockchain::VerifyChain() const
{
	int i = 0;
	for(auto block = _chain.begin(); block != _chain.end(); ++block, i++)
	{
		assert(block->VerifyHash());
		if(i>0)
			assert((block-1)->GetHash() == block->GetPrevHash());
	}
	return true;
}
		
