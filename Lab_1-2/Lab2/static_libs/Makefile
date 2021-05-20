all: main employee lib 
	g++ -o program main.o -L. -lemployee
lib: Employee.o
	ar cr libemployee.a Employee.o
employee: Employee.cpp
	g++ -c Employee.cpp
main: main.cpp
	g++ -c main.cpp
clean:
	rm program *.a *.o

