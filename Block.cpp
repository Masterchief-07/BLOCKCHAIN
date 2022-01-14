#include "Block.hpp"

Block::Block(int _index, Transaction d, size_t prevHash):
	index(_index),
	data(d),
	previousHash(prevHash)
{
	blockHash = GenerateHash();
}


size_t Block::GenerateHash()
{
	std::hash<string> hash1;
	std::hash<size_t> hash2;
	std::hash<size_t> finalHash;
	string tohash = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);

	return finalHash( hash1(toHash) + hash2(previousHash));
}


size_t Block::GetHash() { return blockHash; }
size_t Block::GetPreviousHash() { return previousHash; }

bool Is_valid() { return GenerateHash() == blockHash; }
