jobs: compile run
objects :=  ./lib/AbBinaryNode.o ./lib/PbBinaryNode.o ./lib/PbBST.o ./lib/AbBST.o

compile:
	g++ -std=c++11 -I ./headers/ -o ./lib/AbBinaryNode.o -c ./sources/AbBinaryNode.cpp
	g++ -std=c++11 -I ./headers/ -o ./lib/PbBinaryNode.o -c ./sources/PbBinaryNode.cpp
	g++ -std=c++11 -I ./headers/ -o ./lib/PbBST.o -c ./sources/PbBST.cpp
	g++ -std=c++11 -I ./headers/ -o ./lib/AbBST.o -c ./sources/AbBST.cpp
	g++ -std=c++11 -I ./headers/ -o ./BST $(objects) ./main.cpp

run:
	./BST