#include<iostream>
#include "Blockchain.hpp"
#include "User.hpp"

int main()
{
	Blockchain block;
	User jonathan{std::string{"jonathan"}, 1000.f, block};

	return 0;
}
