#pragma once

#include <functional>
#include "Transaction.hpp"

class Block
{
	public:
		Block(size_t cosnt& phash);
		Block(size_t cosnt& phash, Transaction const& data);
		Block(size_t cosnt& phash, double const amount, size_t const& sId, size_t const& rId);

		size_t const GetHash() const {return _hash;}
		size_t const GetPrevHash() const { return _prevHash;}
		bool const VerifyHash() const { return GenerateHash() == _hash;}
		~Block();

	private:
		static size_t index;
		size_t _prevHash;
		Transaction _data;
		size_t _hash;
		size_t const GenerateHash() const;

};
