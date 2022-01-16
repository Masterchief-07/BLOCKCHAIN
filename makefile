params = -std=c++17 -Wall

main: main.cpp Transaction.cpp Block.cpp Blockchain.cpp User.cpp
	g++ $(params) $^ -o $@

all : main

clean:
	rm -rf main
