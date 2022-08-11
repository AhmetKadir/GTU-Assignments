#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
/*#define DEBUG*/

#include "Klotski.h"

using std::cout;
using std::cin;

namespace AkaGames{
	Klotski::Klotski():
	board({0})
	{
		initialize();
	}
	
	void Klotski::initialize(){
		vector<vector<int>> freshBoard{
		{1, 2, 2, 3},
		{1, 2, 2, 3},
		{4, 5, 5, 6},
		{4, 7, 8, 6},
		{9, 11, 11, 0}
		};
		board.clear();
		int xsize, ysize;
		
		xsize = freshBoard.size();
		ysize = freshBoard[0].size();
		for(auto i=0; i<xsize ; i++){
			board.push_back(vector<int>());
			for(decltype(i) j=0; j< ysize; j++){
				board[i].push_back(freshBoard[i][j]);
			}
		}
	}

	void Klotski::playUser(string userMove){
		/*Correct input format theNumberYouWanttoMove-Direction
		U-Up, D-Down, L-Left, R-Right 
		For example: 5-D
		Moves the block 5 to down if it is possible.*/
		int blockNumber, i, j;
        if (checkInput(userMove) == false) {
            cerr << "Invalid Input!" << endl;
            cout << "You should enter the coordinates" << endl;
            cout << "Correct input format is a-b (a is an integer number between 0-9, b is a letter to specify the direction.)" << endl;
            cout << "For example : (2-L)" << endl;
            return;
        }  
		blockNumber = userMove[0] - '0';
        if(checkMove(blockNumber, userMove[2]) == true){
			if(userMove[2] == 'L')
				for(i=0; i<5; i++)
					for(j=0; j<4; j++)
						if(board[i][j] == blockNumber)
							if(board[i][j-1] == 11)
								swap(board[i][j], board[i][j-1]);
			
			if(userMove[2] == 'R')
				for(i=4; i>=0; i--)
					for(j=3; j>=0; j--)
						if(board[i][j] == blockNumber)
							if(board[i][j+1] == 11)
								swap(board[i][j], board[i][j+1]);

			if(userMove[2] == 'U')
				for(i=0; i<5; i++)
					for(j=0; j<4; j++)
						if(board[i][j] == blockNumber)
							if(board[i-1][j] == 11)
								swap(board[i][j], board[i-1][j]);
			
			if(userMove[2] == 'D')
				for(i=4; i>=0; i--)
					for(j=3; j>=0; j--)
						if(board[i][j] == blockNumber)
							if(board[i+1][j] == 11)
								swap(board[i][j], board[i+1][j]);
		}
		else cout << "INVALID MOVE !!" << endl;
	}  
        
	void Klotski::playAuto(){
		int blockNumber,i ,j;
		char direction;
        
		blockNumber= rand() % 10;
        switch (rand() %4){
			case 0:
				direction = 'L';
				break;
			case 1:
				direction = 'R';
				break;
			case 2:
				direction = 'U';
				break;
			case 3:
				direction = 'D';
				break;
		}
		if(checkMove(blockNumber, direction) == true){
			cout << endl << "Direction is  "<< direction << endl;
			cout << endl << "Block is  "<< blockNumber << endl;
			if(direction == 'L')
				for(i=0; i<5; i++)
					for(j=0; j<4; j++)
						if(board[i][j] == blockNumber)
							if(board[i][j-1] == 11)
								swap(board[i][j], board[i][j-1]);
			
			if(direction == 'R')
				for(i=4; i>=0; i--)
					for(j=3; j>=0; j--)
						if(board[i][j] == blockNumber)
							if(board[i][j+1] == 11)
								swap(board[i][j], board[i][j+1]);

			if(direction == 'U')
				for(i=0; i<5; i++)
					for(j=0; j<4; j++)
						if(board[i][j] == blockNumber)
							if(board[i-1][j] == 11)
								swap(board[i][j], board[i-1][j]);
			
			if(direction == 'D')
				for(i=4; i>=0; i--)
					for(j=3; j>=0; j--)
						if(board[i][j] == blockNumber)
							if(board[i+1][j] == 11)
								swap(board[i][j], board[i+1][j]);
		print();
		}
	}

	bool Klotski::checkInput(string inp){
		int blockNumber;
		auto inputSize = inp.size();
		if((inputSize) != 3) return false;
		
		blockNumber = inp[0] - '0';
		if(blockNumber > 9 && blockNumber < 0) return false;
		if (inp[1] != '-') return false;
		if (inp[2] != 'L' && inp[2] != 'R' &&inp[2] != 'U' && inp[2] != 'D') return false;
		
		return true; 
	}

    bool Klotski::checkMove(int blockNumber, char direction){
		int i, j;
		if (direction == 'L'){
			for(int i=0; i<5; i++){
				for(int j =0; j<4; j++){
					if(board[i][j] == blockNumber){
						if(j == 0) return false;
						if(board[i][j-1] != blockNumber && board[i][j-1] != 11) return false;
						/*if(board[i][j-1] == 11)return true;*/
 					}
				}
			}
			/*return false;*/
		}
		if (direction == 'R'){
			for(i=4; i>=0; i--)
				for(j=3; j>=0; j--)
					if(board[i][j] == blockNumber){
						if(j >= 3) return false;
						if(board[i][j+1] != blockNumber && board[i][j+1] != 11) return false;
						/*if(board[i][j+1] == 11)return true;*/
 					}
			/*return false;*/
		}		
		if (direction == 'U'){
			for(int i=0; i<5; i++){
				for(int j =0; j<4; j++){
					if(board[i][j] == blockNumber){
						if(i == 0) return false;
						if(board[i-1][j] != blockNumber && board[i-1][j] != 11) return false;
						/*if(board[i-1][j] == 11)return true;*/
 					}
				}
			}
			/*return false;*/
		}
		if (direction == 'D'){
			for(i=4; i>=0; i--)
				for(j=3; j>=0; j--)
					if(board[i][j] == blockNumber){
						if(i >= 4) return false;
						if(board[i+1][j] != blockNumber && board[i+1][j] != 11) return false;
						/*if(board[i+1][j] == 11)return true;*/
					}
			/*return false;*/
		}
		return true;
	}

	void Klotski::swap(int& val1, int& val2){
        int temp;
        temp = val1;
        val1 = val2;
        val2 = temp;
    }

	void Klotski::print() const{
		int counter = 1;
		cout << "\x1b[2J"; 
    	cout << "\033[0;0H";
		cout << endl;
        cout << "  \ta b c d" << endl;
		cout << "  \t_______" << endl << endl;
		for (int i = 0; i<5 ; i++){
			cout << counter << "| \t";
            counter++;
			for(int j = 0; j<4 ; j++){
				if(board[i][j] == 11) cout << " ";
				else cout << board[i][j];
				cout << " ";
			}
			cout << endl;
		}
	}

	bool Klotski::endGame() const{
		if(board[3][1]== 11 && board[3][2] == 11 && board[4][1] ==  11 && board[4][2] == 11)
			return true;
		return false;
	}

	int Klotski::boardScore() const{
		if(endGame() == true) return 0;
        else return 1;
	}

}