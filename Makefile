all: a
a:a.o
	g++ -g *.cpp -o a
a.o:a.cpp
	g++ -g -c *.cpp -o a.o
clean:
	rm -r *.o a