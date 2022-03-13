all:main.o Server.o
	g++ main.o Server.o -o main

main.o:main.cpp Server.h Task.h
	g++ -c main.cpp -o main.o

Server.o:Server.cpp Server.h Task.h
	g++ -c Server.cpp -o Server.o

clean:
	rm *.o main