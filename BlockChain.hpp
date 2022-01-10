#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include "Block.h"

class BlockChain
{
	public:
		BlockChain();

		void AddBlock(Block bNew);

	private:
		std::uint32_t _nDifficulty;
		vector<block> _vChain;

		block _GetLastBlock() const;

};
