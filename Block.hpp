#pragma once
#include <cstint>
#include <iostream>

class Block
{
	public:
		string sPrevHash; //hash of prev block

		Block(std::uint32_t nIndex_n, const string &sDataIn);

		string GetHash();

		void MineBlock(std::uint32_t nDifficulty);

	private:
		std::uint32_t _nIndex;
		std::int64_t _nNonce;
		string _sData;
		string _sHash;
		std::time_t _tTime;

		string _CalculateHash() const;
		
};
