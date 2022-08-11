#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H
#include "BoardGame2D.h"

using namespace std;

namespace AkaGames{
class EightPuzzle : public BoardGame2D{
public:
	EightPuzzle();

	void setZeroX(int a);

	void setZeroY(int a);

	void initialize();

	bool solvable();

	using BoardGame2D::playUser;

	void playUser(string userMove);

	void playAuto();

	void swap(int& val1, int& val2);

	int findDirection(int move_x, int move_y);

	bool checkInput(string inp);

	bool checkMove(int move_x, int move_y);

	void print() const;

	bool endGame() const;

	int boardScore() const;

	vector<vector<int>> getBoard() const;
private:
	vector<vector<int>> board;
	int zero_x;
	int zero_y;
};


}
#endif