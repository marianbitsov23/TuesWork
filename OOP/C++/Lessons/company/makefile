company: company.o
	g++ -o company company.o
company.o: employee.o manager.o
	g++ -c company.cpp employee.o manager.o
manager.o: manager.h
	g++ -c manager.cpp
employee.o: employee.h
	g++ -c employee.h