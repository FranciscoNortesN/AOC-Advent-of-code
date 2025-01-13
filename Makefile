bin/1: problemas/1.cpp
	mkdir -p bin
	g++ -o bin/1 1.cpp
bin/5: problemas/5.cpp
	mkdir -p bin
	g++ -o bin/5 5.cpp
bin/9: problemas/9.cpp
	mkdir -p bin
	g++ -o bin/9 9.cpp
bin/11: problemas/11.cpp
	mkdir -p bin
	g++ -o bin/11 11.cpp
bin/16: problemas/16.cpp
	mkdir -p bin
	g++ -o bin/16 16.cpp
clean:
	rm -r *.o *.gch bin
