all:
	mkdir -p bin
	g++ -static-libgcc -static-libstdc++ -std=c++11 budget.cpp -o bin/budget