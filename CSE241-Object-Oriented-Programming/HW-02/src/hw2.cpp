#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>
#include "hw2.h"

using namespace std;

int main(){
    int humanGame = 1;
    bool run = true;
    string boardType, fileName;
    int board;
    while (run){                                                  /*Runs until finish the game.*/
        cout << "\nChoose the board type(from 1 to 6)";                 /*Gets boardtype from user*/
        cout << "\nIf you want to Load a board from files, just write #LOAD FILENAME.TXT#\n";
        cout << "\nTo save the file while playing, write #SAVE filename.txt#";
        cout << "\nYour input: ";
        cin >> boardType;
        if (boardType.compare("LOAD") == 0){                            /*LOAD Command*/
            cin >> fileName;
            loadBoard(fileName, humanGame);
            exit(0);
        }

        board = boardType[0] - '0';
        if (board <= 0 || board > 6 || (boardType.size()) > 1)
            cerr << "Please enter a number between 1-6 !" << endl;    
        else{
            cout << "boardType is " << boardType << "\n";
            cout << "Human game (1) or Computer game (0): " ;
            cin  >> humanGame;
            if (humanGame != 0 && humanGame != 1) {
                run = true;
                cerr << "Please enter 1 or 0 !! " << endl;
            }
            if (humanGame == 1){
                switch(board){
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
                run = false;
            }
            else{ 
                switch(board){
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
                run = false;
            }
        }
    }
    return 0;
}

void printmap(vector<vector<cell>> maps){                           /*Function to print boards*/
    int control = 1,counter = 0;
    string label= "abcdefghijklmnopqr";                             /*Saves letters inside a string*/
    cout << endl;
    for (auto i=0; i < static_cast<int>(maps.size()); i++){
        if (counter != 0) cout << counter << " ";                   /*Prints numbers in the map.*/
        counter++;
        if (i==0 && control == 1) {
            cout << "  ";
            for(int k=0 ; k< static_cast<int>(maps[i].size()); k++) cout << label[k] << " ";    /*Prints letters in the map.*/
                
            control = 0;
            i--;
        }
        else{
            for(decltype(i) j=0; j < static_cast<int>(maps[i].size()); j++){    /*Prints pegs and empty areas, and prints out of the board*/
                switch(maps[i][j]){
                    case (out):
                        cout << ' ' ; 
                        break;
                    case (peg):
                        cout << 'P';
                        break;
                    case(empty):
                        cout << '.';
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

void move(vector<vector<cell>> board, int numberOfMoves /*= 0*/){           /*Function to play human game, numberOfMoves default set to 0 */ 
    string userMove, fileName;                                          
    int row, column, running = 1, score, humanGame = 1, type6 = 0;
    char direction;
    printmap(board);
    while(running == 1){
        if(endGame(board) == true){                              /*Checks if the game is over*/          
            score = finalScore(board);
            printFinalMessage(score);
            running = 0;          
            exit(0);                                                    /*Terminates the program*/
        }
        cout << "Please enter your move: ";                             /*Takes a string from user*/
        cin >> userMove;
        if (userMove.compare("LOAD") == 0){                             /*LOAD command*/
            cin >> fileName;
            loadBoard(fileName, humanGame);
            exit(0);
        }
        if (userMove.compare("SAVE") == 0){                             /*SAVE command*/
            cin >> fileName;
            saveBoard(fileName, board, humanGame, numberOfMoves, type6);
            exit(0);
        }
        column = userMove[0] - 65;                                      /*Takes the char and turns into a integer to fit in the map*/
        row = userMove[1] - '1';                    
        direction = userMove[3];
        if (checkInput(userMove) == false) cerr << "Invalid Input!" << endl;                          
        else if(checkMove(row, column, direction, board) == false) cerr << "Invalid Move!" << endl;
        else{    
            board [row][column] = empty;
            switch(direction){                                          /*Movement according to direction.*/
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
            numberOfMoves+= 1;
            printmap(board);
            cout << endl;
        }
    }
}

void move6 (vector<vector<cell>> board, int numberOfMoves /* = 0*/){        /*Function to play human game,only for map6*/
    string userMove, fileName;                                              
    int row, column, running = 1, score, type6 = 1, humanGame = 1;
    char direction;
    printmap(board);
    while(running == 1){
        if(endGame6(board) == true){                                            /*Checks if the game is over or not.*/
            score = finalScore(board);
            printFinalMessage(score);
            running = 0;
            exit(0);                                                            /*Terminates the program*/
        }
        cout << "Please enter your move: ";                                     
        cin >> userMove;                                                        /*Takes a string from user*/
        if (userMove.compare("LOAD") == 0){                                     /*LOAD Command*/
            cin >> fileName;
            loadBoard(fileName, humanGame);
            exit(0);
        }
        if (userMove.compare("SAVE") == 0){                                     /*SAVE Command*/
            cin >> fileName;
            saveBoard(fileName, board, humanGame, numberOfMoves, type6);
            exit(0);
        }
        column = userMove[0] - 65;                                              /*Takes the char and turns into a integer to fit in the map*/
        row = userMove[1] - '1';
        direction = userMove[3];
        if (checkInput(userMove) == false) cerr << "Invalid Input!" << endl;
        else if(checkMove6(row, column, direction, board) == false) cerr << "Invalid Move!" << endl;
        else{    
            board [row][column] = empty;
            switch(direction){                                                  /*Movement according to direction.*/
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
            numberOfMoves+= 1;
            printmap(board);
            cout << endl;
        }
    }
}

bool checkInput(string inp){                                                        /*Function to check input if it is appropriate*/
    if (inp[1] > '0' && inp[1] <= '9');
    else return false;
    if (inp[0] >= 'A' && inp[0]<= 'P');
    else return false;
    if (inp[3] == 'R' || inp[3] == 'L' || inp[3] == 'U' || inp[3] == 'D');
    else return false;
    return true;
}

bool checkMove(int cRow, int cColumn, char cDirection, vector<vector<cell>> cBoard){        /*Checks move if it is invalid or not.*/
    if (cRow > static_cast<int>(cBoard.size())-1 || cRow < 0) return false;
    if (cColumn > static_cast<int>(cBoard[0].size()) - 1 || cColumn < 0) return false;
    if (cBoard [cRow][cColumn] != peg) return false;
    switch (cDirection){                                                                    /*Checks if it is inside the borders*/
        case 'R':
            if (cColumn + 1 > static_cast<int>(cBoard[0].size()) - 1) return false;     
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

bool endGame(vector<vector<cell>> eBoard){                                           /*Function to check if the game is over or not*/
    /*Checks every cell in the board.
    If the cell has peg on it, and there is a peg beside the cell and there is a empty cell beside it, movement is possible.
    So the game continues.
    If there is no cell satisfies this conditions, game is over.*/
    for(int i=0 ; i<static_cast<int>(eBoard.size()); i++){
        for(int j=0 ; j<static_cast<int>(eBoard[i].size()); j++){
            if(eBoard[i][j] == peg){
                if(j < static_cast<int>(eBoard[i].size()) -2  && eBoard[i][j+1] == peg && eBoard[i][j+2]== empty) return false;
                if(j > 1 && eBoard[i][j-1] == peg && eBoard[i][j-2] == empty) return false;
                if(i < static_cast<int>(eBoard.size())-2 && eBoard[i+1][j] == peg && eBoard[i+2][j] == empty) return false;
                if(i > 1 && eBoard[i-1][j] == peg && eBoard[i-2][j] == empty) return false;
            }
        }
    }
    return true;
}

bool endGame6(vector<vector<cell>> eBoard){                     /*Function to check if the game is over or not, works only for map 6*/
    int a = 0, b = 0;
    for(int i=0 ; i<static_cast<int>(eBoard.size()); i++){      
        for(int j=0 ; j<static_cast<int>(eBoard[i].size()); j++){
            if(eBoard[i][j] == peg){
                if(j < static_cast<int>(eBoard[i].size()) -4  && eBoard[i][j+2] == peg && eBoard[i][j+4]== empty) return false;
                if(j > 3 && eBoard[i][j-2] == peg && eBoard[i][j-4] == empty) return false;
                if((i < static_cast<int>(eBoard.size())-2) 
                    && (j+2 < static_cast<int>(eBoard[i].size()))  
                    && (eBoard[i+1][j+1] == peg)
                    && (eBoard[i+2][j+2] == empty)) a = 1;
                if ((i+2 <static_cast<int>(eBoard.size()))
                    && (j-2 >= 0)
                    && (eBoard[i+1][j-1] == peg)
                    && (eBoard[i+2][j-2] == empty)) b = 1;
                if (a == 1 || b == 1) return false;
                if((i-2 >= 0) 
                    && (j+2 < static_cast<int>(eBoard[i].size()))  
                    && (eBoard[i-1][j+1] == peg)
                    && (eBoard[i-2][j+2] == empty)) a = 1;
                if ((i-2 >= 0)
                    && (j-2 >= 0)
                    && (eBoard[i-1][j-1] == peg)
                    && (eBoard[i-2][j-2] == empty)) b = 1;
                if (a == 1 || b == 1) return false;
            }
        }
    }
    return true;
}

void computerGame(vector<vector<cell>> board, int numberOfMoves /*= 0*/){       /*Function to make computer play the game, numberOfMoves default set to 0*/
    int row, column, running = 1,rDirec, score, humanGame = 0, type6 = 0;
    string answer, fileName;
    char direction;
    srand(time(NULL));                                                          /*It changes random values for every run*/
    printmap(board);
    while(running == 1){
        if(endGame(board) == true){                                             /*Checks if the game is over or not*/
            score = finalScore(board);
            printFinalMessage(score);
            running = 0;
            cout << "You can save the game or end the game" << endl << "USE SAVE COMMAND OR TYPE SOMETHING TO EXIT" << endl;
            cin >> answer;
            if (answer.compare("SAVE") == 0){
                cin >> fileName;
                saveBoard(fileName, board, humanGame, numberOfMoves, type6);
                exit(0);
            }
            cout << "Terminating..." << endl;
            exit(0);
        }
        row = rand() % static_cast<int>(board.size());                      /*Generates random values and get a random move*/
        column = rand() % static_cast<int>(board[0].size());
        rDirec = rand() % 4;
        switch(rDirec){
            case 0 :
                direction = 'R';
                break;
            case 1 :
                direction = 'L';
                break;
            case 2 :
                direction = 'U';
                break;
            case 3 :
                direction = 'D';
                break;
        }
        /*After generating a random move, it checks if the move is valid or not.
        If move is not valid, generates a new move and tries again
        If move is valid, then makes the move.*/
        if(checkMove(row, column, direction, board) == true){           
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
                    break;    
                }
            this_thread::sleep_for(std::chrono::milliseconds(500));                     /*For delay (5 seconds)*/
            printComputerMove(row, column, direction);
            numberOfMoves+= 1;
            printmap(board);
            cout << endl;
        }
    }
}

void computerGame6(vector<vector<cell>> board,  int numberOfMoves /*=0*/){                 /*Computer game for map6*/ 
    int row, column, running = 1,rDirec, score, humanGame = 0, type6 = 1;
    string fileName, answer;
    char direction;
    srand(time(NULL));
    printmap(board);
    while(running == 1){
        if(endGame6(board) == true){
            score = finalScore(board);
            printFinalMessage(score);
            cout << "You can save the game or end the game" << endl << "USE SAVE COMMAND OR TYPE SOMETHING TO EXIT" << endl;
            cin >> answer;
            if (answer.compare("SAVE") == 0){
                cin >> fileName;
                saveBoard(fileName, board, humanGame, numberOfMoves, type6);
                exit(0);
            }
            cout << "Terminating..." << endl;
            exit(0);
        }
        row = rand() % static_cast<int>(board.size());
        column = rand() % static_cast<int>(board[0].size());
        rDirec = rand() % 4;
        switch(rDirec){
            case 0 :
                direction = 'R';
                break;
            case 1 :
                direction = 'L';
                break;
            case 2 :
                direction = 'U';
                break;
            case 3 :
                direction = 'D';
                break;
        }
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
            numberOfMoves+= 1;
            printmap(board);
            cout << endl;
        }
    }
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


void printFinalMessage(int score){
    cout << "The game is over!" << endl;       
    cout << "\n****************************************";
    cout << "\n\tYour final score is "<< score << endl;
    cout << "****************************************\n";
    if (score == 1) cout << "1 is the best score ! " << endl << "Congratulations";
}

void printComputerMove(int row, int column, char direction){        /*It prints computer`s moves*/
    char c = column+65;
    int r = row+1;
    cout << c << r << '-' << direction << " played"<< endl;
}

void loadBoard(string fileName, int& humanGame){
    ifstream myFile;
    vector<vector<cell>> newMap;
    string line;
    int i=0, j=0, a=0, numberOfMoves, type6, control =0, run = 1, fileControl = 1;
    while(run == 1){
        if (fileControl == 0){                                          /*If filename is not valid, or does not have the game, asks for it again.*/
            cout << "Enter the file name again: ";
            cin >> fileName;
        }
        cout << "File " << fileName << " is opening" << endl;
        fileName = "boardTxts/" + fileName;
        myFile.open(fileName);
        if(myFile.is_open()){
            while(getline(myFile, line)){
                if (line.compare("end") == 0){                        /*When it sees the word "end", it starts to take informations about the board and the game*/
                    getline(myFile, line);
                    if(line.compare("Human") == 0) humanGame = 1;
                    else humanGame= 0;
                    control = 1;
                    getline(myFile, line);
                    numberOfMoves = stoi(line);
                    getline(myFile, line);
                    if (line == "type6") type6=1;                       /*If the boardtype is type6 it sets the value 1*/
                    else type6 = 0;
                    
                }
                else {newMap.push_back(vector<cell>());                     /*It takes the board into a vector from txt file.*/
                    a = line.size();
                    for(j=0; j<a; j++){
                        switch (line[j]){
                            case 'P':
                                newMap[i].push_back(peg);
                                control = 1;
                                break;
                            case '-':
                                newMap[i].push_back(out);
                                break;
                            case '.':
                                newMap[i].push_back(empty);
                                break;
                        }
                    }
                }
                i++;
            }
            myFile.close();
        }
        else{
            cerr << "Could not open the file !" << endl;
            fileControl = 0;
        } 
        if (control == 1){                                                      /*Opens correct game function by using informations.*/
            if (humanGame == 1 && type6 == 0) move(newMap, numberOfMoves);
            else if (humanGame == 0 && type6 == 0) computerGame(newMap, numberOfMoves);
            else if (humanGame == 1 && type6 == 1) move6(newMap, numberOfMoves);
            else if (humanGame == 0 && type6 == 1) computerGame6(newMap, numberOfMoves);
            run = 0;
        }
        else {
            cerr << "Wrong file !" << endl;
            fileControl = 0;
        }
    }
    
    return;
}

void saveBoard(string fileName, vector<vector<cell>> board, const int& humanGame, const int& numberOfMoves, const int type6){
    /*Function to save a board into a txt file*/
    ofstream myFile;
    fileName = "boardTxts/" + fileName;
    myFile.open(fileName);
    if(myFile.is_open()){
        for(auto i=0; i<static_cast<int>(board.size()); i++){
            for(decltype (i) j=0; j<static_cast<int>(board[i].size()); j++){
                switch(board[i][j]){
                    case peg:
                        myFile << "P";
                        break; 
                    case empty:
                        myFile << ".";
                        break; 
                    case out:
                        myFile << "-";
                        break; 
                }
            }
        myFile << endl;
        }
        myFile << "end" << endl;
        if (humanGame == 1) myFile << "Human" << endl;
        else myFile << "Computer" << endl;
        myFile << numberOfMoves << endl;
        if (type6 == 1) myFile << "type6";
        else myFile << "type1";

        myFile.close();
        cout << endl << "Saved succesfully" << endl;
    }
    else {
        cerr << "\nCould not open the file !\n" ;
    }
}