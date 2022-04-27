lab3:main

main: main.o
	g++ main.o -o main

main.o: lab3/src/main.cpp
	g++ -Wall -std=c++14 -c lab3/src/main.cpp


clean:
	rm -rf *o main
