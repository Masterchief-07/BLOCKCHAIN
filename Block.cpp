#include "Block.hpp"

Block::Block(int _index, Transaction d, size_t prevHash):
	index(_index),
	previousHash(prevHash),
	data(d)
{
	blockHash = GenerateHash();
}


size_t Block::GenerateHash()
{
	std::hash<std::string> hash1{};
	std::hash<size_t> hash2{};
	std::hash<size_t> finalHash{};
	std::string tohash = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);

	return finalHash( hash1(tohash) + hash2(previousHash));
}


size_t Block::GetHash() { return blockHash; }
size_t Block::GetPreviousHash() { return previousHash; }

bool Block::Is_Valid() { return GenerateHash() == blockHash; }
