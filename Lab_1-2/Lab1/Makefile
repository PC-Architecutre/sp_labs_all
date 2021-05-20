all: main employee
	g++ -o program main.o Employee.o
employee: Employee.cpp
	g++ -c Employee.cpp
main: main.cpp
	g++ -c main.cpp
clean:
	rm main.o Employee.o program

