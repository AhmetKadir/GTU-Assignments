#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

#ifndef BoardGame2D_H
#define BoardGame2D_H

using namespace std;

namespace AkaGames{

class BoardGame2D{
public:
	BoardGame2D(){}

	virtual void playUser (string userMove) = 0;
	
	virtual void playUser () final;
	
	virtual void playAuto() = 0; /*Plays one move*/

	virtual void playAutoAll() final; 

	virtual void print() const = 0;

	friend ostream& operator <<(ostream& outs,
								const BoardGame2D& game);

	virtual bool endGame() const= 0;

	virtual int boardScore() const = 0;

	virtual void initialize() = 0;

	/*static playVector();*/

	virtual ~BoardGame2D() = default;

};
}
#endif