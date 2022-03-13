all:main.o Server.o Task.o
	g++ main.o Server.o Task.o -o main

main.o:main.cpp Server.h Task.h
	g++ -c main.cpp -o main.o

Server.o:Server.cpp Server.h Task.h
	g++ -c Server.cpp -o Server.o

Task.o:Task.cpp Task.h
	g++ -c Task.cpp -o Task.o

clean:
	rm *.o main