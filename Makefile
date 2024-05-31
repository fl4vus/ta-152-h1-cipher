t152h1: main.o
	g++ main.o -o bin/t152h1
	
main.o: main.cpp functions.h manp.h
	g++ -c main.cpp
	
clean:
	rm -rf main.o *.gch


