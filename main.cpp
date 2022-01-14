#include <iostream>
#include "BlockChain.hpp"


int main()
{
	BlockChain eta;

	Transaction data1;
	std::time_t data1Time;
	data1.amount = 1000;
	data1.senderKey = "Jonathan";
	data1.receiverKey = "Josue";
	data1.timestamp = time(&data1Time);

	eta.AddBlock(data1);

	std::cout<<"is chain valid: "<< eta.IsChainValid() <<"\n";

	std::cout<<eta.chain.size()<<"\n";
	
	//try to modifie the chain
	Block *b = eta.GetLatestBlock();
	b->data.amount = 500;


	std::cout<<"is chain valid: "<< eta.IsChainValid() <<"\n";

	return 0;

}
