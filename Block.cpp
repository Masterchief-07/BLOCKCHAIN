#include "Block.hpp"

static size_t Block::index = 0;

Block::Block(size_t cosnt& phash):_prevHash(phash),_data(0, 0 , 0)
{
	index++;
	_hash = GenerateHash();
}

Block::Block(size_t const& phash, Transaction const& data):_prevHash(phash),_data(data)
{
	index++;
	_hash = GenerateHash();
}

Block::Block(size_t const& phash, double const amount, size_t const& sId, size_t const& rId):_prevHash(phash),_data(amount, sId, rId)
{
	index++;
	_hash = GenerateHash();
}

// **************************************
size_t const Block::GenerateHash() const
{
	std::string text = std::to_string(index) + _data.ToString() + std::to_string(_prevHash);
	return std::hash<string>{}(text);
}
