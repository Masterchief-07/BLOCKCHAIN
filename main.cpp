#include<iostream>
#include "Blockchain.hpp"
#include "User.hpp"

int main()
{
	Blockchain block;
	User jonathan{std::string{"jonathan"}, 1000.f, block};
	User josue{std::string{"josue"}, 1000.f, block};
	std::cout<<"jonathan amount : "<<jonathan.GetAmount()<<"\n";
	std::cout<<"josue amount : "<<josue.GetAmount()<<"\n";
	jonathan.Send(10, josue);
	std::cout<<"jonathan amount : "<<jonathan.GetAmount()<<"\n";
	std::cout<<"josue amount : "<<josue.GetAmount()<<"\n";

	return 0;
}
