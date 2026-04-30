programım: main.o donusum.o analiz.o
	g++ main.o donusum.o analiz.o -o programım

main.o: main.cpp donusum.h analiz.h
	g++ -c main.cpp

donusum.o: donusum.cpp donusum.h
	g++ -c donusum.cpp

analiz.o: analiz.cpp analiz.h
	g++ -c analiz.cpp

clean:
	rm -f *.o programım