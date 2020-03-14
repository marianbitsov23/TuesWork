main: employee.o manager.o
	g++ -o main main.cpp manager.o employee.o

manager.o: manager.cpp manager.h
	g++ -c manager.cpp

employee.o: employee.cpp employee.h
	g++ -c employee.cpp

clean:
	-rm *.o main