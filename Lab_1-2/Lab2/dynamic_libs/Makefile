all: employee filedatabase main sharedlib exec

exec: UserInterface.o libsharedlib.so
	g++ -o binary UserInterface.o -L. -lsharedlib -Wl,--rpath,. 

sharedlib: FileDatabase.o Employee.o 
	g++ -shared -o libsharedlib.so FileDatabase.o Employee.o 

employee: Employee.cpp
	g++ -c -fpic Employee.cpp

filedatabase: FileDatabase.cpp
	g++ -c -fpic FileDatabase.cpp

main: UserInterface.cpp
	g++ -c -fpic UserInterface.cpp

clean:
	rm *.o *.so binary

