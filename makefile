all: main.cpp FileHandler.cpp FileHandler.hpp Product.hpp Product.cpp products.csv
	g++ -c FileHandler.cpp
	g++ -c Product.cpp
	g++ -c main.cpp
	g++ main.o FileHandler.o Product.o -o exec
run: all
	./exec products.csv
clean:
	rm *.o
	rm -f exec
