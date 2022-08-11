target:	hw5

Klotski:	Klotski.h Klotski.cpp
	g++ -Wall -Wextra -c -std=c++11 Klotski.cpp 

EightPuzzle:	EightPuzzle.h EightPuzzle.cpp
	g++ -Wall -Wextra -c -std=c++11 EightPuzzle.cpp 

PegSolitaire:	PegSolitaire.h PegSolitaire.cpp
	g++ -Wall -Wextra -c -std=c++11 PegSolitaire.cpp 

BoardGame2D:  BoardGame2D.h BoardGame2D.cpp
	g++ -Wall -Wextra -pedantic -c -std=c++11 BoardGame2D.cpp

main:	Klotski.h EightPuzzle.h PegSolitaire.h BoardGame2D.h main.cpp
	g++ -Wall -Wextra -c -std=c++11 main.cpp

hw5:	main BoardGame2D PegSolitaire EightPuzzle Klotski
	g++ BoardGame2D.o main.cpp PegSolitaire.o EightPuzzle.o Klotski.o -o hw5

clean:
	rm hw5