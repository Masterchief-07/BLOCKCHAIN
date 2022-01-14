eta: main.cpp Transaction.cpp Block.cpp BlockChain.cpp
	g++ $^ -std=c++17 -Wall -o $@

all: eta

clean:
	rm -rf eta
