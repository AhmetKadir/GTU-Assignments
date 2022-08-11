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
		print();
		while(endGame() != true) {
			playAuto();
			/*this_thread::sleep_for(std::chrono::milliseconds(80));                    /*For delay */
			//print();
		}
		cout << "The game is over!" << endl;                
		score = boardScore();
		cout << "Your final score is "<< score << endl;
	} 
	ostream& operator <<(ostream& outs,
								const BoardGame2D& game)
	{
		game.print();
		return outs;
	}
}