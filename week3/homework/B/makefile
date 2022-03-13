all:main.o product.o sum.o
	g++ main.o product.o sum.o -o main

main.o:main.cpp functions.h
	g++ -c main.cpp -o main.o

product.o:product.cpp functions.h
	g++ -c product.cpp -o product.o

sum.o:sum.cpp functions.h
	g++ -c sum.cpp -o sum.o

clean:
	rm *.o main

debug:
	g++ -c product.cpp -o product.o -g -D DEBUG
	g++ -c sum.cpp -o sum.o -g -D DEBUG
	make all