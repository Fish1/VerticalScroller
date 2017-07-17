install:
	g++ -c -g src/*.cpp
	g++ *.o -o app -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o
