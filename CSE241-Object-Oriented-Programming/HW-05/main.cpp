#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "BoardGame2D.h"
#include "PegSolitaire.h"
#include "EightPuzzle.h"
#include "Klotski.h"

using namespace std;
using namespace AkaGames;

int main(){
	srand(time(NULL));
	PegSolitaire pegGame1,pegGame2;
	EightPuzzle EPgame1, EPgame2;
	Klotski KlotskiGame1, KlotskiGame2;
	/*pegGame1.playUser();*/
	/*pegGame1.playAutoAll();
	EPgame1.playUser();
	EPgame2.playAutoAll();*/
	KlotskiGame1.playUser();
	KlotskiGame2.playAutoAll();
	
	

	return 0;
}