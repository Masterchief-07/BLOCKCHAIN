#include "Block.hpp"
#include "sha256.hpp"

Block::Block(std::uint32_t nIndex_n, const string &sDataIn): _nIndex(nIndexIn), _sData(sDataIn)
{
	_nNonce = -1;
	_tTime = time(nullptr);
}

string Block::GetHash()
{
	return _sHash;
}

		void MineBlock(std::uint32_t nDifficulty);
