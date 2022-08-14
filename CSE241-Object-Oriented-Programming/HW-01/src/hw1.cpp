#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include "hw1.h"

using namespace std;

int main(){
    int run = 1, boardType, humanGame;
    while (run !=0 ){       /*Runs until finish one game.*/
        cout << "\n---------------------------------------------";
        cout << "\n\t\tPEG SOLITAIRE";
        cout << "\n---------------------------------------------";

        cout << "\n\nChoose the board type(from 1 to 6): ";
        cin >> boardType;
        if (boardType < 1 || boardType > 6) {
            run = 1;
            cout << "Please enter a number between 1-6 !" << endl;
            }
        else{
            cout << "Human game (1) or Computer game (0): " ;
            cin  >> humanGame;
            if (humanGame != 0 && humanGame != 1) {
                run = 1;
                cout << "Please enter 1 or 0 !! " << endl;
            }
            if (humanGame == 1){
                switch(boardType){
                    case 1:
                        move(map1());
                        break;
                    case 2:
                        move(map2());
                        break;
                    case 3:
                        move(map3());
                        break;
                    case 4:
                        move(map4());
                        break;
                    case 5:
                        move(map5());
                        break;
                    case 6:
                        move6(map6());
                        break;
                }
                run = 0;
            }
            else{ 
                switch(boardType){
                    case 1:
                        computerGame(map1());
                        break;
                    case 2:
                        computerGame(map2());
                        break;
                    case 3:
                        computerGame(map3());
                        break;
                    case 4:
                        computerGame(map4());
                        break;
                    case 5:
                        computerGame(map5());
                        break;
                    case 6:
                        computerGame6(map6());
                        break;
                }
                run = 0;
            }
            
        }
    }
    return 0;
}

void printmap(vector<vector<cell>> maps){   /*Function to print boards*/
    int control = 1,counter = 0;
    string label= "abcdefghij";
    cout << endl;
    for (int i=0; i < static_cast<int>(maps.size()); i++){
        if (counter != 0) cout << counter << " ";   /*Prints numbers in the map.*/
        counter++;
        if (i==0 && control == 1) {
            cout << "  ";
            for(int k=0 ; k< static_cast<int>(maps[i].size()); k++) cout << label[k] << " ";    /*Prints letters in the map.*/
            control = 0;
            i--;
        }
        else{
            for(int j=0; j < static_cast<int>(maps[i].size()); j++){    /*Prints pegs and empty areas, and prints out of the board*/
                switch(maps[i][j]){
                    case (out):
                        cout << " " ; 
                        break;
                    case (peg):
                        cout << "P";
                        break;
                    case(empty):
                        cout << ".";
                        break;
                }
                cout << " ";
                
            }
        }
        cout << endl;
        
    }
    
}

vector<vector<cell>> map1(){            
    vector<vector<cell>> mymap1{
        {out, out, peg, peg, peg, out, out},
        {out, peg, peg, peg, peg, peg, out},
        {peg, peg, peg, empty, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg},
        {out, peg, peg, peg, peg, peg, out},
        {out, out, peg, peg, peg, out, out}
    };
    return mymap1;
}
vector<vector<cell>> map2(){
    vector<vector<cell>> mymap2{
        {out, out, out, peg, peg, peg, out, out, out},
        {out, out, out, peg, peg, peg, out, out, out},
        {out, out, out, peg, peg, peg, out, out, out},
        {peg, peg, peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, peg, empty, peg, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg, peg, peg},
        {out, out, out, peg, peg, peg, out, out, out},
        {out, out, out, peg, peg, peg, out, out, out},
        {out, out, out, peg, peg, peg, out, out, out}
    };
    return mymap2;
}

vector<vector<cell>> map3(){
    vector<vector<cell>> mymap3{
        {out, out, peg, peg, peg, out, out, out},
        {out, out, peg, peg, peg, out, out, out},
        {out, out, peg, peg, peg, out, out, out},
        {peg, peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, empty, peg, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg, peg},
        {out, out, peg, peg, peg, out, out, out},
        {out, out, peg, peg, peg, out, out, out}
    };
    return mymap3;
}
vector<vector<cell>> map4(){
    
    vector<vector<cell>> mymap4{
        {out, out, peg, peg, peg, out, out},
        {out, out, peg, peg, peg, out, out},
        {peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, empty, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg},
        {out, out, peg, peg, peg, out, out},
        {out, out, peg, peg, peg, out, out}
    };
    return mymap4;
}

vector<vector<cell>> map5(){
    
    vector<vector<cell>> mymap5{
        {out, out, out, out, peg, out, out, out, out},
        {out, out, out, peg, peg, peg, out, out, out},
        {out, out, peg, peg, peg, peg, peg, out, out},
        {out, peg, peg, peg, peg, peg, peg, peg, out},
        {peg, peg, peg, peg, empty, peg, peg, peg, peg},
        {out, peg, peg, peg, peg, peg, peg, peg, out},
        {out, out, peg, peg, peg, peg, peg, out, out},
        {out, out, out, peg, peg, peg, out, out, out},
        {out, out, out, out, peg, out, out, out, out}
    };

    return mymap5;
}
vector<vector<cell>> map6(){
    vector<vector<cell>> mymap6{
        {out, out, out, out, empty, out, out, out, out},
        {out, out, out, peg, out, peg, out, out, out},
        {out, out, peg, out, peg, out, peg, out, out},
        {out, peg, out, peg, out, peg, out, peg, out},
        {peg, out, peg, out, peg, out, peg, out, peg}
    };
    return mymap6;
}

void move(vector<vector<cell>> board){      /*Function to play human game*/
    string userMove;
    int row, column, score;
    char direction;
    bool run = true;
    printmap(board);
    while(run){
        printInputMessage();
        cin >> userMove;
        processInput(userMove, &column, &row, &direction);
        if (checkInput(userMove) == false) cout << "\nInvalid Input!\n" << endl;
        else if(checkMove(row, column, direction, board) == false) cout << "\nInvalid Move!\n" << endl;
        else{    
            board [row][column] = empty;
            switch(direction){                      /*Movement according to direction.*/
                case 'R':
                    board [row][column+1] = empty;
                    board [row][column+2] = peg;
                    break;
                case 'L':
                    board [row][column-1] = empty;
                    board [row][column-2] = peg;
                    break;
                case 'U':
                    board [row-1][column] = empty;
                    board [row-2][column] = peg;
                    break;
                case 'D':
                    board [row+1][column] = empty;
                    board [row+2][column] = peg;
                    break;
                default:
                    board [row][column] = peg;
                    cout << "Wrong entry !" << endl;
                    break;    
            }
            printmap(board);
            cout << endl;
            if(endGame(board) == true){                              /*Finish game*/          
                score = finalScore(board);
                printFinalMessage(score);
                run = false;                                        /*Ends loop*/
            }
        }
    }
}

void move6 (vector<vector<cell>> board){        /*Function to play human game*/ 
    string userMove;                            /*Only for map 6*/
    int row, column, score;
    char direction;
    bool run = true;
    printmap(board);
    while(run){
        printInputMessage();        /*Takes a string from user*/
        cin >> userMove;
        processInput(userMove, &column, &row, &direction);
        if (checkInput(userMove) == false) cout << "\nInvalid Input!\n" << endl;
        else if(checkMove6(row, column, direction, board) == false) cout << "\nInvalid Move!\n" << endl;
        else{    
            board [row][column] = empty;
            switch(direction){                                  /*Movement according to direction.*/
                case 'R':
                    board [row][column+2] = empty;
                    board [row][column+4] = peg;
                    break;
                case 'L':
                    board [row][column-2] = empty;
                    board [row][column-4] = peg;
                    break;
                case 'U':
                    if(board[row-1][column+1] == peg && board[row-2][column+2] == empty){
                        board [row-1][column+1] = empty;
                        board [row-2][column+2] = peg;
                    }
                    else{
                        board [row-1][column+-1] = empty;
                        board [row-2][column-2] = peg;
                    }
                    break;
                case 'D':
                    if(board[row+1][column+1] == peg && board[row+2][column+2] == empty){
                        board [row+1][column+1] = empty;
                        board [row+2][column+2] = peg;
                    }
                    else{
                        board [row+1][column-1] = empty;
                        board [row+2][column-2] = peg;
                    }
                    break;
                default:
                    board [row][column] = peg;
                    cout << "Wrong entry !" << endl;
                    break;    
            }
            printmap(board);
            cout << endl;
            cout << endl;
            if(endGame6(board) == true){
                score = finalScore(board);
                printFinalMessage(score);
                run = false;
            }
        }
    }
}

bool checkInput(string inp){                                /*Function to check input if it is appropriate*/
    if (inp[1] > '0' && inp[1] < '9');
    else return false;
    if (inp[0] >= 'A' && inp[0]<= 'I');
    else return false;
    if (inp[3] == 'R' || inp[3] == 'L' || inp[3] == 'U' || inp[3] == 'D');
    else return false;
    return true;
}

bool checkMove(int cRow, int cColumn, char cDirection, vector<vector<cell>> cBoard){        /*Checks move if it is invalid or not.*/
    if (cRow > static_cast<int>(cBoard.size())-1 || cRow < 0) return false;
    if (cColumn > static_cast<int>(cBoard[0].size()) - 1 || cColumn < 0) return false;
    if (cBoard [cRow][cColumn] != peg) return false;
    switch (cDirection){
        case 'R':
            if (cColumn + 1 > static_cast<int>(cBoard[0].size()) - 1) return false;     /*Checks if it is inside the borders*/
            if (cColumn + 2 > static_cast<int>(cBoard[0].size()) - 1) return false;
            if (cBoard[cRow][cColumn + 1] != peg) return false;
            if (cBoard[cRow][cColumn + 2] != empty) return false;
            break;
        case 'L':
            if (cColumn -1 < 0) return false;
            if (cColumn -2 < 0) return false;
            if (cBoard[cRow][cColumn - 1] != peg) return false;
            if (cBoard[cRow][cColumn - 2] != empty) return false;
            break;
        case 'U':
            if (cRow -1 < 0 || cRow -2 < 0 ) return false;
            if (cBoard[cRow - 1][cColumn] != peg) return false;
            if (cBoard[cRow - 2][cColumn] != empty) return false;
            break;
        case 'D':
            if (cRow + 1 > static_cast<int>(cBoard.size()) - 1) return false;
            if (cRow + 2 > static_cast<int>(cBoard.size()) - 1) return false;
            if (cBoard[cRow + 1][cColumn] != peg) return false;
            if (cBoard[cRow + 2][cColumn] != empty) return false;
            break;
    }
    return true;
}

bool checkMove6(int cRow, int cColumn, char cDirection, vector<vector<cell>> cBoard){       /*Checks move if it is invalid or not.*/
    if (cRow > static_cast<int>(cBoard.size())-1 || cRow < 0) return false;                 /*Works only for map 6*/
    if (cColumn > static_cast<int>(cBoard[0].size()) - 1 || cColumn < 0) return false;
    if (cBoard [cRow][cColumn] != peg) return false;
    switch (cDirection){
        case 'R':
            if (cColumn + 2 > static_cast<int>(cBoard[0].size()) - 1) return false;
            if (cColumn + 4 > static_cast<int>(cBoard[0].size()) - 1) return false;
            if (cBoard[cRow][cColumn + 2] != peg) return false;
            if (cBoard[cRow][cColumn + 4] != empty) return false;
            break;
        case 'L':
            if (cColumn -2 < 0) return false;
            if (cColumn -4 < 0) return false;
            if (cBoard[cRow][cColumn - 2] != peg) return false;
            if (cBoard[cRow][cColumn - 4] != empty) return false;
            break;
        case 'U':
            if (cRow -2 < 0 ) return false;
            if (cColumn + 2 >= static_cast<int>(cBoard[0].size()) && cColumn - 2 < 0) return false;
            if ((cBoard[cRow - 1][cColumn+1] != peg || cBoard[cRow - 2][cColumn+2] != empty) && (cBoard[cRow - 1][cColumn-1] != peg || cBoard[cRow - 2][cColumn-2] != empty)) return false;
            break;
        case 'D':
            if (cRow + 2 >= static_cast<int>(cBoard.size())) return false;
            if (cColumn + 2 >= static_cast<int>(cBoard[0].size()) && cColumn - 2 < 0) return false;
            if ((cBoard[cRow + 1][cColumn+1] != peg || cBoard[cRow + 2][cColumn+2] != empty) && (cBoard[cRow + 1][cColumn-1] != peg || cBoard[cRow + 2][cColumn-2] != empty)) return false;
            break;
    }
    return true;
}

bool endGame(vector<vector<cell>> eBoard){                      /*Function to check if the game is over or not*/
    for(int i=0 ; i<static_cast<int>(eBoard.size()); i++){
        for(int j=0 ; j<static_cast<int>(eBoard[i].size()); j++){
            if(eBoard[i][j] == peg){
                if(j < static_cast<int>(eBoard[i].size()) -1  && eBoard[i][j+1] == peg && eBoard[i][j+2]== empty) return false;
                if(j > 1 && eBoard[i][j-1] == peg && eBoard[i][j-2] == empty) return false;
                if(i < static_cast<int>(eBoard.size())-2 && eBoard[i+1][j] == peg && eBoard[i+2][j] == empty) return false;
                if(i > 1 && eBoard[i-1][j] == peg && eBoard[i-2][j] == empty) return false;
            }
        }
    }
    return true;
}

bool endGame6(vector<vector<cell>> eBoard){                     /*Function to check if the game is over or not*/
    int a = 0, b = 0;
    for(int i=0 ; i<static_cast<int>(eBoard.size()); i++){      /*Works only for map 6*/
        for(int j=0 ; j<static_cast<int>(eBoard[i].size()); j++){
            if(eBoard[i][j] == peg){
                if(j < static_cast<int>(eBoard[i].size()) -4  && eBoard[i][j+2] == peg && eBoard[i][j+4]== empty) return false;
                if(j > 3 && eBoard[i][j-2] == peg && eBoard[i][j-4] == empty) return false;
                if(i < (static_cast<int>(eBoard.size())-2) 
                    && j+2 < static_cast<int>(eBoard[i].size())  
                    && eBoard[i+1][j+1] == peg
                    && eBoard[i+2][j+2] == empty) a = 1;
                if (i+2 <static_cast<int>(eBoard.size())
                    && j-2 >= 0
                    && eBoard[i+1][j-1] == peg
                    && eBoard[i+2][j-2] == empty) b = 1;
                if (a == 1 || b == 1) return false;
                if(i-2 > 0 
                    && j+2 < static_cast<int>(eBoard[i].size())  
                    && eBoard[i-1][j+1] == peg
                    && eBoard[i-2][j+2] == empty) a = 1;
                if (i-2 > 0
                    && j-2 >= 0
                    && eBoard[i-1][j-1] == peg
                    && eBoard[i-2][j-2] == empty) b = 1;
                if (a == 1 || b == 1) return false;
            }
        }
    }
    return true;
}

void computerGame(vector<vector<cell>> board){                      /*Function to make computer play the game*/
    int row, column, score;
    bool run = true;
    char direction;
    srand(time(NULL));                                              /*It changes random values for every run*/
    printmap(board);
    while(run){
        getRandomMove(&row, &column, &direction, board);
        if(checkMove(row, column, direction, board) == false) ;
        else{    
            board [row][column] = empty;
            switch(direction){
                case 'R':
                    board [row][column+1] = empty;
                    board [row][column+2] = peg;
                    break;
                case 'L':
                    board [row][column-1] = empty;
                    board [row][column-2] = peg;
                    break;
                case 'U':
                    board [row-1][column] = empty;
                    board [row-2][column] = peg;
                    break;
                case 'D':
                    board [row+1][column] = empty;
                    board [row+2][column] = peg;
                    break;
                default:
                    board [row][column] = peg;
                    cout << "Wrong entry !" << endl;
                    break;    
                }
            this_thread::sleep_for(std::chrono::milliseconds(500));         /*For delay*/
            printComputerMove(row, column, direction);
            printmap(board);
            cout << endl;

            if(endGame(board) == true){             /*Finish game*/
                score = finalScore(board);
                printFinalMessage(score);
                run = false;                                /*Ends the loop*/
            }
        }
    }
}

void computerGame6(vector<vector<cell>> board){                 /*Computer game for map6*/  
    int row, column, score;
    char direction;
    bool run = true;
    srand(time(NULL));
    printmap(board);
    while(run){
        getRandomMove(&row, &column, &direction, board);
        if(checkMove6(row, column, direction, board) == false) ;
        else{    
            board [row][column] = empty;
            switch(direction){
                case 'R':
                    board [row][column+2] = empty;
                    board [row][column+4] = peg;
                    break;
                case 'L':
                    board [row][column-2] = empty;
                    board [row][column-4] = peg;
                    break;
                case 'U':
                    board [row-1][column+1] = empty;
                    board [row-2][column+2] = peg;
                    break;
                case 'D':
                    board [row+1][column+1] = empty;
                    board [row+2][column+2] = peg;
                    break;
                default:
                    board [row][column] = peg;
                    cout << "Wrong entry !" << endl;
                    break;    
                }
            this_thread::sleep_for(std::chrono::milliseconds(500));
            printComputerMove(row, column, direction);
            printmap(board);
            cout << endl;

            if(endGame6(board) == true){
                score = finalScore(board);
                printFinalMessage(score);
                run = false;
            }
        }
    }
}

void getRandomMove(int *row, int *col, char *direc, vector<vector<cell>> board){
    *row = rand() % static_cast<int>(board.size());
    *col = rand() % static_cast<int>(board[0].size());
    int rDirec = rand() % 4;
    switch(rDirec){
        case 0 :
            *direc = 'R';
            break;
        case 1 :
            *direc = 'L';
            break;
        case 2 :
            *direc = 'U';
            break;
        case 3 :
            *direc = 'D';
            break;
    }
}

void processInput(string userMove,int *col, int *r, char* dir){
        *col = userMove[0] - 65;                  /*Takes the char and turns into a integer to fit in the map*/
        *r = userMove[1] - '1';                    
        *dir = userMove[3];
}

void printInputMessage(){
    cout << "\nPlease enter your move" << endl;         /*Takes a string from user*/
    cout << "---Correct input type: B4-R---\n";
    cout << "---Upper letters only---\n";
    cout << "---This moves the peg at B4 towards right to eliminate the peg at C4---\n";
    cout << "---Use L for left, R for right, U for up, and D for down.---\n"; 
    cout << "Your move: "; 
}

void printFinalMessage(int score){
    cout << "The game is over!" << endl;       
    cout << "\n****************************************";
    cout << "\n\tYour final score is "<< score << endl;
    cout << "****************************************\n";
    if (score == 1) cout << "1 is the best score ! " << endl << "Congratulations";
}


int finalScore(vector<vector<cell>> fBoard){                    /*Function to calculate final score*/
    int final = 0;                                              /*Calculates pegs in the board*/
    for(int i=0; i<static_cast<int>(fBoard.size()); i++){
        for(int j=0; j<static_cast<int>(fBoard[i].size()); j++){
            if (fBoard[i][j] == peg) final++;
        }
    }
    return final;
}

void printComputerMove(int row, int column, char direction){        /*It prints computer`s moves*/
    char c = column+65;
    int r = row+1;
    cout << c << r << '-' << direction << " played"<< endl;
}