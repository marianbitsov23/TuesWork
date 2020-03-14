main: main.o client.o industrial_client.o normal_client.o
	g++ -o main main.o client.o industrial_client.o normal_client.o

main.o:
	g++ -c main.cpp

client.o: client.cpp client.h
	g++ -c client.cpp

industrial_client.o: industrial_client.cpp industrial_client.h
	g++ -c industrial_client.cpp

normal_client.o: normal_client.cpp normal_client.h
	g++ -c normal_client.cpp

clean:
	-rm *.o main
