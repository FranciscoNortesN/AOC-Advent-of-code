bin/1: 1.cpp
	mkdir -p bin
	g++ -o bin/1 1.cpp
clean:
	rm -r *.o *.gch bin
