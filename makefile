main: main.cpp Button.cpp Menu.cpp Circle.cpp Square.cpp
	@g++ -std=c++17 main.cpp Button.cpp Menu.cpp Circle.cpp Square.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network	
	@./main

clear:
	@rm -f main test test1 test2 test3
