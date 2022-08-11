#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "EightPuzzle.h"

using std::cout;
using std::cin;

namespace AkaGames{
    EightPuzzle::EightPuzzle():
    board({0}),zero_x (0), zero_y(0)
    {
        initialize();
    }
	
    void EightPuzzle::setZeroX(int a){
        zero_x = a;
    }

    void EightPuzzle::setZeroY(int a){
        zero_y = a;
    }

    void EightPuzzle::initialize(){
		int randnum, temp;
        do{
			vector<int> defaultBoard{1,2,3,4,5,6,7,8,0};
			board.clear();
			for(int i =0 ; i<8 ; i++){
				randnum = rand() % (9);
				temp = defaultBoard[randnum];
				defaultBoard[randnum] =defaultBoard[i];
				defaultBoard[i] = temp;
			}
			board.resize(3, vector<int>(3));
			int k=0;
        
				for (int i =0 ; i<3; i++){
				for (int j=0; j<3 ; j++){
					/*cerr << "Initialize error4" << endl;*/
					board[i][j] = defaultBoard[k];
					if(board[i][j] == 0) {
						zero_x = i;
						zero_y = j;
					} 
					k=k+1;
				}
			}
		}while(solvable() == false);
	}

	bool EightPuzzle::solvable(){
		int i, j, k ,m;
		int counter = 0;
		for (i = 0; i<3 ; i++)
			for (j = 0; j<3 ; j++){
				for (k = i; k<3 ; k++){
					if(k == i){
						for (m = j+1; m<3 ; m++){
							if (board[i][j] != 0 && board[k][m]!=0 &&  board [i][j] > board[k][m])
								counter++;
						}
					}
					else {
						for (m = 0; m<3 ; m++){
							if (board[i][j] != 0 && board[k][m]!=0 &&  board [i][j] > board[k][m])
								counter++;
						}
					}
				}
			}
		return (counter % 2 == 0);
	}

    void EightPuzzle::playUser(string userMove){
        /*Correct input format : "0-1"*/
        int move_x, move_y, direction;
        if (checkInput(userMove) == false) {
            cerr << "Invalid Input!" << endl;
            cout << "You should enter the coordinates" << endl;
            cout << "Correct input format is a-b (a and b is an integer number between 0-2)" << endl;
            cout << "For example : (2-1)" << endl;
            return;
        }  
		move_x = userMove[0] - '0';
        move_y = userMove[2] - '0';
        direction = findDirection(move_x, move_y);
        if (direction == 4){
            cerr << "Invalid Move" << endl;
            return;
        }              
        cout << direction << endl;
		switch(direction){
			case 0: /*LEFT*/
				if(move_y == 1){
					swap(board[move_x][move_y], board[move_x][0]);

				}
				else if(zero_y == 0){
					swap(board[move_x][move_y], board[move_x][0]);
					swap(board[move_x][0], board[move_x][1]);
				}
				else{
					swap(board[move_x][move_y], board[move_x][1]);
				}
				break;
			case 1: /*RIGHT*/
				if(move_y == 1){
					swap(board[move_x][move_y], board[move_x][2]);
				}
				else if(zero_y == 2){
					swap(board[move_x][move_y], board[move_x][2]);
					swap(board[move_x][2], board[move_x][1]);
				}
				else{/*zero_y == 1*/
					swap(board[move_x][move_y], board[move_x][1]);
				}
				break;
			case 2: /*UP*/
				if(move_x == 1){
					swap(board[move_x][move_y], board[0][move_y]);
				}
				else if(zero_x == 0){
					swap(board[move_x][move_y], board[0][move_y]);
					swap(board[0][move_y], board[1][move_y]);
				}
				else{
					swap(board[1][move_y],board[2][move_y]);
				}
				break;
			case 3: /*DOWN*/
				if(move_x == 1){
					swap(board[move_x][move_y], board[2][move_y]);
				}
				else if(zero_x == 2){
					swap(board[move_x][move_y], board[2][move_y]);
					swap(board[2][move_y], board[1][move_y]);
				}
				else{
					swap(board[0][move_y],board[1][move_y]);
				}
				break;
			default:
				cerr << "Something is wrong" << endl;
				break;
		}
		setZeroX(move_x);
		setZeroY(move_y);

    }

    void EightPuzzle::playAuto(){
        int move_x, move_y, direction, control =1;
        while(control == 1){
            move_x = rand() % 3;                      
            move_y = rand() % 3;
            direction = findDirection(move_x, move_y);
            if ((move_x == zero_x && move_y == zero_y) || direction == 4) control = 1;
            else control = 0;
        }

        cout << endl;
        cout << "coordinates are :" << move_x << " " << move_y << endl;
		cout << "direction value is " << direction << endl;
        switch(direction){
			case 0: /*LEFT*/
				if(move_y == 1){
					swap(board[move_x][move_y], board[move_x][0]);

				}
				else if(zero_y == 0){
					swap(board[move_x][move_y], board[move_x][0]);
					swap(board[move_x][0], board[move_x][1]);
				}
				else{
					swap(board[move_x][move_y], board[move_x][1]);
				}
				break;
			case 1: /*RIGHT*/
				if(move_y == 1){
					swap(board[move_x][move_y], board[move_x][2]);
				}
				else if(zero_y == 2){
					swap(board[move_x][move_y], board[move_x][2]);
					swap(board[move_x][2], board[move_x][1]);
				}
				else{/*zero_y == 1*/
					swap(board[move_x][move_y], board[move_x][1]);
				}
				break;
			case 2: /*UP*/
				if(move_x == 1){
					swap(board[move_x][move_y], board[0][move_y]);
				}
				else if(zero_x == 0){
					swap(board[move_x][move_y], board[0][move_y]);
					swap(board[0][move_y], board[1][move_y]);
				}
				else{
					swap(board[1][move_y],board[2][move_y]);
				}
				break;
			case 3: /*DOWN*/
				if(move_x == 1){
					swap(board[move_x][move_y], board[2][move_y]);
				}
				else if(zero_x == 2){
					swap(board[move_x][move_y], board[2][move_y]);
					swap(board[2][move_y], board[1][move_y]);
				}
				else{
					swap(board[0][move_y],board[1][move_y]);
				}
				break;
			default:
				cerr << "Something is wrong" << endl;
				break;
		}
		print();
		if(direction >= 0 && direction < 4){
            setZeroX(move_x);
		    setZeroY(move_y);
        }
    }
    
    void EightPuzzle::swap(int& val1, int& val2){
        int temp;
        temp = val1;
        val1 = val2;
        val2 = temp;
    }

    int EightPuzzle::findDirection(int move_x, int move_y){
        if (zero_y < move_y && zero_x == move_x)/*Left direction*/
            return 0;
        else if(zero_y > move_y && zero_x == move_x)/*Right direction*/
            return 1;
        else if(zero_x < move_x && zero_y == move_y)/*Up direction*/
            return 2;
        else if(zero_x > move_x && zero_y == move_y)/*Down direction*/
            return 3;
        else return 4;
    }

	bool EightPuzzle::checkInput(string inp){
		auto inputSize = inp.size();
		if((inputSize) != 3) return false;
		if ((inp[1]) != '-') return false;
		int move_x = inp[0] - '0';
        int move_y = inp[2] - '0';
		if(move_x > 2 || move_x < 0 || move_y < 0 || move_y > 2) return false;
		return true;
	}

	void EightPuzzle::print() const{
        int counter = 0;
    	cout << "\x1b[2J"; 
    	cout << "\033[0;0H";
		cout << endl;
        cout << "  \t0 1 2" << endl;
		cout << "  \t_____" << endl << endl;
        for(auto i=0; i<3 ;i++){
            cout << counter << "| \t";
            counter++;
            for(decltype(i) j=0; j<3; j++){
                if(board[i][j] != 0)cout << board[i][j];
                else cout << "*";
                cout << " ";
            }
            cout << endl;    
        }
    }

    bool EightPuzzle::endGame() const{
        int checkCell = 1;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j] != checkCell) return false;
                if (i == 2 && j == 2) return true;
                checkCell+= 1;
            }
        }
        return true;
    }

    int EightPuzzle::boardScore() const{
        if(endGame() == true) return 0;
        else return 1;
    }

	vector<vector<int>> EightPuzzle::getBoard() const{
        return board;
    }
    

}
