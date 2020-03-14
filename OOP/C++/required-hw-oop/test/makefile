main: main.o clothing.o order.o provider.o stock.o store.o tech.o user.o
	g++ -o main main.o clothing.o order.o provider.o stock.o store.o tech.o user.o

main.o:
	g++ -c main.cpp

clothing.o: clothing.cpp clothing.h
	g++ -c clothing.cpp

order.o: order.cpp order.h
	g++ -c order.cpp

provider.o: provider.cpp provider.h
	g++ -c provider.cpp

stock.o: stock.cpp stock.h
	g++ -c stock.cpp

store.o: store.cpp store.h
	g++ -c store.cpp

tech.o: tech.cpp tech.h
	g++ -c tech.cpp

user.o: user.cpp user.h
	g++ -c user.cpp

clean:
	-rm *.o main