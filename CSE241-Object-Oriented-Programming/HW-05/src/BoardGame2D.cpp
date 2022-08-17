#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "BoardGame2D.h"

using std::cout;
using std::cin;

namespace AkaGames{
	void BoardGame2D::playUser () {
		string userMove;
		int score;
		print();
		printMovementRules();

		while(endGame() != true){
			cout << endl << "Please enter the movement: ";
			cin >> userMove;
			playUser(userMove);
			print();
		}
		cout << "The game is over!" << endl;                
		score = boardScore();
		cout << "Your final score is "<< score << endl;
	}

	void BoardGame2D::playAutoAll() {
		int score;
		int numberOfMoves = 0;
		bool gameContinuesMessage = false;

		print();
		while(endGame() != true) {
			if(playAuto()){
				numberOfMoves ++;
				this_thread::sleep_for(std::chrono::milliseconds(200));                    /*For delay */
				if(numberOfMoves < 100) print();

				if (numberOfMoves == 125)
					gameContinuesMessage = true;
					
				if(gameContinuesMessage){
					cout << "\n---The game is still going on, the results will be shared soon---\n";
					gameContinuesMessage = false;
				}
			}
		}
		print();
		cout << "\n\nThe game is over!" << endl;                
		score = boardScore();
		cout << "Your final score is "<< score << endl << endl;
	} 
	ostream& operator <<(ostream& outs,
								const BoardGame2D& game)
	{
		game.print();
		return outs;
	}
}